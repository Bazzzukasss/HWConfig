#ifndef HWSESSION_H
#define HWSESSION_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include "HWShell.h"

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
        QString getName(){return name;}
        QString getType(){return type;}
        QString getCmd(){return cmd;}
        QString getDescription(){return description;}
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
            session.clear();
        }

        void addCmd(HWCommand _cmd)
        {
            commands.append(_cmd);
        }
        void setName(QString _name)
        {
            name=_name;
        }
        void setActive(bool _active)
        {
            active=_active;
        }
        void setActive(QString _active)
        {
            active=_active.toInt();
        }
        void setSession(HWSession _session)
        {
            session=_session;
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
        QString name;
        bool active;
        HWSession session;
        QVector<HWCommand> commands;

};
class HWManager{
public:
    HWManager(QString _conf_file_name)
    {

    }
    ~HWManager();
    bool loadConfig(QString _filename);
    void showConnections();
private:

    HWShell* shell;
    QVector<HWConnection> connections;
    void parseXMLConfig(QFile* _pFile);
    void parseXMLTeg_connection(QXmlStreamReader &_xml,HWConnection &_connection);
    void parseXMLTeg_session(QXmlStreamReader &_xml,HWSession &_session);
    void parseXMLTeg_command(QXmlStreamReader &_xml,HWCommand &_cmd);
};

#endif // HWSESSION_H
