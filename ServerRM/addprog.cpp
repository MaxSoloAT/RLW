#include "addprog.h"
#include "ui_addprog.h"
#include <QDebug>
#include <QMessageBox>
addprog::addprog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addprog)
{
    ui->setupUi(this);

    QPixmap selprog_p(":/icons/icons/logset_i.png");
    QIcon selprog_i(selprog_p);
    setWindowIcon(selprog_i);
    setWindowTitle("Add");
    progs_f.setFileName("Programs.txt");
    progs_f.open(QIODevice::ReadWrite);
    QTextStream progs_ts(&progs_f);
    QString data_s =progs_f.readAll();
    data_sl = data_s.split("/n");
    data_sl.removeAll("");
    ui->prog_l->addItems(data_sl);
   // qDebug()<<data_sl<<endl;
}

addprog::~addprog()
{
    delete ui;
    progs_f.close();
}

void addprog::on_add_b_clicked()
{
    QString File_str;
    QTextStream progs_ts(&progs_f);
    File_str = QFileDialog::getOpenFileName(this, tr("Select file"), "/", tr("*.exe"));
    bool flag_same = 0;

    for(int i = 0; i< data_sl.size(); i++){
        if(File_str == data_sl[i]){
            flag_same = 1;
            break;
        }

    }
    if (flag_same != 1 ){
    ui->prog_l->addItem(File_str);
    progs_ts<<File_str+"/n";
    }
    else{
        QMessageBox::warning(this, "Add Error","There is this program!");
    }
}

void addprog::on_remove_b_clicked()
{
    //TODO if no rows get error and crash!!
    QString data_del = ui->prog_l->item(row_in_w)->text();


    //progs_f.close();
    //progs_f.remove();


    progs_f.setFileName("Programs.txt");
    progs_f.open(QIODevice::ReadWrite);
    QTextStream progs_ts(&progs_f);


    /*qDebug()<<data_s<<endl;
    QStringList dat;



    progs_f.setFileName("Programs.txt");
    progs_f.open(QIODevice::ReadWrite);
    dat = data_s.split("/n");
    //data_sl.removeAll(data_del);
    qDebug()<<dat;

    for(int i = 0; i < data_sl.size(); i++){
        progs_ts<<data_sl[i]+"/n";
    }

*/
  //  ui->prog_l->takeItem(row_in_w);


}

void addprog::on_prog_l_currentRowChanged(int currentRow)
{
    row_in_w = currentRow;
}
