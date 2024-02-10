#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QSound>
#include <QMessageBox>
#include <QPixmap>
#include <QUrl>
#include <QtMultimedia/QMediaPlayer>
#include <QSoundEffect>
#include <QMediaPlaylist>

int currentP = 1;
int i = 0;
int val1 = 0, val2 = 0;
int c = 0;
int round = 1;
int musicOfforOn = 0;
int soundClick = 0;

QMediaPlayer* music = new QMediaPlayer();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TicTacToe");
    setWindowIcon(QIcon(":/resources/Images/Game_Icon.ico"));



    ui->pushButtonExit->setIcon(QIcon(":/resources/Images/Exit_Icon.ico"));
    ui->pushButtonExit->setIconSize(QSize(81,81));
    ui->actionExit->setIcon(QIcon(":/resources/Images/Exit_Icon.ico"));
    ui->actionHow_to_play->setIcon(QIcon(":/resources/Images/HowToPlay_Icon.png"));
    ui->actionNew_game->setIcon(QIcon(":/resources/Images/NewGame_Icon.png"));
    ui->actionCredits->setIcon(QIcon(":/resources/Images/Credits_Icon.png"));

    QPixmap pixWall(":/resources/Images/Wallpaper.png");
    music->setMedia(QUrl("qrc:/resources/Sounds/backGroundMusic.wav"));
    music->play();

    connect(music,&QMediaPlayer::mediaStatusChanged,music,&QMediaPlayer::play);



    ui->labelWallpaper->setPixmap(pixWall.scaled(1800,1200));
    ui->pushButtonNext->setVisible(false);
    ui->pushButtonBack->setVisible(false);
    ui->labelPix->setVisible(false);
    ui->pushButtonNewGame->setEnabled(false);
    ui->groupBoxYN->setVisible(false);
    ui->labelWin->setVisible(false);
    ui->labelT->setVisible(false);
    ui->labelX->setVisible(false);
    ui->labelError->setVisible(false);
    ui->pushButtonReset->setEnabled(false);
    ui->pushButtonStart->setEnabled(false);
    ui->pushButton1->setEnabled(false);
    ui->pushButton2->setEnabled(false);
    ui->pushButton3->setEnabled(false);
    ui->pushButton4->setEnabled(false);
    ui->pushButton5->setEnabled(false);
    ui->pushButton6->setEnabled(false);
    ui->pushButton7->setEnabled(false);
    ui->pushButton8->setEnabled(false);
    ui->pushButton9->setEnabled(false);
    ui->pushButton10->setEnabled(false);
    ui->pushButton11->setEnabled(false);
    ui->pushButton12->setEnabled(false);
    ui->pushButton13->setEnabled(false);
    ui->pushButton14->setEnabled(false);
    ui->pushButton15->setEnabled(false);
    ui->pushButton16->setEnabled(false);
    ui->pushButton17->setEnabled(false);
    ui->pushButton18->setEnabled(false);
    ui->pushButton19->setEnabled(false);
    ui->pushButton20->setEnabled(false);
    ui->pushButton21->setEnabled(false);
    ui->pushButton22->setEnabled(false);
    ui->pushButton23->setEnabled(false);
    ui->pushButton24->setEnabled(false);
    ui->pushButton25->setEnabled(false);
    ui->lineM1P1->setEnabled(false);
    ui->lineM1P2->setEnabled(false);
    ui->lineM2P1->setEnabled(false);
    ui->lineM2P2->setEnabled(false);
    ui->lineM3P1->setEnabled(false);
    ui->lineM3P2->setEnabled(false);
    ui->pushButtonConfirm->setVisible(false);
    ui->pushButtonEdit->setEnabled(false);
    ui->pushButtonReset->setVisible(false);
    ui->labelX->setStyleSheet("color:green;");
    ui->labelX->setText(ui->lineEditP1->text());
    ui->labelW1->setVisible(false);
    ui->labelW2->setVisible(false);
    ui->labelW3->setVisible(false);
    ui->labelW4->setVisible(false);
    ui->labelW5->setVisible(false);
    ui->labelW6->setVisible(false);
    ui->labelW7->setVisible(false);
    ui->labelW8->setVisible(false);
    ui->labelW9->setVisible(false);
    ui->labelW10->setVisible(false);
    ui->labelW11->setVisible(false);
    ui->labelW12->setVisible(false);
}

int countT = 0;

void MainWindow::on_actionHow_to_play_triggered()
{
    QPixmap pixHTP(":/resources/Images/howToPlay.png");

    ui->labelPix->setVisible(true);
    ui->labelPix->setPixmap(pixHTP);
    ui->pushButtonBack->setEnabled(false);
    ui->pushButtonNext->setVisible(true);
    ui->pushButtonBack->setVisible(true);

}

void MainWindow::on_pushButtonNext_clicked()
{
    countT++;
    showImage();
}

void MainWindow::on_pushButtonBack_clicked()
{
    countT--;
    showImage();
}

void MainWindow::showImage()
{
    int w = ui->labelPix->width();
    int h = ui->labelPix->height();
    QPixmap pixHTP(":/resources/Images/howToPlay.png");
    QPixmap pixEN(":/resources/Images/enterName.png");
    QPixmap pixHTW(":/resources/Images/howTowWin.png");
    QPixmap pixSA(":/resources/Images/startActive.png");
    QPixmap pixW1(":/resources/Images/win1.png");
    QPixmap pixW2(":/resources/Images/win2.png");
    QPixmap pixW3(":/resources/Images/win3.png");
    QPixmap pixOI(":/resources/Images/ohterInformations.png");
    QPixmap pixT1(":/resources/Images/turn1.png");
    QPixmap pixT2(":/resources/Images/turn2.png");
    QPixmap pixTE(":/resources/Images/turnEnd.png");
    if(countT == 0)
    {
        ui->pushButtonBack->setEnabled(false);
    }
    else
    {
        ui->pushButtonBack->setEnabled(true);
    }
    if(countT == 10)
    {
        ui->pushButtonNext->setText("Ok");
    }
    if(countT == 11)
    {
        countT = 0;
        ui->labelPix->setVisible(false);
        ui->pushButtonBack->setVisible(false);
        ui->pushButtonNext->setVisible(false);
        ui->pushButtonNext->setText("Next");
    }
    if(countT == 0)
    {
        ui->labelPix->setPixmap(pixHTP.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 1)
    {
        ui->labelPix->setPixmap(pixEN.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 2)
    {
        ui->labelPix->setPixmap(pixSA.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 3)
    {
        ui->labelPix->setPixmap(pixT1.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 4)
    {
        ui->labelPix->setPixmap(pixT2.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 5)
    {
        ui->labelPix->setPixmap(pixTE.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 6)
    {
        ui->labelPix->setPixmap(pixHTW.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 7)
    {
        ui->labelPix->setPixmap(pixW1.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 8)
    {
        ui->labelPix->setPixmap(pixW2.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 9)
    {
        ui->labelPix->setPixmap(pixW3.scaled(w,h,Qt::KeepAspectRatio));
    }
    else if(countT == 10)
    {
        ui->labelPix->setPixmap(pixOI.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::winScreen()
{
    QString name1 = ui->lineEditP1->text();
    QString name2 = ui->lineEditP2->text();
    i++;
    int w = ui->labelPix->width();
    int h = ui->labelPix->height();
    QPixmap pixL1(":/resources/Images/line1.png");
    QPixmap pixL2(":/resources/Images/line 2.png");
    QPixmap pixL3(":/resources/Images/line 3.png");
    QPixmap pixL4(":/resources/Images/line 4.png");



    if(i == 25 && c == 0)
        {
        if(soundClick==0)
        {
           QSound::play(":/resources/Sounds/drawSound.wav");
        }
            ui->labelWin->setVisible(true);
            ui->labelWin->setStyleSheet("color:blue;");
            ui->labelWin->setText("Draw 🤝");
            resultTable();

            c = 1;i = 0;
        }

    if(     ui->pushButton1->text().length()>0&&
            ui->pushButton1->text()==ui->pushButton7->text()&&
            ui->pushButton7->text()==ui->pushButton13->text()&&
            ui->pushButton13->text()==ui->pushButton19->text()&&
            ui->pushButton19->text()==ui->pushButton25->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW11->setVisible(true);
        ui->labelW11->setPixmap(pixL3.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton1->text().length()>0&&
            ui->pushButton1->text()==ui->pushButton2->text()&&
            ui->pushButton2->text()==ui->pushButton3->text()&&
            ui->pushButton3->text()==ui->pushButton4->text()&&
            ui->pushButton4->text()==ui->pushButton5->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW6->setVisible(true);
        ui->labelW6->setPixmap(pixL1.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton6->text().length()>0&&
            ui->pushButton6->text()==ui->pushButton7->text()&&
            ui->pushButton7->text()==ui->pushButton8->text()&&
            ui->pushButton8->text()==ui->pushButton9->text()&&
            ui->pushButton9->text()==ui->pushButton10->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW7->setVisible(true);
        ui->labelW7->setPixmap(pixL1.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton11->text().length()>0&&
            ui->pushButton11->text()==ui->pushButton12->text()&&
            ui->pushButton12->text()==ui->pushButton13->text()&&
            ui->pushButton13->text()==ui->pushButton14->text()&&
            ui->pushButton14->text()==ui->pushButton15->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW8->setVisible(true);
        ui->labelW8->setPixmap(pixL1.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton16->text().length()>0&&
            ui->pushButton16->text()==ui->pushButton17->text()&&
            ui->pushButton17->text()==ui->pushButton18->text()&&
            ui->pushButton18->text()==ui->pushButton19->text()&&
            ui->pushButton19->text()==ui->pushButton20->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW9->setVisible(true);
        ui->labelW9->setPixmap(pixL1.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton21->text().length()>0&&
            ui->pushButton21->text()==ui->pushButton22->text()&&
            ui->pushButton22->text()==ui->pushButton23->text()&&
            ui->pushButton23->text()==ui->pushButton24->text()&&
            ui->pushButton24->text()==ui->pushButton25->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW10->setVisible(true);
        ui->labelW10->setPixmap(pixL1.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton1->text().length()>0&&
            ui->pushButton1->text()==ui->pushButton6->text()&&
            ui->pushButton6->text()==ui->pushButton11->text()&&
            ui->pushButton11->text()==ui->pushButton16->text()&&
            ui->pushButton16->text()==ui->pushButton21->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW1->setVisible(true);
        ui->labelW1->setPixmap(pixL2.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton2->text().length()>0&&
            ui->pushButton2->text()==ui->pushButton7->text()&&
            ui->pushButton7->text()==ui->pushButton12->text()&&
            ui->pushButton12->text()==ui->pushButton17->text()&&
            ui->pushButton17->text()==ui->pushButton22->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW2->setVisible(true);
        ui->labelW2->setPixmap(pixL2.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton3->text().length()>0&&
            ui->pushButton3->text()==ui->pushButton8->text()&&
            ui->pushButton8->text()==ui->pushButton13->text()&&
            ui->pushButton13->text()==ui->pushButton18->text()&&
            ui->pushButton18->text()==ui->pushButton23->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW3->setVisible(true);
        ui->labelW3->setPixmap(pixL2.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton4->text().length()>0&&
            ui->pushButton4->text()==ui->pushButton9->text()&&
            ui->pushButton9->text()==ui->pushButton14->text()&&
            ui->pushButton14->text()==ui->pushButton19->text()&&
            ui->pushButton19->text()==ui->pushButton24->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW4->setVisible(true);
        ui->labelW4->setPixmap(pixL2.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton5->text().length()>0&&
            ui->pushButton5->text()==ui->pushButton10->text()&&
            ui->pushButton10->text()==ui->pushButton15->text()&&
            ui->pushButton15->text()==ui->pushButton20->text()&&
            ui->pushButton20->text()==ui->pushButton25->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW5->setVisible(true);
        ui->labelW5->setPixmap(pixL2.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");

        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }
        resultTable();
    }
    if(     ui->pushButton5->text().length()>0&&
            ui->pushButton5->text()==ui->pushButton9->text()&&
            ui->pushButton9->text()==ui->pushButton13->text()&&
            ui->pushButton13->text()==ui->pushButton17->text()&&
            ui->pushButton17->text()==ui->pushButton21->text())
    {
        c = 1;
        ui->labelWin->setVisible(true);
        ui->labelW12->setVisible(true);
        ui->labelW12->setPixmap(pixL4.scaled(w,h,Qt::KeepAspectRatio));
        if(currentP==2)
        {
            ui->labelWin->setStyleSheet("color:green;");
            ui->labelWin->setText(name1 + " won 👑");
        }
        else
        {
            ui->labelWin->setStyleSheet("color:red;");
            ui->labelWin->setText(name2 + " won 👑");
        }


        resultTable();
    }

    if(c == 1)
    {
        if(round >= 2)
        {
           ui->pushButtonStart->setVisible(false);
           ui->pushButtonReset->setVisible(true);
        }
        round++;
    ui->labelX->setText("");
    ui->labelT->setText("Game Over ...");
    ui->pushButton1->setEnabled(false);
    ui->pushButton2->setEnabled(false);
    ui->pushButton3->setEnabled(false);
    ui->pushButton4->setEnabled(false);
    ui->pushButton5->setEnabled(false);
    ui->pushButton6->setEnabled(false);
    ui->pushButton7->setEnabled(false);
    ui->pushButton8->setEnabled(false);
    ui->pushButton9->setEnabled(false);
    ui->pushButton10->setEnabled(false);
    ui->pushButton11->setEnabled(false);
    ui->pushButton12->setEnabled(false);
    ui->pushButton13->setEnabled(false);
    ui->pushButton14->setEnabled(false);
    ui->pushButton15->setEnabled(false);
    ui->pushButton16->setEnabled(false);
    ui->pushButton17->setEnabled(false);
    ui->pushButton18->setEnabled(false);
    ui->pushButton19->setEnabled(false);
    ui->pushButton20->setEnabled(false);
    ui->pushButton21->setEnabled(false);
    ui->pushButton22->setEnabled(false);
    ui->pushButton23->setEnabled(false);
    ui->pushButton24->setEnabled(false);
    ui->pushButton25->setEnabled(false);
    }
}
int w1 = 0;
int w2 = 0;
int l1 = 0;
int l2 = 0;
int d = 0;
void MainWindow::resultTable()
{
    QString name1 = ui->lineEditP1->text();
    QString name2 = ui->lineEditP2->text();



    if(ui->labelWin->text()==name1 + " won 👑")
    {
        if(soundClick==0)
        {
           QSound::play(":/resources/Sounds/winningSound.wav");
        }
        ui->groupBoxYN->setVisible(true);
        w1++;
        l2++;
    }
    else if(ui->labelWin->text()==name2 + " won 👑")
    {
        if(soundClick==0)
        {
           QSound::play(":/resources/Sounds/winningSound.wav");
        }
        ui->groupBoxYN->setVisible(true);
        w2++;
        l1++;
    }
    else if(ui->labelWin->text()=="Draw 🤝")
    {
        ui->groupBoxYN->setVisible(true);
        d++;
    }
    QString W1 = QString::number(w1);
    QString W2 = QString::number(w2);
    QString L1 = QString::number(l1);
    QString L2 = QString::number(l2);
    QString D = QString::number(d);
    ui->lineM1P1->setText(W1);
    ui->lineM1P2->setText(W2);
    ui->lineM2P1->setText(L1);
    ui->lineM2P2->setText(L2);
    ui->lineM3P1->setText(D);
    ui->lineM3P2->setText(D);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::validation()
{
    if(val1 == 1 && val2 == 1)
    {
        if(ui->lineEditP1->text()==ui->lineEditP2->text())
        {
            ui->labelError->setVisible(true);
            ui->pushButtonStart->setEnabled(false);
        }
        else
        {
        ui->pushButtonStart->setEnabled(true);
        ui->labelError->setVisible(false);
        }
    }
}

void MainWindow::on_lineEditP1_textChanged(const QString &arg1)
{
    if(ui->lineEditP1->text().length()>0)
    {

        val1 = 1;
    }
    else if(ui->lineEditP1->text()==0 || ui->lineEditP1->text()=="")
    {
        ui->pushButtonStart->setEnabled(false);
        val1 = 0;
    }

    validation();
}

void MainWindow::on_lineEditP2_textChanged(const QString &arg1)
{
    if(ui->lineEditP2->text().length()>0)
    {

        val2 = 1;
    }
    else if(ui->lineEditP2->text()==0 || ui->lineEditP2->text()=="")
    {
        ui->pushButtonStart->setEnabled(false);
        val2 = 0;
    }   

    validation();
}


void MainWindow::soundClilck()
{
    if(soundClick == 0)
    {
        QSound::play(":/resources/Sounds/pushButtonClick1.wav");
    }
}

void MainWindow::on_pushButtonStart_clicked()
{
    QString Name1 = ui->lineEditP1->text();
    QString Name2 = ui->lineEditP2->text();
    ui->labelX->setText(ui->lineEditP1->text());
    ui->pushButtonNewGame->setEnabled(true);
    ui->labelMP1->setText(Name1);
    ui->labelMP2->setText(Name2);
    ui->pushButtonReset->setEnabled(true);
    ui->labelT->setVisible(true);
    ui->labelX->setVisible(true);
    ui->lineEditP1->setEnabled(false);
    ui->lineEditP2->setEnabled(false);
    ui->pushButton1->setEnabled(true);
    ui->pushButton2->setEnabled(true);
    ui->pushButton3->setEnabled(true);
    ui->pushButton4->setEnabled(true);
    ui->pushButton5->setEnabled(true);
    ui->pushButton6->setEnabled(true);
    ui->pushButton7->setEnabled(true);
    ui->pushButton8->setEnabled(true);
    ui->pushButton9->setEnabled(true);
    ui->pushButton10->setEnabled(true);
    ui->pushButton11->setEnabled(true);
    ui->pushButton12->setEnabled(true);
    ui->pushButton13->setEnabled(true);
    ui->pushButton14->setEnabled(true);
    ui->pushButton15->setEnabled(true);
    ui->pushButton16->setEnabled(true);
    ui->pushButton17->setEnabled(true);
    ui->pushButton18->setEnabled(true);
    ui->pushButton19->setEnabled(true);
    ui->pushButton20->setEnabled(true);
    ui->pushButton21->setEnabled(true);
    ui->pushButton22->setEnabled(true);
    ui->pushButton23->setEnabled(true);
    ui->pushButton24->setEnabled(true);
    ui->pushButton25->setEnabled(true);
    ui->pushButtonStart->setEnabled(false);
    ui->pushButtonEdit->setEnabled(true);
}

void MainWindow::on_pushButton1_clicked()
{

    soundClilck();

    if(currentP==1)
    {
        ui->pushButton1->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton1->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton1->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton1->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton1->setEnabled(false);
}


void MainWindow::on_pushButton2_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton2->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton2->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton2->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton2->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton2->setEnabled(false);
}


void MainWindow::on_pushButton3_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton3->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton3->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton3->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton3->setText("O");
    currentP = 1;
    }
    winScreen();

    ui->pushButton3->setEnabled(false);
}


void MainWindow::on_pushButton4_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton4->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton4->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton4->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton4->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton4->setEnabled(false);
}


void MainWindow::on_pushButton5_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton5->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton5->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton5->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton5->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton5->setEnabled(false);
}


void MainWindow::on_pushButton6_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton6->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton6->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton6->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton6->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton6->setEnabled(false);
}


void MainWindow::on_pushButton7_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton7->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton7->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton7->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton7->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton7->setEnabled(false);
}


void MainWindow::on_pushButton8_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton8->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton8->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton8->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton8->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton8->setEnabled(false);
}


void MainWindow::on_pushButton9_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton9->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton9->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton9->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton9->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton9->setEnabled(false);
}


void MainWindow::on_pushButton10_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton10->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton10->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton10->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton10->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton10->setEnabled(false);
}


void MainWindow::on_pushButton11_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton11->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton11->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton11->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton11->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton11->setEnabled(false);
}


void MainWindow::on_pushButton12_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton12->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton12->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton12->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton12->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton12->setEnabled(false);
}


void MainWindow::on_pushButton13_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton13->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton13->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton13->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton13->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton13->setEnabled(false);
}


void MainWindow::on_pushButton14_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton14->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton14->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton14->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton14->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton14->setEnabled(false);
}


void MainWindow::on_pushButton15_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton15->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton15->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton15->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton15->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton15->setEnabled(false);
}


void MainWindow::on_pushButton16_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton16->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton16->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton16->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton16->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton16->setEnabled(false);
}


void MainWindow::on_pushButton17_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton17->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton17->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton17->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton17->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton17->setEnabled(false);
}


void MainWindow::on_pushButton18_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton18->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton18->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton18->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton18->setText("O");
    currentP = 1;
    }
    winScreen();;
    ui->pushButton18->setEnabled(false);
}


void MainWindow::on_pushButton19_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton19->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton19->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton19->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton19->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton19->setEnabled(false);
}


void MainWindow::on_pushButton20_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton20->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton20->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton20->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton20->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton20->setEnabled(false);
}


void MainWindow::on_pushButton21_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton21->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton21->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton21->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton21->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton21->setEnabled(false);
}


void MainWindow::on_pushButton22_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton22->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton22->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton22->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton22->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton22->setEnabled(false);
}


void MainWindow::on_pushButton23_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton23->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton23->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton23->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton23->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton23->setEnabled(false);
}


void MainWindow::on_pushButton24_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton24->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton24->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton24->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton24->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton24->setEnabled(false);
}


void MainWindow::on_pushButton25_clicked()
{
    soundClilck();
    if(currentP==1)
    {
        ui->pushButton25->setStyleSheet("background-color:gray;color:green;");
        ui->labelX->setStyleSheet("color:red;");
        ui->labelX->setText(ui->lineEditP2->text());
    ui->pushButton25->setText("X");
    currentP = 2;
    }
    else
    {
        ui->pushButton25->setStyleSheet("background-color:gray;color:red;");
        ui->labelX->setStyleSheet("color:green;");
        ui->labelX->setText(ui->lineEditP1->text());
        ui->pushButton25->setText("O");
    currentP = 1;
    }
    winScreen();
    ui->pushButton25->setEnabled(false);

}

//this is named (hidden)Start button in ui
void MainWindow::on_pushButtonReset_clicked()
{
    currentP = 1;
    i = 0;
    c = 0;

    ui->labelX->setText(ui->lineEditP1->text());
    ui->labelX->setStyleSheet("color:green;");
    ui->labelWin->setVisible(false);
    ui->pushButton1->setEnabled(true);
    ui->pushButton2->setEnabled(true);
    ui->pushButton3->setEnabled(true);
    ui->pushButton4->setEnabled(true);
    ui->pushButton5->setEnabled(true);
    ui->pushButton6->setEnabled(true);
    ui->pushButton7->setEnabled(true);
    ui->pushButton8->setEnabled(true);
    ui->pushButton9->setEnabled(true);
    ui->pushButton10->setEnabled(true);
    ui->pushButton11->setEnabled(true);
    ui->pushButton12->setEnabled(true);
    ui->pushButton13->setEnabled(true);
    ui->pushButton14->setEnabled(true);
    ui->pushButton15->setEnabled(true);
    ui->pushButton16->setEnabled(true);
    ui->pushButton17->setEnabled(true);
    ui->pushButton18->setEnabled(true);
    ui->pushButton19->setEnabled(true);
    ui->pushButton20->setEnabled(true);
    ui->pushButton21->setEnabled(true);
    ui->pushButton22->setEnabled(true);
    ui->pushButton23->setEnabled(true);
    ui->pushButton24->setEnabled(true);
    ui->pushButton25->setEnabled(true);
    ui->pushButton1->setText("");
    ui->pushButton2->setText("");
    ui->pushButton3->setText("");
    ui->pushButton4->setText("");
    ui->pushButton5->setText("");
    ui->pushButton6->setText("");
    ui->pushButton7->setText("");
    ui->pushButton8->setText("");
    ui->pushButton9->setText("");
    ui->pushButton10->setText("");
    ui->pushButton11->setText("");
    ui->pushButton12->setText("");
    ui->pushButton13->setText("");
    ui->pushButton14->setText("");
    ui->pushButton15->setText("");
    ui->pushButton16->setText("");
    ui->pushButton17->setText("");
    ui->pushButton18->setText("");
    ui->pushButton19->setText("");
    ui->pushButton20->setText("");
    ui->pushButton21->setText("");
    ui->pushButton22->setText("");
    ui->pushButton23->setText("");
    ui->pushButton24->setText("");
    ui->pushButton25->setText("");
    ui->labelWin->setText("");
    ui->pushButton1->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton2->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton3->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton4->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton5->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton6->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton7->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton8->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton9->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton10->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton11->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton12->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton13->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton14->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton15->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton16->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton17->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton18->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton19->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton20->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton21->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton22->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton23->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton24->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton25->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton1->setText("1");
    ui->pushButton2->setText("2");
    ui->pushButton3->setText("3");
    ui->pushButton4->setText("4");
    ui->pushButton5->setText("5");
    ui->pushButton6->setText("6");
    ui->pushButton7->setText("7");
    ui->pushButton8->setText("8");
    ui->pushButton9->setText("9");
    ui->pushButton10->setText("10");
    ui->pushButton11->setText("11");
    ui->pushButton12->setText("12");
    ui->pushButton13->setText("13");
    ui->pushButton14->setText("14");
    ui->pushButton15->setText("15");
    ui->pushButton16->setText("16");
    ui->pushButton17->setText("17");
    ui->pushButton18->setText("18");
    ui->pushButton19->setText("19");
    ui->pushButton20->setText("20");
    ui->pushButton21->setText("21");
    ui->pushButton22->setText("22");
    ui->pushButton23->setText("23");
    ui->pushButton24->setText("24");
    ui->pushButton25->setText("25");
    ui->groupBoxYN->setVisible(false);
    ui->pushButtonReset->setVisible(false);
    ui->pushButtonReset->setEnabled(true);
    ui->pushButtonStart->setVisible(true);
    ui->radioButtonNo->setChecked(true);
    ui->labelT->setText("It's your turn,");
    ui->labelW1->setVisible(false);
    ui->labelW2->setVisible(false);
    ui->labelW3->setVisible(false);
    ui->labelW4->setVisible(false);
    ui->labelW5->setVisible(false);
    ui->labelW6->setVisible(false);
    ui->labelW7->setVisible(false);
    ui->labelW8->setVisible(false);
    ui->labelW9->setVisible(false);
    ui->labelW10->setVisible(false);
    ui->labelW11->setVisible(false);
    ui->labelW12->setVisible(false);
    ui->radioButtonYes->setChecked(true);
}

//this is called Reset button in ui
void MainWindow::on_pushButtonNewGame_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this,"Warning","Reseting will erase everything\n are you sure ?",
                         QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
    currentP = 1;
    i = 0;
    c = 0;
    w1 = 0;
    w2 = 0;
    l1 = 0;
    l2 = 0;
    round = 1;
    ui->labelMP1->setText("Player 1");
    ui->labelMP2->setText("Player 2");
    ui->labelWin->setVisible(false);
    ui->labelX->setText(ui->lineEditP1->text());
    ui->labelX->setStyleSheet("color:green;");
    ui->labelT->setVisible(false);
    ui->labelX->setVisible(false);
    ui->labelError->setVisible(false);
    ui->pushButtonReset->setEnabled(false);
    ui->pushButton1->setEnabled(false);
    ui->pushButton2->setEnabled(false);
    ui->pushButton3->setEnabled(false);
    ui->pushButton4->setEnabled(false);
    ui->pushButton5->setEnabled(false);
    ui->pushButton6->setEnabled(false);
    ui->pushButton7->setEnabled(false);
    ui->pushButton8->setEnabled(false);
    ui->pushButton9->setEnabled(false);
    ui->pushButton10->setEnabled(false);
    ui->pushButton11->setEnabled(false);
    ui->pushButton12->setEnabled(false);
    ui->pushButton13->setEnabled(false);
    ui->pushButton14->setEnabled(false);
    ui->pushButton15->setEnabled(false);
    ui->pushButton16->setEnabled(false);
    ui->pushButton17->setEnabled(false);
    ui->pushButton18->setEnabled(false);
    ui->pushButton19->setEnabled(false);
    ui->pushButton20->setEnabled(false);
    ui->pushButton21->setEnabled(false);
    ui->pushButton22->setEnabled(false);
    ui->pushButton23->setEnabled(false);
    ui->pushButton24->setEnabled(false);
    ui->pushButton25->setEnabled(false);
    ui->lineEditP2->setText("");
    ui->lineEditP1->setText("");
    ui->lineEditP2->setEnabled(true);
    ui->lineEditP1->setEnabled(true);
    ui->pushButtonStart->setEnabled(false);
    ui->labelWin->setText("");
    ui->lineM1P1->setText("0");
    ui->lineM1P2->setText("0");
    ui->lineM2P1->setText("0");
    ui->lineM2P2->setText("0");
    ui->lineM3P1->setText("0");
    ui->lineM3P2->setText("0");
    ui->pushButtonEdit->setEnabled(false);
    ui->pushButton1->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton2->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton3->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton4->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton5->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton6->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton7->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton8->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton9->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton10->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton11->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton12->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton13->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton14->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton15->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton16->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton17->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton18->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton19->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton20->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton21->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton22->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton23->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton24->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton25->setStyleSheet("background-color: rgb(170, 255, 255);");
    ui->pushButton1->setText("1");
    ui->pushButton2->setText("2");
    ui->pushButton3->setText("3");
    ui->pushButton4->setText("4");
    ui->pushButton5->setText("5");
    ui->pushButton6->setText("6");
    ui->pushButton7->setText("7");
    ui->pushButton8->setText("8");
    ui->pushButton9->setText("9");
    ui->pushButton10->setText("10");
    ui->pushButton11->setText("11");
    ui->pushButton12->setText("12");
    ui->pushButton13->setText("13");
    ui->pushButton14->setText("14");
    ui->pushButton15->setText("15");
    ui->pushButton16->setText("16");
    ui->pushButton17->setText("17");
    ui->pushButton18->setText("18");
    ui->pushButton19->setText("19");
    ui->pushButton20->setText("20");
    ui->pushButton21->setText("21");
    ui->pushButton22->setText("22");
    ui->pushButton23->setText("23");
    ui->pushButton24->setText("24");
    ui->pushButton25->setText("25");
    ui->labelT->setText("It's your turn,");
    ui->pushButtonNewGame->setEnabled(false);
    ui->groupBoxYN->setVisible(false);
    ui->radioButtonNo->setChecked(true);
    ui->pushButtonReset->setVisible(false);
    ui->labelError->setVisible(false);
    ui->pushButtonConfirm->setVisible(false);
    ui->pushButtonEdit->setVisible(true);
    ui->lineM1P1->setEnabled(false);
    ui->lineM1P2->setEnabled(false);
    ui->lineM2P1->setEnabled(false);
    ui->lineM2P2->setEnabled(false);
    ui->lineM3P1->setEnabled(false);
    ui->lineM3P2->setEnabled(false);
    ui->pushButtonStart->setVisible(true);
    ui->labelW1->setVisible(false);
    ui->labelW2->setVisible(false);
    ui->labelW3->setVisible(false);
    ui->labelW4->setVisible(false);
    ui->labelW5->setVisible(false);
    ui->labelW6->setVisible(false);
    ui->labelW7->setVisible(false);
    ui->labelW8->setVisible(false);
    ui->labelW9->setVisible(false);
    ui->labelW10->setVisible(false);
    ui->labelW11->setVisible(false);
    ui->labelW12->setVisible(false);
    ui->pushButton1->setVisible(true);
    ui->pushButton2->setVisible(true);
    ui->pushButton3->setVisible(true);
    ui->pushButton4->setVisible(true);
    ui->pushButton5->setVisible(true);
    ui->pushButton6->setVisible(true);
    ui->pushButton7->setVisible(true);
    ui->pushButton8->setVisible(true);
    ui->pushButton9->setVisible(true);
    ui->pushButton10->setVisible(true);
    ui->pushButton11->setVisible(true);
    ui->pushButton12->setVisible(true);
    ui->pushButton13->setVisible(true);
    ui->pushButton14->setVisible(true);
    ui->pushButton15->setVisible(true);
    ui->pushButton16->setVisible(true);
    ui->pushButton17->setVisible(true);
    ui->pushButton18->setVisible(true);
    ui->pushButton19->setVisible(true);
    ui->pushButton20->setVisible(true);
    ui->pushButton21->setVisible(true);
    ui->pushButton22->setVisible(true);
    ui->pushButton23->setVisible(true);
    ui->pushButton24->setVisible(true);
    ui->pushButton25->setVisible(true);
    ui->line_1->setVisible(true);
    ui->line_2->setVisible(true);
    ui->line_3->setVisible(true);
    ui->line_4->setVisible(true);
    ui->line_5->setVisible(true);
    ui->line_6->setVisible(true);
    ui->line_7->setVisible(true);
    ui->line_8->setVisible(true);
    ui->groupBoxName->setVisible(true);
    ui->radioButtonYes->setChecked(true);
    ui->pushButtonReset->setEnabled(true);
    ui->pushButtonNewGame->setVisible(true);
    ui->pushButtonEdit->setVisible(true);
    ui->pushButtonStart->setVisible(true);


    this->move(0,0);
    this->resize(1132,752);
    ui->frame->move(790,230);
  }
}


void MainWindow::on_pushButtonExit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this,"Warning","Are you sure you want to exit ?",
                         QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        close();
    }
}


void MainWindow::on_pushButtonEdit_clicked()
{
    ui->lineM1P1->setEnabled(true);
    ui->lineM1P2->setEnabled(true);
    ui->lineM2P1->setEnabled(true);
    ui->lineM2P2->setEnabled(true);
    ui->lineM3P1->setEnabled(true);
    ui->lineM3P2->setEnabled(true);
    ui->pushButtonConfirm->setVisible(true);
    ui->pushButtonEdit->setEnabled(false);
    ui->pushButtonEdit->setVisible(false);
}


void MainWindow::on_pushButtonConfirm_clicked()
{
    ui->lineM1P1->setEnabled(false);
    ui->lineM1P2->setEnabled(false);
    ui->lineM2P1->setEnabled(false);
    ui->lineM2P2->setEnabled(false);
    ui->lineM3P1->setEnabled(false);
    ui->lineM3P2->setEnabled(false);
    ui->pushButtonEdit->setEnabled(true);
    ui->pushButtonConfirm->setVisible(false);
    ui->pushButtonEdit->setVisible(true);
}




void MainWindow::on_radioButtonYes_clicked()
{
    ui->pushButtonStart->setVisible(false);
    ui->pushButtonReset->setVisible(true);
}


void MainWindow::on_radioButtonNo_clicked()
{
    ui->pushButtonStart->setVisible(true);
    ui->pushButtonReset->setVisible(false);
    finalChart();
}


void MainWindow::on_lineM1P1_textChanged(const QString &arg1)
{
    ui->lineM2P2->setText(ui->lineM1P1->text());
    QString W1 = ui->lineM1P1->text();
    w1 = W1.toInt();
    l2 = w1;
}


void MainWindow::on_lineM1P2_textChanged(const QString &arg1)
{
    ui->lineM2P1->setText(ui->lineM1P2->text());
    QString W2 = ui->lineM1P2->text();
    w2 = W2.toInt();
    l1 = w2;
}


void MainWindow::on_lineM3P1_textChanged(const QString &arg1)
{
    ui->lineM3P2->setText(ui->lineM3P1->text());
    QString D = ui->lineM3P1->text();
    d = D.toInt();

}


void MainWindow::on_lineM3P2_textChanged(const QString &arg1)
{
    ui->lineM3P1->setText(ui->lineM3P2->text());
    QString D = ui->lineM3P2->text();
    d = D.toInt();
}


void MainWindow::on_lineM2P1_textChanged(const QString &arg1)
{
    ui->lineM1P2->setText(ui->lineM2P1->text());

    QString L1 = ui->lineM2P1->text();
    l1 = L1.toInt();
    w2 = l1;
}


void MainWindow::on_lineM2P2_textChanged(const QString &arg1)
{
    ui->lineM1P1->setText(ui->lineM2P2->text());
    QString L2 = ui->lineM2P2->text();
    l2 = L2.toInt();
    w1 = l2;
}


void MainWindow::on_actionNew_game_triggered()
{
    on_pushButtonNewGame_clicked();
}


void MainWindow::on_actionExit_triggered()
{
    on_pushButtonExit_clicked();
}

void MainWindow::on_actionCredits_triggered()
{
    QMessageBox::information(this,"Credits","by Erfan Ghasemian & Arian Saeedkondori");
}

void MainWindow::finalChart()
{
    ui->pushButton1->setVisible(false);
    ui->pushButton2->setVisible(false);
    ui->pushButton3->setVisible(false);
    ui->pushButton4->setVisible(false);
    ui->pushButton5->setVisible(false);
    ui->pushButton6->setVisible(false);
    ui->pushButton7->setVisible(false);
    ui->pushButton8->setVisible(false);
    ui->pushButton9->setVisible(false);
    ui->pushButton10->setVisible(false);
    ui->pushButton11->setVisible(false);
    ui->pushButton12->setVisible(false);
    ui->pushButton13->setVisible(false);
    ui->pushButton14->setVisible(false);
    ui->pushButton15->setVisible(false);
    ui->pushButton16->setVisible(false);
    ui->pushButton17->setVisible(false);
    ui->pushButton18->setVisible(false);
    ui->pushButton19->setVisible(false);
    ui->pushButton20->setVisible(false);
    ui->pushButton21->setVisible(false);
    ui->pushButton22->setVisible(false);
    ui->pushButton23->setVisible(false);
    ui->pushButton24->setVisible(false);
    ui->pushButton25->setVisible(false);
    ui->line_1->setVisible(false);
    ui->line_2->setVisible(false);
    ui->line_3->setVisible(false);
    ui->line_4->setVisible(false);
    ui->line_5->setVisible(false);
    ui->line_6->setVisible(false);
    ui->line_7->setVisible(false);
    ui->line_8->setVisible(false);
    ui->groupBoxName->setVisible(false);
    ui->labelWin->setVisible(false);
    ui->labelW1->setVisible(false);
    ui->labelW2->setVisible(false);
    ui->labelW3->setVisible(false);
    ui->labelW4->setVisible(false);
    ui->labelW5->setVisible(false);
    ui->labelW6->setVisible(false);
    ui->labelW7->setVisible(false);
    ui->labelW8->setVisible(false);
    ui->labelW9->setVisible(false);
    ui->labelW10->setVisible(false);
    ui->labelW11->setVisible(false);
    ui->labelW12->setVisible(false);
    ui->pushButtonReset->setVisible(false);
    ui->pushButtonNewGame->setVisible(false);
    ui->pushButtonEdit->setVisible(false);
    ui->pushButtonConfirm->setVisible(false);
    ui->groupBoxYN->setVisible(false);
    ui->pushButtonStart->setVisible(false);


    this->move(0,0);
    this->resize(330,250);
    ui->frame->move(0,0);

}


int wall = 0;
void MainWindow::on_pushButtonWall_clicked()
{
    QPixmap pixWall(":/resources/Images/Wallpaper.png");
    QPixmap pixWallDark(":/resources/Images/DarkTheme.png");

    if(wall == 0)
    {
    ui->labelWallpaper->setPixmap(pixWallDark.scaled(1800,1200));
    ui->pushButtonWall->setText("Dark");
    wall = 1;
    }
    else if(wall == 1)
    {
        ui->labelWallpaper->setPixmap(pixWall.scaled(1800,1200));
        ui->pushButtonWall->setText("Light");
        wall = 0;
    }
}



void MainWindow::on_pushButtonMusic_clicked()
{
    if(musicOfforOn==0)
    {
        music->setMuted(true);
        musicOfforOn = 1;
        ui->pushButtonMusic->setText("Muted");
    }
    else if(musicOfforOn==1)
    {
        music->setMuted(false);
        musicOfforOn = 0;
        ui->pushButtonMusic->setText("On");
    }
}


void MainWindow::on_pushButtonSoundEffects_clicked()
{
    if(soundClick==0)
    {
        soundClick = 1;
        ui->pushButtonSoundEffects->setText("Muted");
    }
    else if(soundClick==1)
    {
        soundClick = 0;
        ui->pushButtonSoundEffects->setText("On");
    }
}

