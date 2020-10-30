#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QCoreApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionopen_file_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(
            this,
            tr("open image."),
            QCoreApplication::applicationDirPath(),
            tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    qDebug()<<"open file: "<<file_name;
    ERROR_CODE ret = input_image.SetImg(file_name.toStdString());
    if (ret == OK) {
        LabelDisplayMat(ui->input_img, input_image.GetImg());
    }
}

void MainWindow::on_actionsave_file_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(
            this,
            tr("save a file."),
            QCoreApplication::applicationDirPath(),
            tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    qDebug()<<"save file: "<<file_name;
    cv::imwrite(file_name.toStdString(), output_mat);
}

void MainWindow::on_pushButton_clicked()
{
//    img dilate
    DilateParams params;
    params.iteration = ui->in_dilate_0_iteration->value();
    params.kernel_size = ui->in_dilate_1_kernel_size->value();
    params.morph_shape = cv::MORPH_RECT;
    ERROR_CODE ret = input_image.Dilate(output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
//    img erode
    ErodeParams params;
    params.iteration = ui->in_erode_0_iteration->value();
    params.kernel_size = ui->in_erode_1_kernel_size->value();
    params.morph_shape = cv::MORPH_RECT;
    ERROR_CODE ret = input_image.Erode(output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    }
}
