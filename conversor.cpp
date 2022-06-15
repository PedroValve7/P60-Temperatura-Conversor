#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectar el Dial de centigrados con el slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(Cent2Fahr(int)));

    connect(ui->inFah, SIGNAL(valueChanged(int)),
            this, SLOT(Fahr2Cent(int)));

    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(Cent3Kelv(int)));

    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT(Kelv2Cent(int)));

    connect(ui->inFah, SIGNAL(valueChanged(int)),
            this, SLOT(Fahr2Kelv(int)));

    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT(Kelv2Fahr(int)));
}

Conversor::~Conversor()
{
    delete ui;

}
void Conversor::Cent3Kelv(int grados)
{
    if (ui->inCent->hasFocus()){
        int ck = (grados + 273.15);
        ui->inKel->setValue(ck);
    }
}

void Conversor::Cent2Fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int cf = (grados * 9.0/5) +32;
        ui->inFah->setValue(cf);
    }
}

void Conversor::Fahr2Kelv(int grados)
{
    if (ui->inFah->hasFocus()){
        int fk = ((grados - 32) * 5.0/9) + 273.15;
        ui->inKel->setValue(fk);
    }
}
void Conversor::Fahr2Cent(int grados)
{
    if (ui->inFah->hasFocus()){
        int fc = (grados - 32) * 5.0/9;
        ui->inCent->setValue(fc);
    }
}



void Conversor::Kelv2Cent(int grados)
{
    if (ui->inKel->hasFocus()){
        int kc = (grados - 273.15);
        ui->inCent->setValue(kc);
    }
}



void Conversor::Kelv2Fahr(int grados)
{
    if (ui->inKel->hasFocus()){
        int kf = ((grados - 273.15) * 9.0/5) + 32;
        ui->inFah->setValue(kf);
    }
}

