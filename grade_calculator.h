#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>
#include <QObject>
#include <QMessageBox>

namespace Ui {
class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = nullptr);
    ~grade_calculator();
private slots:
    void update_overall();
    void update_C();
    void on_pushButton_clicked();

private:
    Ui::grade_calculator *ui;
};

#endif // GRADE_CALCULATOR_H
