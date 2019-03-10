#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
        QObject::connect(ui->hw1spinbox,SIGNAL(valueChanged(int)),
                             this,SLOT(update_overall()));
        QObject::connect(ui->hw2spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->hw3spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->hw4spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->hw5spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->hw6spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->hw7spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->hw8spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->mt1spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->mt2spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->finalspinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
        QObject::connect(ui->schemaa,SIGNAL(clicked()),
                         this,SLOT(update_overall()));
        QObject::connect(ui->schemab,SIGNAL(clicked()),
                         this,SLOT(update_overall()));

    //ui->schemaa->setChecked(1);

   /* QObject::connect(ui->hw1spinbox,SIGNAL(valueChanged(int)),
                         this,SLOT(update_overall()));
    QObject::connect(ui->hw2spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->hw3spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->hw4spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->hw5spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->hw6spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->hw7spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->hw8spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->mt1spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->mt2spinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->finalspinbox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall()));
    QObject::connect(ui->schemaa,SIGNAL(clicked()),
                     this,SLOT(update_overall()));
    QObject::connect(ui->schemab,SIGNAL(clicked()),
                     this,SLOT(update_overall()));

    ui->schemab->setChecked(1);*/
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall() {
    double hw1 = ui->hw1spinbox->value();
    double hw2 = ui->hw2spinbox->value();
    double hw3 = ui->hw3spinbox->value();
    double hw4 = ui->hw4spinbox->value();
    double hw5 = ui->hw5spinbox->value();
    double hw6 = ui->hw6spinbox->value();
    double hw7 = ui->hw7spinbox->value();
    double hw8 = ui->hw8spinbox->value();
    double mt1 = ui->mt1spinbox->value();
    double mt2 = ui->mt2spinbox->value();
    double f = ui->finalspinbox->value();

    double hw_total = hw1 + hw2 + hw3 + hw4 + hw5 + hw6 + hw7 + hw8;
    double overall = 0;

    if(ui->schemaa->isChecked())
        overall = hw_total/32+mt1/5+mt2/5+f*.35;
    if(ui->schemab->isChecked()){
        double exam = ((mt1>mt2)?mt1:mt2);
        overall = hw_total/32+exam*.3+f*.44;
    }
    ui->overall_grade->setText(QString::number(overall));
}

