#include "student_log.h"
#include "ui_student_log.h"
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QTextCodec>
student_log::student_log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_log)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowTitle("Login");
    QPixmap exi(":/icons/icons/main_i.png");
    QIcon ex(exi);
    setWindowIcon(ex);
    //QPixmap selprog_p(":/icons/icons/logset_i.png");
    //QIcon selprog_i(selprog_p);
    //setWindowIcon(selprog_i);
    setWindowFlags(Qt::Window       //disable x
        | Qt::WindowMinimizeButtonHint
        | Qt::WindowMaximizeButtonHint
        );
    setFixedSize(155,95);

    ui->name_l->setGeometry(5,5,45,20);
    ui->name_l->setText("Name");
    ui->sname_l->setGeometry(5,25,45,20);
    ui->sname_l->setText("Surname");
    ui->group_l->setGeometry(5,45,45,20);
    ui->group_l->setText("Group");

    ui->name_el->setGeometry(50,5,100,20);
    ui->surname_el->setGeometry(50,25,100,20);
    ui->group_el->setGeometry(50,45,100,20);
    ui->login_b->setGeometry(5,70,145,20);
}

student_log::~student_log() //open main

{

    if(ui->name_el->text() == "" || ui->surname_el->text() == "" || ui->group_el->text() == ""){
    //qDebug()<<ui->name_el->text(),ui->surname_el->text(),ui->group_el->text();
    }
    else{
        delete ui;
    }
}

void student_log::on_login_b_clicked()
{
   /* QString data_s;
    data_s +="PC 1";
    data_s +=" ";
    data_s +="First name:";
    data_s += ui->firname_l->text();
    data_s +=" ";
    data_s +="Second name:";
    data_s += ui->secname_l->text();

    manager = new QNetworkAccessManager();
    request.setUrl(QUrl(url_person+data_s));
    manager->get(request);
    //Qmassegebox
    data_s.clear();*/

    if(ui->name_el->text() == "" || ui->surname_el->text() == "" || ui->group_el->text() == ""){
    }
    else{
        QFile *progs_f = new QFile;
        progs_f->setFileName(QDir::currentPath()+"/users.txt");
        progs_f->open(QIODevice::Append);
        QTextStream progs_ts(progs_f);

       progs_ts.setCodec("");
        progs_ts<<"Date: "<<QDateTime::currentDateTime().toString()<<" Name: " << ui->name_el->text() << " Surname: " << ui->surname_el->text() << " Group: "<<ui->group_el->text()<<"\n";
        progs_f->close();
        delete progs_f;
        close();
    }
}
