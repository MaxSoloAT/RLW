
#ifndef STUDENT_LOG_H
#define STUDENT_LOG_H

#include <QDialog>
#include <QNetworkAccessManager>

namespace Ui {
class student_log;
}

class student_log : public QDialog
{
    Q_OBJECT

public:
    explicit student_log(QWidget *parent = nullptr);
    ~student_log();

    /*QString url_person = "http://ogonek.kl.com.ua/index.php?zapros=";//change name zapros
    QNetworkAccessManager * manager;
    QNetworkRequest request;*/

private slots:
    void on_login_b_clicked();

private:
    Ui::student_log *ui;
};

#endif // STUDENT_LOG_H
