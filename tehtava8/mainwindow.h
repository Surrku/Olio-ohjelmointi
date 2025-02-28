#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startHandler();
    void stopHandler();
    void timeHandler();
    void playerHandler();
    void timeoutHandler();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pTimer;

    void updateProgressBar();
    void setGameInfoText(QString text);
};

#endif // MAINWINDOW_H
