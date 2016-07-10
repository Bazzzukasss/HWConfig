/********************************************************************************
** Form generated from reading UI file 'hwconfigwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HWCONFIGWINDOW_H
#define UI_HWCONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HWConfigWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_TERMINAL;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_TERMINAL;
    QLineEdit *lineEdit_CMD;
    QFrame *frame_CONNECTIONS;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox_CONNECTIONS;
    QLabel *label_SESSION;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_COMMANDS;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HWConfigWindow)
    {
        if (HWConfigWindow->objectName().isEmpty())
            HWConfigWindow->setObjectName(QStringLiteral("HWConfigWindow"));
        HWConfigWindow->resize(933, 463);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        HWConfigWindow->setWindowIcon(icon);
        HWConfigWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(HWConfigWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_TERMINAL = new QFrame(centralWidget);
        frame_TERMINAL->setObjectName(QStringLiteral("frame_TERMINAL"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_TERMINAL->sizePolicy().hasHeightForWidth());
        frame_TERMINAL->setSizePolicy(sizePolicy);
        frame_TERMINAL->setFrameShape(QFrame::Box);
        frame_TERMINAL->setFrameShadow(QFrame::Sunken);
        frame_TERMINAL->setLineWidth(1);
        verticalLayout = new QVBoxLayout(frame_TERMINAL);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        textEdit_TERMINAL = new QTextEdit(frame_TERMINAL);
        textEdit_TERMINAL->setObjectName(QStringLiteral("textEdit_TERMINAL"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(252, 255, 222, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(106, 104, 100, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(212, 208, 200, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        textEdit_TERMINAL->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        textEdit_TERMINAL->setFont(font);
        textEdit_TERMINAL->setStyleSheet(QStringLiteral(""));
        textEdit_TERMINAL->setFrameShape(QFrame::NoFrame);
        textEdit_TERMINAL->setFrameShadow(QFrame::Plain);
        textEdit_TERMINAL->setReadOnly(true);

        verticalLayout->addWidget(textEdit_TERMINAL);

        lineEdit_CMD = new QLineEdit(frame_TERMINAL);
        lineEdit_CMD->setObjectName(QStringLiteral("lineEdit_CMD"));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_CMD->setFont(font1);
        lineEdit_CMD->setStyleSheet(QStringLiteral(""));
        lineEdit_CMD->setFrame(false);

        verticalLayout->addWidget(lineEdit_CMD);


        horizontalLayout->addWidget(frame_TERMINAL);

        frame_CONNECTIONS = new QFrame(centralWidget);
        frame_CONNECTIONS->setObjectName(QStringLiteral("frame_CONNECTIONS"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_CONNECTIONS->sizePolicy().hasHeightForWidth());
        frame_CONNECTIONS->setSizePolicy(sizePolicy1);
        frame_CONNECTIONS->setStyleSheet(QLatin1String("QFrame#frame_CONNECTIONS,QPushButton\n"
"{\n"
"	background-image: url(:/images/images/mramor4.png);\n"
"}"));
        frame_CONNECTIONS->setFrameShape(QFrame::Box);
        frame_CONNECTIONS->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame_CONNECTIONS);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        comboBox_CONNECTIONS = new QComboBox(frame_CONNECTIONS);
        comboBox_CONNECTIONS->setObjectName(QStringLiteral("comboBox_CONNECTIONS"));
        QFont font2;
        font2.setPointSize(10);
        comboBox_CONNECTIONS->setFont(font2);
        comboBox_CONNECTIONS->setFrame(false);

        gridLayout->addWidget(comboBox_CONNECTIONS, 0, 1, 1, 1);

        label_SESSION = new QLabel(frame_CONNECTIONS);
        label_SESSION->setObjectName(QStringLiteral("label_SESSION"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_SESSION->sizePolicy().hasHeightForWidth());
        label_SESSION->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        label_SESSION->setFont(font3);
        label_SESSION->setFrameShape(QFrame::NoFrame);
        label_SESSION->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_SESSION, 1, 1, 1, 1);

        label_3 = new QLabel(frame_CONNECTIONS);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_3->setFont(font4);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_2 = new QLabel(frame_CONNECTIONS);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setFont(font4);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(frame_CONNECTIONS);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font4);

        gridLayout->addWidget(label, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_COMMANDS = new QVBoxLayout();
        verticalLayout_COMMANDS->setSpacing(6);
        verticalLayout_COMMANDS->setObjectName(QStringLiteral("verticalLayout_COMMANDS"));

        verticalLayout_2->addLayout(verticalLayout_COMMANDS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(frame_CONNECTIONS);

        HWConfigWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HWConfigWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 933, 18));
        HWConfigWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(HWConfigWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HWConfigWindow->setStatusBar(statusBar);

        retranslateUi(HWConfigWindow);

        QMetaObject::connectSlotsByName(HWConfigWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HWConfigWindow)
    {
        HWConfigWindow->setWindowTitle(QApplication::translate("HWConfigWindow", "HWConfig", 0));
        label_SESSION->setText(QApplication::translate("HWConfigWindow", "session description", 0));
        label_3->setText(QApplication::translate("HWConfigWindow", "CONNECTIONS:", 0));
        label_2->setText(QApplication::translate("HWConfigWindow", "SESSION:", 0));
        label->setText(QApplication::translate("HWConfigWindow", "COMMANDS:", 0));
    } // retranslateUi

};

namespace Ui {
    class HWConfigWindow: public Ui_HWConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HWCONFIGWINDOW_H
