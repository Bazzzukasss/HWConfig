#ifndef HWSESSION_H
#define HWSESSION_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>
#include <QStringList>
#include "HWShell.h"
#include <QObject>

class HWConfig {
public:
    HWConfig(QString _conf_file_name);
    ~HWConfig();
    bool load(QString _filename);
    void setCurConnection(int _index)
    {
        if(_index<connections.count())
        {
            curConnection=&connections[_index];
        }
        else
            curConnection=0;
    }
    const QStringList& getConnectionsList(){return connectionsList;}
    const QStringList getCommandsList()
    {
        if(curConnection)
            return curConnection->getActiveCommandsList(CLT_FULL);
        else
            return QStringList();
    }
    const QStringList getCommandsTypeList()
    {
        if(curConnection)
            return curConnection->getActiveCommandsList(CLT_TYPE);
        else
            return QStringList();
    }
    const QStringList getCommandsNameList()
    {
        if(curConnection)
            return curConnection->getActiveCommandsList(CLT_NAME);
        else
            return QStringList();
    }
    const QStringList getCommandsDescriptionList()
    {
        if(curConnection)
            return curConnection->getActiveCommandsList(CLT_DESCRIPTION);
        else
            return QStringList();
    }

    const QString getSessionName()
    {
        if(curConnection)
            return curConnection->getSession().getName();
        else
            return QString();
    }
    const QString getSessionDescription()
    {
        if(curConnection)
            return curConnection->getSession().getDescription();
        else
            return QString();
    }
    void executeCMD(int _index);
    void executeActiveCMD(int _index)
    {
        executeCMD(curConnection->getActiveCMDIndex(_index));
    }

    HWShell* getShell(){return shell;}

private:

    QString curConfigFile;
    QStringList connectionsList;
    QStringList commandsListToShow;
    QVector<int> commandIndex;
    HWShell* shell;
    HWConnection* curConnection;
    QVector<HWConnection> connections;
    void showConnections();
    void parseXMLConfig(QFile* _pFile);
    void parseXMLTeg_connection(QXmlStreamReader &_xml,HWConnection &_connection);
    void parseXMLTeg_session(QXmlStreamReader &_xml,HWSession &_session);
    void parseXMLTeg_command(QXmlStreamReader &_xml,HWCommand &_cmd);
};

#endif // HWSESSION_H
