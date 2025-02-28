#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(300)
    , player2Time(300)
    , gameTime(300)
    , currentPlayer(1)
{
    ui->setupUi(this);

    pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &MainWindow::timeoutHandler);

    connect(ui->start_button, &QPushButton::clicked, this, &MainWindow::startHandler);
    connect(ui->stop_button, &QPushButton::clicked, this, &MainWindow::stopHandler);

    connect(ui->timebutton_5min, &QPushButton::clicked, this, &MainWindow::timeHandler);
    connect(ui->timebutton_120sec, &QPushButton::clicked, this, &MainWindow::timeHandler);

    connect(ui->switch_button1, &QPushButton::clicked, this, &MainWindow::playerHandler);

    updateProgressBar();
    setGameInfoText("Game ready. Select playtime!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeoutHandler()
{
    if (currentPlayer == 1) {
        player1Time--;
    } else {
        player2Time--;
    }

    if (player1Time <= 0 || player2Time <= 0) {
        pTimer->stop();
        setGameInfoText("Time is up! ");
        return;
    }

    updateProgressBar();
}

void MainWindow::startHandler()
{
    pTimer->start(1000);
    setGameInfoText("Game started!");
}

void MainWindow::stopHandler()
{
    pTimer->stop();
    setGameInfoText("Game stopped!");
}

void MainWindow::timeHandler()
{
    if (sender() == ui->timebutton_5min) {
        player1Time = player2Time = gameTime = 300;
    } else if (sender() == ui->timebutton_120sec) {
        player1Time = player2Time = gameTime = 120;
    }

    updateProgressBar();
    setGameInfoText("Time set. Press start!");
}

void MainWindow::playerHandler()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void MainWindow::updateProgressBar()
{
    ui->progressBar1->setValue((player1Time * 100) / gameTime);
    ui->progressBar2->setValue((player2Time * 100) / gameTime);
}

void MainWindow::setGameInfoText(QString text)
{
    ui->text_box->setText(text);
}
