#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>
#include <QObject>

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
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::grade_calculator *ui;
};

#endif // GRADE_CALCULATOR_H
