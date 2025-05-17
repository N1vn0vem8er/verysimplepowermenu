#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    const QString settingsPath = "vspmsettings";
    QString shutdownCommand = "shutdown now";
    QString rebootCommand = "reboot";
    QString logoutCommand = "echo no command set";
    QString sleepCommand = "echo no command set";

private slots:
    void shutdown();
    void logout();
    void sleep();
    void reboot();
};
#endif // MAINWINDOW_H
