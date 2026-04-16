#include "ui.h"

#include <QtCore/qnamespace.h>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
    void MainWindow::setupUi(QMainWindow* mainWindow) {
        QWidget* centralWidget = new QWidget(mainWindow);
        mainWindow->setCentralWidget(centralWidget);
        centralWidget->setMinimumSize(800, 600);

        mainWindow->setWindowTitle("Development Template");
        QString iconPath = QDir(QCoreApplication::applicationDirPath()).filePath("resource/checkQtIcon.png");
        if (QFileInfo::exists(iconPath))
            mainWindow->setWindowIcon(QIcon(iconPath));
        else
            QMessageBox::warning(nullptr, "Warning", "Icon file does not exist!");
        
        QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
        QLabel *show_version = new QLabel("Template v2.3");
        show_version->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(show_version);
    }
}; // namespace Ui