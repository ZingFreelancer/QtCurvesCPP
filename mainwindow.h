#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_Astroid_clicked();

    void on_btn_Cicloid_clicked();

    void on_btw_HuygensCicloid_clicked();

    void on_btn_HypoCicloid_clicked();

    void on_btn_Line_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
