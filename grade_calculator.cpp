#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->hw1spinbox,SLOT(setValue(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->midterm1spinbox,SLOT(setValue(int)));
    QObject::connect(ui->hw1spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
    QObject::connect(ui->midterm1spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall() {
    double hw1 = ui->hw1spinbox->value();
    double mt1 = ui->midterm1spinbox->value();

    //double hw = hw1;
    double overall = hw1+mt1;
    ui->overall_grade->setText(QString::number(overall));
}
