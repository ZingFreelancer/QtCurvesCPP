#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spin_scale->setValue(this->ui->renderArea->getScale());
    this->ui->spin_interval->setValue(this->ui->renderArea->getIntervalLength());
    this->ui->spin_count->setValue(this->ui->renderArea->getStepCount());
    //ui->renderArea->setWindowTitle(ui->renderArea->windowTitle()+" ["+ui->renderArea->getShape()+"]");
    this->ui->renderArea->window()->setWindowTitle("Shape: "+ui->renderArea->shapeName);
}

void MainWindow::on_btn_Astroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_Cicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btw_HuygensCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_HypoCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_circle_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Circle);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_Line_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_spin_scale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}

void MainWindow::on_spin_interval_valueChanged(double length)
{
    this->ui->renderArea->setIntervalLength(length);
}

void MainWindow::on_spin_count_valueChanged(int count)
{
    this->ui->renderArea->setStepCount(count);
}

void MainWindow::on_btn_background_color_clicked()
{
    //open color picker dialog and change background color
    QColor color = QColorDialog::getColor(ui->renderArea->getBackgroundColor(), this, "Select Color");
    ui->renderArea->setBackgroundColor(color);
}

void MainWindow::on_btn_line_color_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->getShapeColor(), this, "Select Color");
    ui->renderArea->setShapeColor(color);
}

void MainWindow::on_btn_ellipse_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Ellipse);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_fancy_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Fancy);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_starfish_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Starfish);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_cloud_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud1);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btn_cloud2_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud2);
    this->ui->renderArea->repaint();
    update_ui();
}
