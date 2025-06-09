#include "ui.h"

#include <QtCore/qnamespace.h>
#include <QWidget>

namespace Ui
{
    void MainWindow::setupUi(QMainWindow *mainWindow)
    {
        QWidget *centralWidget = new QWidget(mainWindow);
        mainWindow->setCentralWidget(centralWidget);
        centralWidget->setMinimumSize(800, 600);
    }
}; // namespace Ui