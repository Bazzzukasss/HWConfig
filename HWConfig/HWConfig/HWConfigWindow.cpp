#include "HWConfigWindow.h"
#include "ui_hwconfigwindow.h"

HWConfigWindow::HWConfigWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HWConfigWindow)
{
    ui->setupUi(this);
    config=new HWConfig( QCoreApplication::applicationDirPath() + "/connections.xml");
    ui->comboBox_CONNECTIONS->clear();
    ui->comboBox_CONNECTIONS->addItems(config->getConnectionsList());
    showCurConnection();
    connect(this,SIGNAL(cmdSended()),this,SLOT(on_cmdSended()));
    connect(config->getShell(),SIGNAL(configCmdSended()),this,SLOT(on_cmdSended()));
    progressValue=0;
    maxProgressValue=0;
    progressDialog= new QProgressDialog("Proсessing the data...", 0, 0, maxProgressValue);
    progressDialog->setModal(Qt::WindowModal);
    progressDialog->setMinimumDuration(0);
    progressDialog->setWindowTitle("Please Wait");
    progressDialog->setValue(maxProgressValue);

}

HWConfigWindow::~HWConfigWindow()
{
    delete ui;
    delete config;
}

void HWConfigWindow::on_lineEdit_CMD_returnPressed()
{
    QString cmd=ui->lineEdit_CMD->text();
    ui->textEdit_TERMINAL->clear();
    config->getShell()->setCmdInfo(cmd);
    config->getShell()->sendCmd(cmd);
}

void HWConfigWindow::showCurConnection()
{
    showSession();
    showCommands();
}

void HWConfigWindow::showCommands()
{
    createCMDButtons();
}

void HWConfigWindow::showSession()
{
    ui->label_SESSION->setText("<b>"+config->getSessionName()+"</b>\n\t["+config->getSessionDescription()+"]");
}
void HWConfigWindow::createCMDButtons()
{
    QFont font;
    //clearing buttons
    if(!buttons.isEmpty())
    {
        foreach(QPushButton* pButton,buttons)
        {
            ui->frame_CONNECTIONS->layout()->removeWidget(pButton);
            delete pButton;
        }
        buttons.clear();
    }
    QStringList list=config->getCommandsList();
    QStringList nameList=config->getCommandsNameList();
    QStringList descList=config->getCommandsDescriptionList();
    QStringList typeList=config->getCommandsTypeList();

    //adding buttons
    for(int i=0;i<list.size();i++)
    {
        QPushButton* pButton= new QPushButton(this);
        pButton->setText(nameList[i]);
        pButton->setToolTip(descList[i]);
        pButton->setIcon(QIcon(":/images/images/"+typeList[i]+".png"));
        pButton->setIconSize(QSize(24,24));
        font.setBold(true);
        pButton->setFont(font);
        buttons.push_back(pButton);
        ui->verticalLayout_COMMANDS->addWidget(pButton);
        connect(pButton,SIGNAL(clicked()),this,SLOT(on_cmd_BUTTONS_clicked()));
    }
}
void HWConfigWindow::on_comboBox_CONNECTIONS_currentIndexChanged(int index)
{
    config->setCurConnection(index);
    showCurConnection();    
}


void HWConfigWindow::on_cmdSended()
{
    progressDialog->setValue(++progressValue);
    qApp->processEvents();
    ui->textEdit_TERMINAL->insertPlainText(config->getShell()->getCmdInfo());
    ui->textEdit_TERMINAL->insertPlainText(config->getShell()->getPromtLine());
    ui->textEdit_TERMINAL->insertPlainText(config->getShell()->getResult());
    ui->textEdit_TERMINAL->insertPlainText("\n");
    qApp->processEvents();
}

void HWConfigWindow::on_cmd_BUTTONS_clicked()
{
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());
    if (!pButton)
        return;
    executeCMD(buttons.indexOf(pButton));
}

void HWConfigWindow::executeCMD(int cmd_index)
{
    progressValue=0;
    progressDialog->setValue(progressValue);
    qApp->processEvents();

    qDebug()<<"CMD index: "<<cmd_index;
    ui->textEdit_TERMINAL->clear();
    config->executeActiveCMD(cmd_index);

    progressDialog->setValue(maxProgressValue);

}


