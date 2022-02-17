#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_BBelRub_clicked();

    void on_BRusRub_clicked();

    void on_Bdol_clicked();

    void on_Bevr_clicked();


    void on_CenaZaKmBel_textEdited(const QString &arg1);

    void on_CenaZaKmRoss_textEdited(const QString &arg1);

    void on_CenaZaLitr_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
