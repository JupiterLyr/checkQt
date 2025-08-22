#include "mainwindow.h"

#include <QtCore/qlogging.h>
#include <QtCore/qnamespace.h>

#include <iostream>
#include <QThread>
#include <QWidget>

#include "ui.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    std::cout << "MainWindow threadId: " << QThread::currentThreadId() << std::endl;
    ui = new Ui::MainWindow();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}