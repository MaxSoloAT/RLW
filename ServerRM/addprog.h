#ifndef ADDPROG_H
#define ADDPROG_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QProcess>
#include <QDir>
#include <QTextStream>

namespace Ui {
class addprog;
}

class addprog : public QDialog
{
    Q_OBJECT

public:
    explicit addprog(QWidget *parent = nullptr);
    ~addprog();

    QFile progs_f;
    QStringList data_sl;
    int row_in_w = 0;


private slots:
    void on_add_b_clicked();

    void on_remove_b_clicked();



    void on_prog_l_currentRowChanged(int currentRow);

private:
    Ui::addprog *ui;
};

#endif // ADDPROG_H
