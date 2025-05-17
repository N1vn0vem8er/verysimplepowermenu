#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QProcess>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings(settingsPath);
    rebootCommand = settings.value("rebootCommand", "reboot").toString();
    shutdownCommand = settings.value("shutdownCommand", "shutdown now").toString();
    sleepCommand = settings.value("sleepCommand", "systemctl suspend").toString();
    logoutCommand = settings.value("logoutCommand", "echo no command set").toString();

    setWindowState(Qt::WindowFullScreen);
    ui->rebootButton->setFixedSize(QSize(300, 300));
    ui->shutdownButton->setFixedSize(QSize(300, 300));
    ui->sleepButton->setFixedSize(QSize(300, 300));
    ui->logoutButton->setFixedSize(QSize(300, 300));
    connect(ui->shutdownButton, &QPushButton::clicked, this, &MainWindow::shutdown);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::logout);
    connect(ui->rebootButton, &QPushButton::clicked, this, &MainWindow::reboot);
    connect(ui->sleepButton, &QPushButton::clicked, this, &MainWindow::sleep);
    QAction* exitAction = new QAction(this);
    exitAction->setShortcut(QKeySequence(Qt::Key_Escape));
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);
    addAction(exitAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shutdown()
{
    QProcess* process = new QProcess(this);
    process->startCommand(shutdownCommand);
    process->waitForFinished(3000);
    delete process;
    close();
}

void MainWindow::logout()
{
    QProcess* process = new QProcess(this);
    process->startCommand(logoutCommand);
    process->waitForFinished(3000);
    delete process;
    close();
}

void MainWindow::sleep()
{
    QProcess* process = new QProcess(this);
    process->startCommand(sleepCommand);
    process->waitForFinished(3000);
    delete process;
    close();
}

void MainWindow::reboot()
{
    QProcess* process = new QProcess(this);
    process->startCommand(rebootCommand);
    process->waitForFinished(3000);
    delete process;
    close();
}
