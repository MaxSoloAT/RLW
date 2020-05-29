#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int w_h = 48;


private slots:
    void on_exit_b_clicked();

    void on_cam_b_clicked();


    void on_logset_b_clicked();


    void on_selprog_b_clicked();

private:
    Ui::MainWindow *ui;
    int flagO_C = 1;
};
#endif // MAINWINDOW_H
