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
    setWindowState(Qt::WindowMaximized);
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
    ERROR_CODE ret = LoadImg(file_name.toStdString(), input_mat);
    if (ret == OK) {
        LabelDisplayMat(ui->input_img, input_mat);
        cvtColor(input_mat, gray_mat, COLOR_BGR2GRAY);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to load img, error code: ") + QString::number(int(ret)));
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
    ERROR_CODE ret = Dilate(input_mat, output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to dilate img, error code: ") + QString::number(int(ret)));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
//    img erode
    ErodeParams params;
    params.iteration = ui->in_erode_0_iteration->value();
    params.kernel_size = ui->in_erode_1_kernel_size->value();
    params.morph_shape = cv::MORPH_RECT;
    ERROR_CODE ret = Erode(input_mat, output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to erode img, error code: ") + QString::number(int(ret)));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
//    show gray img
    if (!gray_mat.empty()) {
        LabelDisplayMat(ui->output_img, gray_mat);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
//    show histogram of gray img
}

void MainWindow::on_pushButton_5_clicked()
{
//    gaussian filter
    GaussianFilterParams params;
    params.kernel_x = ui->in_gaussian_filter_0->value();
    params.kernel_y = ui->in_gaussian_filter_1->value();
    params.sigma = ui->in_gaussian_filter_2->value();
    ERROR_CODE ret = GaussianFilter(input_mat, output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to filter img, error code: ") + QString::number(int(ret)));
    }
}

void MainWindow::on_pushButton_6_clicked()
{
//    mean filter
    MeanFilterParams params;
    params.kernel_x = ui->in_mean_filter_0->value();
    params.kernel_y = ui->in_mean_filter_1->value();
    ERROR_CODE ret = MeanFilter(input_mat, output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to filter img, error code: ") + QString::number(int(ret)));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
//    median filter
    MedianFilterParams params;
    params.kernel_size = ui->in_median_filter_0->value();
    ERROR_CODE ret = MedianFilter(input_mat, output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to filter img, error code: ") + QString::number(int(ret)));
    }
}

void MainWindow::on_pushButton_8_clicked()
{
//    bilateral filter
    BilateralFilterParams params;
    params.diameter = ui->in_bilateral_filter_0->value();
    params.sigma_color = ui->in_bilateral_filter_1->value();
    params.sigma_space = ui->in_bilateral_filter_2->value();
    ERROR_CODE ret = BilateralFilter(input_mat, output_mat, params);
    if (ret == OK) {
        LabelDisplayMat(ui->output_img, output_mat);
    } else {
        QMessageBox::warning(this, tr("error"), tr("fail to filter img, error code: ") + QString::number(int(ret)));
    }
}
