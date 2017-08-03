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

    void on_spin_scale_valueChanged(double arg1);

    //Variables
    void on_spin_interval_valueChanged(double arg1);

    void on_spin_count_valueChanged(int arg1);

    void on_btn_background_color_clicked();

    void on_btn_line_color_clicked();

    void on_btn_circle_clicked();

    void on_btn_ellipse_clicked();

    void on_btn_fancy_clicked();

    //Variables
    void on_btn_starfish_clicked();

private:
    Ui::MainWindow *ui;

    //Methods
private:
    void update_ui();
};

#endif // MAINWINDOW_H
