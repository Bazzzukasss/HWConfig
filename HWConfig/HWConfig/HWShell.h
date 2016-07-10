#ifndef HWSHELL_H
#define HWSHELL_H

#include <QProcess>
#include "HWConnection.h"

class HWShell: public QObject{
    Q_OBJECT
    public:
        HWShell(const HWSession &_session,const QString &_ssh_client="plink", const QString &_scp_client="pscp")
        {
            ssh_client=_ssh_client;
            scp_client=_scp_client;
            curSession=_session;
        }
        ~HWShell(){};
        void setCurSession(const HWSession &_session)
        {
            curSession=_session;
        }
        void executeCmd(HWCommand &_cmd)
        {
            setCmdInfo(_cmd);
            if(_cmd.getType()==CT_SEND_CMD)
                sendCmd(_cmd.getCmd());
            if(_cmd.getType()==CT_SEND_FILE)
                sendFile(_cmd.getCmd());
            _cmd.show();

        }

        void sendCmd(const QString &_cmd)
        {
            sendCmd(_cmd,curSession);
            setPromtLine(_cmd);
            emit configCmdSended();
        }
        void sendFile(const QString &_cmd)
        {
            QStringList args=_cmd.split(" ");
            if(args.count()>1)
            {
                sendFile(args[0],args[1],curSession);
                setPromtLine(_cmd);
                emit configCmdSended();
            }
        }

        QString getResult(){return  process.readAllStandardOutput();}
        const QString& getPromtLine(){return promtLine;}
        const QString& getCmdInfo(){return cmdInfo;}
        void setCmdInfo(QString &_cmd)
        {
            cmdInfo="Command:["+_cmd+"]\n";
        }

    signals:
        void configCmdSended();

    private:
        QString promtLine;
        QString cmdInfo;
        QString ssh_client;
        QString scp_client;
        HWSession curSession;
        QProcess process;
        QStringList getArgumentsList(HWSession &_session,const QString &_cmd)
        {
            QStringList line;
            line<<"-"+_session.getProtocol()<<"-P"<<_session.getPort()<<"-pw"<<_session.getPassword()<<_session.getUserHost()<<_cmd;

            return line;
        }
        QStringList getArgumentsList(HWSession &_session,const QString &_src,const QString _dst)
        {
            QStringList line;
            line<<"-P"<<_session.getPort()<<"-pw"<<_session.getPassword()<<_src<<_session.getUserHost()+":"+_dst;
            return line;
        }
        int sendProc(const QString &_client,QStringList _args)
        {
            //qDebug()<<_client<<_args;
            process.start(_client,_args);
            process.waitForFinished(1000);
            process.waitForReadyRead(1000);
            return process.exitCode();

        }
        void sendFile(const QString &_src,const QString _dst)
        {
            sendFile(_src,_dst,curSession);
        }
        void sendCmd(const QString &_cmd,HWSession &_session)
        {
            sendProc(ssh_client,getArgumentsList(_session,_cmd));
        }
        void sendFile(const QString &_src,const QString _dst,HWSession &_session)
        {
            sendProc(scp_client,getArgumentsList(_session,_src,_dst));
        }
        void setCmdInfo(HWCommand &_cmd)
        {
            cmdInfo=_cmd.getInfo()+"\n";
        }

        void setPromtLine(const QString &_cmd)
        {
            promtLine="#"+curSession.getUserHost()+" > "+_cmd+"\n";
        }

};

#endif // HWSHELL_H
