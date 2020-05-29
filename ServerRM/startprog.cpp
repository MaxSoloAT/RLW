#include "startprog.h"
#include "ui_startprog.h"

startprog::startprog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startprog)
{
    ui->setupUi(this);
    setWindowTitle("Start");
    QPixmap exi(":/icons/icons/selprog_i.png");
    QIcon ex(exi);
    setWindowIcon(ex);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    ui->progs_l->setGeometry(0,0,300,100);
    ui->run_b->setGeometry(0,100,300,25);
    setFixedSize(300,125);

    progs_f.setFileName("Programs.txt");
    progs_f.open(QIODevice::ReadWrite);
    QTextStream progs_ts(&progs_f);
    QString data_s =progs_f.readAll();
    data_sl = data_s.split("/n");
    data_sl.removeAll("");
    ui->progs_l->addItems(data_sl);

}

startprog::~startprog()
{
    delete ui;
}

void startprog::on_progs_l_currentRowChanged(int currentRow)
{
    row_in_w = currentRow;
}

void startprog::on_run_b_clicked()
{
     QString url_prog = ui->progs_l->item(row_in_w)->text();
     QProcess::startDetached(url_prog);
}
