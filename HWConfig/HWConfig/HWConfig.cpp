#include "HWConfig.h"
HWConfig::HWConfig(QString _conf_file_name)
{
    load(_conf_file_name);
    shell=new HWShell(curConnection->getSession());
}
HWConfig::~HWConfig()
{
    delete shell;
}
void HWConfig::executeCMD(int _index)
{
    HWCommand* pCmd;
    int index;
    if(_index<0)
    {
        qDebug()<<"cmd index <0!!!"<<endl;
        return;
    }
    if(curConnection)
    {
        pCmd=curConnection->getCMD(_index);

        if(pCmd->getType()!=CT_BATCH_CMD)
            shell->executeCmd(*pCmd);
        else
        {
            QStringList args=pCmd->getCmd().split(" ");
            for(int i=0;i<args.count();i++)
            {
                index=curConnection->getCMDIndex(args[i]);
                if(index>=0)
                    executeCMD(index);
            }
        }
    }
}

void HWConfig::parseXMLTeg_command(QXmlStreamReader &_xml,HWCommand &_cmd)
{
    QXmlStreamAttributes attributes;
    attributes = _xml.attributes();
    if(attributes.hasAttribute("name"))
        _cmd.setName(attributes.value("name").toString());
    else
        _cmd.setName("noname");

    if(attributes.hasAttribute("type"))
        _cmd.setType(attributes.value("type").toString());
    else
        _cmd.setType("notype");

    if(attributes.hasAttribute("description"))
        _cmd.setDescription(attributes.value("description").toString());
    else
        _cmd.setDescription("nodescription");

    if(attributes.hasAttribute("active"))
        _cmd.setActive(attributes.value("active").toInt());
    else
        _cmd.setActive("noactive");
    _xml.readNext();
    _cmd.setCmd(_xml.text().toString());

}
void HWConfig::parseXMLTeg_connection(QXmlStreamReader &_xml,HWConnection &_connection)
{
    QXmlStreamAttributes attributes;
    HWSession       session;
    HWCommand       cmd;
    attributes = _xml.attributes();
    _connection.clear();
    if(attributes.hasAttribute("name"))
        _connection.setName(attributes.value("name").toString());
    else
        _connection.setName("noname");

    if(attributes.hasAttribute("active"))
        _connection.setActive(attributes.value("active").toInt());
    else
        _connection.setActive(false);

    while (!(_xml.tokenType() == QXmlStreamReader::EndElement && _xml.name() == "connection"))
    {
        _xml.readNext();
        //qDebug()<<"\tC"<<_xml.tokenType()<<_xml.name()<<_xml.text();
        if (_xml.tokenType() == QXmlStreamReader::StartElement)
        {
            if(_xml.name() == "session")
            {
                parseXMLTeg_session(_xml,session);
                _connection.setSession(session);
            }
            if(_xml.name() == "command")
            {
                parseXMLTeg_command(_xml,cmd);
                _connection.addCmd(cmd);
            }
        }
    }
}
void HWConfig::parseXMLTeg_session(QXmlStreamReader &_xml,HWSession &_session)
{
    QXmlStreamAttributes attributes;
    attributes = _xml.attributes();
    if(attributes.hasAttribute("user"))
        _session.setUser(attributes.value("user").toString());
    else
        _session.setUser("nouser");

    if(attributes.hasAttribute("port"))
        _session.setPort(attributes.value("port").toString());
    else
        _session.setPort("noport");

    if(attributes.hasAttribute("host"))
        _session.setHost(attributes.value("host").toString());
    else
        _session.setHost("nohost");

    if(attributes.hasAttribute("password"))
        _session.setPassword(attributes.value("password").toString());
    else
        _session.setPassword("nopassword");

    if(attributes.hasAttribute("protocol"))
        _session.setProtocol(attributes.value("protocol").toString());
    else
        _session.setProtocol("noprotocol");
    _xml.readNext();
    _session.setName(_xml.text().toString());
}

void HWConfig::parseXMLConfig(QFile* _pFile)
{
    HWConnection    connection;
    QXmlStreamReader xml(_pFile);

    connections.clear();
    connectionsList.clear();
    while (!xml.atEnd() && !xml.hasError())
    {
       xml.readNext();
       //qDebug()<<xml.tokenType()<<xml.name();

       if (xml.tokenType() == QXmlStreamReader::StartElement)
       {
           if (xml.name() == "connections")
               continue;

           if (xml.name() == "connection")
           {
               parseXMLTeg_connection(xml,connection);
               if(connection.getActive())
               {
                   connections.append(connection);
                   connectionsList.append(connection.getName());
               }
           }
       }
    }
}

bool HWConfig::load(QString _filename)
{
    QFile file;
    file.setFileName(_filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    curConfigFile=_filename;
    parseXMLConfig(&file);
    file.close();
    setCurConnection(0);
    showConnections();
    return true;
}
void HWConfig::showConnections()
{
    HWConnection connection;
    qDebug()<<"CONNECTIONS:";
    foreach (connection, connections)
        connection.show();
}
