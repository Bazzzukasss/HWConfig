#ifndef HWCONNECTION_H
#define HWCONNECTION_H

#include <QString>
#include <QDebug>
#include <QStringList>

#define CT_SEND_CMD     "send cmd"
#define CT_SEND_FILE    "send file"
#define CT_BATCH_CMD    "batch cmd"
enum CommandsListTypeEnum{CLT_FULL,CLT_NAME,CLT_DESCRIPTION,CLT_TYPE};
class HWCommand {
    public:
        HWCommand(){};
        HWCommand(bool _active,QString _name,QString _type,QString _description,QString _cmd)
        {
            setData(_active,_name,_type,_description,_cmd);
        }
        ~HWCommand(){};
        void setData(bool _active,QString _name,QString _type,QString _description,QString _cmd)
        {
            cmd=_cmd;
            active=_active;
            name=_name;
            type=_type;
            description=_description;
        }

        void clear(){ setData(0,"","","",""); }

        void setActive(bool _active){active=_active;}
        void setCmd(QString _cmd){cmd=_cmd;}
        void setName(QString _name){name=_name;}
        void setType(QString _type){type=_type;}
        void setDescription(QString _description){description=_description;}

        bool getActive(){return active;}
        const QString getName(){return name;}
        const QString getType(){return type;}
        const QString getCmd(){return cmd;}
        const QString getDescription(){return description;}
        const QString getInfo(){return QString("Command:["+name+"] ["+description+"] ["+type+"]");}
        void show()
        {
            qDebug()<<"\t\tCommand:["<<name<<" "<<description<<" "<<type<<" "<<active<<" "<<cmd<<"]";
        }
    private:
        bool active;
        QString name;
        QString type;
        QString description;
        QString cmd;
};
class HWSession {
    public:
        HWSession(){};
        HWSession(QString _name,QString _user,QString _password,QString _host,QString _port,QString _protocol)
        {
            setData(_name,_user,_password,_host,_port,_protocol);
        }
        ~HWSession(){};
        void setData(QString _name,QString _user,QString _password,QString _host,QString _port,QString _protocol)
        {
            name=_name;
            user=_user;
            password=_password;
            host=_host;
            port=_port;
            protocol=_protocol;
        }
        void clear(){ setData("","","","","",""); }

        void setUser(QString _user){user=_user;}
        void setName(QString _name){name=_name;}
        void setPassword(QString _password){password=_password;}
        void setHost(QString _host){host=_host;}
        void setPort(QString _port){port=_port;}
        void setProtocol(QString _protocol){protocol=_protocol;}

        QString getDescription(){return user+"@"+host+" #"+port+" "+protocol;}
        QString getName(){return name;}
        QString getUser(){return user;}
        QString getPassword(){return password;}
        QString getHost(){return host;}
        QString getPort(){return port;}
        QString getProtocol(){return protocol;}
        QString getUserHost(){return user+"@"+host;}

        void show()
        {
            qDebug()<<"\tSession:["<<name<<" "<<user<<" "<<password<<" "<<host<<" "<<port<<" "<<protocol<<"]";
        }

    private:
        QString name;
        QString user;
        QString password;
        QString host;
        QString port;
        QString protocol;

};
class HWConnection
{
    public:
        HWConnection(){};
        ~HWConnection(){};
        void clear()
        {
            commands.clear();
            commandsList.clear();
            session.clear();
            activeCommandsIndexes.clear();
            cmd_index=0;
        }

        void addCmd(HWCommand _cmd)
        {
            commands.append(_cmd);
            if(_cmd.getActive())
                activeCommandsIndexes.append(cmd_index);
            cmd_index++;
        }
        void setName(QString _name){name=_name;}
        void setActive(bool _active){active=_active;}
        void setSession(HWSession _session){session=_session;}
        bool getActive(){return active;}
        HWSession getSession(){return session;}
        QString getName(){return name;}

        HWCommand* getCMD(int _index)
        {
            if(_index<commands.count())
                return &commands[_index];
            else
                return 0;
        }
        int getActiveCMDIndex(int _index)
        {
            if(_index<activeCommandsIndexes.count())
                return activeCommandsIndexes.at(_index);
            else
                return -1;
        }
        HWCommand* getCMD(QString &_cmd_name)
        {
            HWCommand cmd;
            int index=0;
            if(commands.count()>0)
            {
                foreach (cmd, commands) {
                    if(cmd.getName()==_cmd_name)
                        return &commands[index];
                    index++;
                }
                return 0;
            }
            else
                return 0;
        }
        int getCMDIndex(QString &_cmd_name)
        {
            HWCommand cmd;
            int index=0;
            if(commands.count()>0)
            {
                foreach (cmd, commands) {
                    if(cmd.getName()==_cmd_name)
                        return index;
                    index++;
                }
                return -1;
            }
            else
                return -1;
        }
        const QStringList getCommandsList()
        {
            HWCommand cmd;
            commandsList.clear();
            foreach (cmd, commands)
                commandsList.append(cmd.getName()+"\n   ["+cmd.getDescription()+"]\n");
            return commandsList;
        }
        const QStringList getActiveCommandsList(CommandsListTypeEnum type)
        {
            HWCommand cmd;
            activeCommandsList.clear();
            foreach (cmd, commands)
                if(cmd.getActive())
                {
                    if(type==CLT_FULL)
                        activeCommandsList.append(cmd.getName()+"\n   ["+cmd.getDescription()+"]\n");
                    if(type==CLT_NAME)
                        activeCommandsList.append(cmd.getName());
                    if(type==CLT_DESCRIPTION)
                        activeCommandsList.append(cmd.getDescription());
                    if(type==CLT_TYPE)
                        activeCommandsList.append(cmd.getType());
                }
            return activeCommandsList;
        }
        const QVector<int> getActiveCommandsIndexes()
        {
            return activeCommandsIndexes;
        }

        void show()
        {
            HWCommand cmd;
            qDebug()<<"Connection:["<<name<<" "<<active<<"]";
            session.show();
            foreach (cmd, commands)
                cmd.show();
        }

    private:
        int                 cmd_index;
        QString             name;
        bool                active;
        HWSession           session;
        QVector<HWCommand>  commands;
        QVector<int>        activeCommandsIndexes;
        QStringList         commandsList;
        QStringList         activeCommandsList;

};

#endif // HWCONNECTION_H
