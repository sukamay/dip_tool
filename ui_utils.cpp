#include "ui_utils.h"

#include <QImage>
#include <QPixmap>
#include <QVector>

//参数1-显示图像的Label，参数2-要显示的Mat
void LabelDisplayMat(QLabel *label,const cv::Mat &mat)
{
    cv::Mat Rgb;
    QImage Img;
    QVector<QRgb> gray_color_table;
    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else//Gray Img
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, QImage::Format_Indexed8);
        for (int i = 0; i < 256; i++) {
            gray_color_table.push_back(qRgb(i, i, i));
        }
        Img.setColorTable(gray_color_table);
    }
    Img = Img.scaled(label->size(), Qt::KeepAspectRatio);
    label->setPixmap(QPixmap::fromImage(Img));
//    label->setScaledContents(true);
}
