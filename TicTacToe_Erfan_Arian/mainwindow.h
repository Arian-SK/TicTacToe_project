#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void showImage();

    void validation();

    void on_pushButtonStart_clicked();

    void on_lineEditP1_textChanged(const QString &arg1);

    void on_lineEditP2_textChanged(const QString &arg1);

    void soundClilck();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton10_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

    void on_pushButton13_clicked();

    void on_pushButton14_clicked();

    void on_pushButton15_clicked();

    void on_pushButton16_clicked();

    void on_pushButton17_clicked();

    void on_pushButton18_clicked();

    void on_pushButton19_clicked();

    void on_pushButton20_clicked();

    void on_pushButton21_clicked();

    void on_pushButton22_clicked();

    void on_pushButton23_clicked();

    void on_pushButton24_clicked();

    void on_pushButton25_clicked();

    void on_pushButtonReset_clicked();

    void on_pushButtonNewGame_clicked();

    void winScreen();

    void on_pushButtonExit_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonConfirm_clicked();

    void resultTable();

    void on_radioButtonYes_clicked();

    void on_radioButtonNo_clicked();

    void on_lineM1P1_textChanged(const QString &arg1);

    void on_lineM1P2_textChanged(const QString &arg1);

    void on_lineM3P1_textChanged(const QString &arg1);

    void on_lineM3P2_textChanged(const QString &arg1);

    void on_lineM2P1_textChanged(const QString &arg1);

    void on_lineM2P2_textChanged(const QString &arg1);

    void on_actionHow_to_play_triggered();

    void on_pushButtonNext_clicked();

    void on_pushButtonBack_clicked();

    void on_actionNew_game_triggered();

    void on_actionExit_triggered();

    void on_actionCredits_triggered();

    void finalChart();

    void on_pushButtonWall_clicked();

    void on_pushButtonMusic_clicked();

    void on_pushButtonSoundEffects_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
