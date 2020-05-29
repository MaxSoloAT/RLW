#ifndef LOGSET_H
#define LOGSET_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class LogSet;
}

class LogSet : public QDialog
{
    Q_OBJECT

public:
    explicit LogSet(QWidget *parent = nullptr);
    ~LogSet();

    QFile progs_f;
    QString data_psw;
private slots:


    void on_cancel_b_clicked();

    void on_login_b_clicked();

private:
    Ui::LogSet *ui;
};

#endif // LOGSET_H
