#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 确保 Ui 命名空间的前向声明正确
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    // Q_OBJECT  // 需要用到信号和槽时要加回来

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H