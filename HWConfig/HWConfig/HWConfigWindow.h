#ifndef HWCONFIGWINDOW_H
#define HWCONFIGWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "HWConfig.h"
#include <QPushButton>
#include <QStringList>
#include <QProgressDialog>

namespace Ui {
class HWConfigWindow;
}

class HWConfigWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HWConfigWindow(QWidget *parent = 0);
    ~HWConfigWindow();

signals:
    void cmdSended();

private slots:

    void on_lineEdit_CMD_returnPressed();

    void on_comboBox_CONNECTIONS_currentIndexChanged(int index);

    void on_cmdSended();

    void on_cmd_BUTTONS_clicked();


private:
    int progressValue;
    int maxProgressValue;
    QProgressDialog* progressDialog;
    Ui::HWConfigWindow *ui;
    HWConfig* config;
    QVector<QPushButton*> buttons;
    void createCMDButtons();
    void showCurConnection();
    void showCommands();
    void showSession();
    void executeCMD(int cmd_index);
 };

#endif // HWCONFIGWINDOW_H
