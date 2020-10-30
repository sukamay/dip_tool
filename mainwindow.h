#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "image.h"
#include "ui_utils.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_file_triggered();

    void on_actionsave_file_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Image input_image;
    Mat output_mat;
};

#endif // MAINWINDOW_H
