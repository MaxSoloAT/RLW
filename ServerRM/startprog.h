#ifndef STARTPROG_H
#define STARTPROG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QProcess>
namespace Ui {
class startprog;
}

class startprog : public QDialog
{
    Q_OBJECT

public:
    explicit startprog(QWidget *parent = nullptr);
    ~startprog();


    QFile progs_f;
    QStringList data_sl;
    int row_in_w = 0;

private slots:
    void on_progs_l_currentRowChanged(int currentRow);

    void on_run_b_clicked();

private:
    Ui::startprog *ui;
};

#endif // STARTPROG_H
