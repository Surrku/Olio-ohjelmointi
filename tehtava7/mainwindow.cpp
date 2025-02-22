#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{
    state = 0;

    ui->setupUi(this);
    connect(ui->n1, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n2, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n3, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n4, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n5, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n6, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n7, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n8, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n9, &QPushButton::clicked, this, &MainWindow::numberHandler);
    connect(ui->n0, &QPushButton::clicked, this, &MainWindow::numberHandler);

    connect(ui->sum, &QPushButton::clicked, this, &MainWindow::calcHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::calcHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::calcHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::calcHandler);

    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enterHandler);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberHandler()
{
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString numberName = button->objectName();
    qDebug()<<numberName.at(1);

    if(state ==0) {
        ui->num1Box->setText(ui->num1Box->text()+numberName.at(1));
    }
    else {
        ui->num2Box->setText(ui->num2Box->text()+numberName.at(1));
    }

}

void MainWindow::calcHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    state = 1;

    bool num1, num2;

    float number1 = ui->num1Box->text().toFloat(&num1);
    float number2= ui->num2Box->text().toFloat(&num2);

    if (button == ui->sum)
        operand = 0;
    else if (button == ui->sub)
        operand = 1;
    else if (button == ui->div)
        operand = 2;
    else
        operand = 3;

}

void MainWindow::enterHandler()
{
    bool num1Ok, num2Ok;
    float number1 = ui->num1Box->text().toFloat(&num1Ok);
    float number2 = ui->num2Box->text().toFloat(&num2Ok);

    //if (!num1Ok || !num2Ok) {
    //    ui->resultBox->setText("Virheellinen syöte");
    //    return;
    //}

    switch (operand) {
    case 0: result = number1 + number2; break;
    case 1: result = number1 - number2; break;
    case 2:
        if (number2 != 0)
            result = number1 / number2;
        else {
            return;
        }
        break;
    case 3: result = number1 * number2; break;
    }

    ui->resultBox->setText(QString::number(result));
    state = 0;
}


void MainWindow::clearHandler()
{
    ui->resultBox->clear();
    ui->num1Box->clear();
    ui->num2Box->clear();
    state = 0;
}

