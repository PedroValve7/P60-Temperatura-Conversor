#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Conversor; }
QT_END_NAMESPACE

class Conversor : public QDialog
{
    Q_OBJECT

public:
    Conversor(QWidget *parent = nullptr);
    ~Conversor();

public slots:
    void Cent2Fahr(int grados); void Cent3Kelv(int grados);
    void Fahr2Cent(int grados); void Fahr2Kelv(int grados);
    void Kelv2Cent(int grados); void Kelv2Fahr(int grados);

private:
    Ui::Conversor *ui;
};
#endif // CONVERSOR_H
