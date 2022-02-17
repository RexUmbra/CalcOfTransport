#include "mainwindow.h"
#include "ui_mainwindow.h"

double CenaZaKmBelBelRub = 0.44165, CenaZaKmRusBelRub = 0.634, cenaZaLitrBelRub = 1.68;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->label_11->setText("Бел. руб/км");
    ui->label_12->setText("Бел. руб");
    ui->CenaZaKmBel->setText(QString::number(CenaZaKmBelBelRub));

    ui->CenaZaKmRoss->setText(QString::number(CenaZaKmRusBelRub));
    ui->CenaZaLitr->setText(QString::number(cenaZaLitrBelRub));
    ui->RashTop->setText("32");
    ui->BBelRub->setChecked(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double lBel, lRus, cBel, cRus, rash, cLitr, zp, dopRash, l;
    QString getText = ui->belKm->text();
    lBel = getText.toDouble();

    getText = ui->rossKm_2->text();
    lRus = getText.toDouble();

    getText = ui->CenaZaKmBel->text();
    cBel = getText.toDouble();


    getText = ui->CenaZaKmRoss->text();
    cRus = getText.toDouble();

    getText = ui->RashTop->text();
    rash = getText.toDouble();

    getText = ui->CenaZaLitr->text();
    cLitr = getText.toDouble();

    getText = ui->zpVod->text();
    zp = getText.toDouble();

    getText = ui->dopRash->text();
    dopRash = getText.toDouble();

    getText = ui->rasstoianie->text();
    l = getText.toDouble();

    double itogKm = ((lBel*cBel) + (lRus*cRus) +  ((l/100)*rash*cLitr) + zp + dopRash)/(double)l;
    ui->itogKm->setText(QString::number(itogKm));
    double itog = (lBel*cBel) + (lRus*cRus) +  ((l/100)*rash*cLitr) + zp + dopRash;
    ui->itog->setText(QString::number(itog));

    double cBenzD = (l/100)*rash*cLitr;
    ui->cBenz->setText(QString::number(cBenzD));
    ui->NDS->setText(QString::number((cBenzD-cBenzD/1.2)));
}



void MainWindow::on_BBelRub_clicked()
{

  ui->label_11->setText("Бел. руб/км");
  ui->label_12->setText("Бел. руб");
  ui->CenaZaKmBel->setText(QString::number(CenaZaKmBelBelRub));
  ui->CenaZaKmRoss->setText(QString::number(CenaZaKmRusBelRub));
  ui->CenaZaLitr->setText(QString::number(cenaZaLitrBelRub));
}

void MainWindow::on_BRusRub_clicked()
{

  ui->label_11->setText("Рос. руб/км");
  ui->label_12->setText("Рос. руб");

  ui->CenaZaKmBel->setText(QString::number((100*CenaZaKmBelBelRub)/ui->kursRus->text().toDouble()));

  ui->CenaZaKmRoss->setText(QString::number((100*CenaZaKmRusBelRub)/ui->kursRus->text().toDouble()));
  ui->CenaZaLitr->setText(QString::number((100*cenaZaLitrBelRub)/ui->kursRus->text().toDouble()));
}

void MainWindow::on_Bdol_clicked()
{
  ui->label_11->setText("$/км");
  ui->label_12->setText("$");
  ui->CenaZaKmBel->setText(QString::number(CenaZaKmBelBelRub/ui->kursDol->text().toDouble()));
  ui->CenaZaKmRoss->setText(QString::number(CenaZaKmRusBelRub/ui->kursDol->text().toDouble()));
  ui->CenaZaLitr->setText(QString::number(cenaZaLitrBelRub/ui->kursDol->text().toDouble()));
}

void MainWindow::on_Bevr_clicked()
{
  ui->label_11->setText("€/км");
  ui->label_12->setText("€");
  ui->CenaZaKmBel->setText(QString::number(CenaZaKmBelBelRub/ui->kursEvr->text().toDouble()));
  ui->CenaZaKmRoss->setText(QString::number(CenaZaKmRusBelRub/ui->kursEvr->text().toDouble()));
  ui->CenaZaLitr->setText(QString::number(cenaZaLitrBelRub/ui->kursEvr->text().toDouble()));
}

void MainWindow::on_CenaZaKmBel_textEdited(const QString &arg1)
{
  if(ui->BBelRub->isChecked())
    {
      CenaZaKmBelBelRub = ui->CenaZaKmBel->text().toDouble();
    }
  else if(ui->BRusRub->isChecked())
    {

      CenaZaKmBelBelRub = (ui->CenaZaKmBel->text().toDouble()*ui->kursRus->text().toDouble()/100);
    }
  else if(ui->Bdol->isChecked())
    {
      CenaZaKmBelBelRub = (ui->CenaZaKmBel->text().toDouble()*ui->kursDol->text().toDouble());
    }
  else if(ui->Bevr->isChecked())
    {
      CenaZaKmBelBelRub = (ui->CenaZaKmBel->text().toDouble()*ui->kursEvr->text().toDouble());
    }
}

void MainWindow::on_CenaZaKmRoss_textEdited(const QString &arg1)
{
  if(ui->BBelRub->isChecked())
    {
      CenaZaKmRusBelRub = ui->CenaZaKmRoss->text().toDouble();
    }
  else if(ui->BRusRub->isChecked())
    {
      CenaZaKmRusBelRub = (ui->CenaZaKmRoss->text().toDouble()*ui->kursRus->text().toDouble())/100;
    }
  else if(ui->Bdol->isChecked())
    {
      CenaZaKmRusBelRub = (ui->CenaZaKmRoss->text().toDouble()*ui->kursDol->text().toDouble());
    }
  else if(ui->Bevr->isChecked())
    {
      CenaZaKmRusBelRub = (ui->CenaZaKmRoss->text().toDouble()*ui->kursEvr->text().toDouble());
    }
}

void MainWindow::on_CenaZaLitr_textEdited(const QString &arg1)
{
  if(ui->BBelRub->isChecked())
    {
      cenaZaLitrBelRub = ui->CenaZaLitr->text().toDouble();
    }
  else if(ui->BRusRub->isChecked())
    {
      cenaZaLitrBelRub = (ui->CenaZaLitr->text().toDouble()*ui->kursRus->text().toDouble())/100;
    }
  else if(ui->Bdol->isChecked())
    {
      cenaZaLitrBelRub = (ui->CenaZaLitr->text().toDouble()*ui->kursDol->text().toDouble());
    }
  else if(ui->Bevr->isChecked())
    {
      cenaZaLitrBelRub = (ui->CenaZaLitr->text().toDouble()*ui->kursEvr->text().toDouble());
    }
}
