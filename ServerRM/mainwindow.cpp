#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <logset.h>
#include <startprog.h>
#include <student_log.h>


#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QNetworkAccessManager>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle("LWK");
    //наследование от QWigdet!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*QProcess *AN_inst = new QProcess;
    AN_inst->start(QDir::currentPath()+"/release/AnyDesk/id.bat"); //check
    AN_inst->waitForFinished(-1);
    QString id_s = AN_inst->readAllStandardOutput();
    id_s.remove(" \r\n");*/

    /*AN_inst->start(QDir::currentPath()+"/release/AnyDesk/alias.bat");
    AN_inst->waitForFinished(-1);
    QString al_s = AN_inst->readAllStandardOutput();
    al_s.remove(" \r\n");*/

    /*AN_inst->start(QDir::currentPath()+"/release/AnyDesk/status.bat");
    AN_inst->waitForFinished(-1);
    QString status_s = AN_inst->readAllStandardOutput();
    status_s.remove(" \r\n");

    QString *labPC_s = new QString;
    labPC_s->push_back("http://ogonek.kl.com.ua/index.php?pc_free=");
    labPC_s->push_back("wat pc? "); //add number probably in logset
    labPC_s->push_back(status_s);
    labPC_s->push_back(" ");
    labPC_s->push_back(id_s);

    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QNetworkRequest *request = new QNetworkRequest;
    request->setUrl(QUrl(*labPC_s));
    manager->get(*request);
    //qDebug()<<*labPC_s;

    delete labPC_s;
    delete AN_inst;
    delete manager;
    delete request;*/

    ui->setupUi(this);
    //QPalette backgr(palette());
    //backgr.setColor(QPalette::Background, Qt::black);
    //m_pMyWidget->setAutoFillBackground(true);
    //m_pMyWidget->setPalette(Pal);
    //m_pMyWidget->show();


    system("taskkill /f /im explorer.exe");
    student_log st;
    st.exec();
    ui->exit_b->setGeometry(3*w_h,0,w_h,w_h);
    QPixmap exit_p(":/icons/icons/exit_i.png");
    QIcon exit_i(exit_p);
    ui->exit_b->setIcon(exit_i);
    ui->exit_b->setIconSize(QSize(w_h,w_h));

    ui->cam_b->setGeometry(1*w_h,0,w_h,w_h);
    QPixmap cam_p(":/icons/icons/cam_i.png");
    QIcon cam_i(cam_p);
    ui->cam_b->setIcon(cam_i);
    ui->cam_b->setIconSize(QSize(w_h,w_h));

    ui->logset_b->setGeometry(2*w_h,0,w_h,w_h);
    QPixmap logset_p(":/icons/icons/logset_i.png");
    QIcon logset_i(logset_p);
    ui->logset_b->setIcon(logset_i);
    ui->logset_b->setIconSize(QSize(w_h,w_h));

    ui->selprog_b->setGeometry(0*w_h,0,w_h,w_h);
    QPixmap selprog_p(":/icons/icons/selprog_i.png");
    QIcon selprog_i(selprog_p);
    ui->selprog_b->setIcon(selprog_i);
    ui->selprog_b->setIconSize(QSize(w_h,w_h));

    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlag(Qt::WindowStaysOnTopHint); //above all program


    //TODO + user name + group +pc(what lab)
}

MainWindow::~MainWindow()   //TODO check closing cam player
{   flagO_C = 0;
    delete ui;
    cv::destroyAllWindows();

    //QProcess::startDetached("C:\\Windows\\System32\\tsdiscon.exe"); //dont work
    QProcess::startDetached("C:\\Windows\\explorer.exe");

}

void MainWindow::on_exit_b_clicked() //exit
{
    flagO_C = 0;
    close(); // call destructor
}

void MainWindow::on_cam_b_clicked() //only open
{
    cv::VideoCapture cap(0);
    cv::Mat frame;
    if (cap.isOpened()){
        while(1){
            cap.read(frame);
            cv::imshow("WIN_RF", frame);
            cv::waitKey(30);
            if(flagO_C == 0){
                break;
                 cv::destroyAllWindows();
            }
        }
    }
    else {
        QMessageBox::warning(this, "Error CAM","Проблеми з камерою.\n Перевірте підключення.");
    }
}



void MainWindow::on_logset_b_clicked()
{
    LogSet log_set;
    log_set.setModal(true);
    log_set.exec();
}



void MainWindow::on_selprog_b_clicked()
{
    startprog start_prog;
    start_prog.setModal(true);
    start_prog.exec();
}
