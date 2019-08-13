#include "ICcalculator.h"
#include "ui_ICcalculator.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QQueue>
#include <QStack>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/mainIco.ico"));
    new_science=new science;
    new_complex=new Complex;
    new_game=new Game;
    ui->stackedWidget->addWidget(new_science);
    ui->stackedWidget->addWidget(new_complex);
    ui->stackedWidget->addWidget(new_game);
    ui->stackedWidget->setCurrentWidget(new_science);

    connect(ui->actionscience,&QAction::triggered,this,&Calculator::open_science);
    connect(ui->actioncomplex,&QAction::triggered,this,&Calculator::open_complex);
    connect(ui->actiongame,&QAction::triggered,this,&Calculator::open_game);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::open_science(){
    ui->stackedWidget->setCurrentWidget(new_science);
}

void Calculator::open_complex(){
    ui->stackedWidget->setCurrentWidget(new_complex);
}

void Calculator::open_game(){
    ui->stackedWidget->setCurrentWidget(new_game);
}
