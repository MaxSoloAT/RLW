#include "logset.h"
#include "ui_logset.h"
#include <QMessageBox>
#include <addprog.h>
#include <QDebug>
LogSet::LogSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogSet)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowTitle("Login");
    QPixmap selprog_p(":/icons/icons/logset_i.png");
    QIcon selprog_i(selprog_p);
    setWindowIcon(selprog_i);

    setFixedSize(155,70);
    ui->pass_t->setGeometry(5,5,50,25);
    ui->pass_t->setText("Password:");

    ui->pass_l->setGeometry(65,5,85,25);

    ui->login_b->setGeometry(5,40,70,25);
    ui->cancel_b->setGeometry(80,40,70,25);

    progs_f.setFileName(QDir::currentPath()+"/pass.txt");           //all under connect with reading password
    progs_f.open(QIODevice::ReadOnly);
    QTextStream progs_ts(&progs_f);
    data_psw =progs_f.readLine();

}

LogSet::~LogSet()
{
    delete ui;
}

void LogSet::on_cancel_b_clicked()  //exit
{
    close();
}

void LogSet::on_login_b_clicked()   //call checking password
{
    if(ui->pass_l->text() == data_psw){
        close();
        addprog progs;
        progs.setModal(true);
        progs.exec();
    }
    else{
        QMessageBox::warning(this, "Error","Wrong password");
    }
}
