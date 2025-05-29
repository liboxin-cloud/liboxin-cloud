#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QDir>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QUrl>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QIcon icon; // 创建一个图标对象
    icon.addFile("://logo.ico"); // 给图标对象设置一个图标
    setWindowIcon(icon); // 把图标对象设置为该窗口的图标
    ui->setupUi(this);
    this->setFixedSize(390,670);
    AudioOutput=new QAudioOutput(this);
    MediaPlayer= new QMediaPlayer(this);
    MediaPlayer->setAudioOutput(AudioOutput);
    //MediaPlayer->setSource(QUrl::fromLocalFile("D:/音乐/sky.mp3"));
    //MediaPlayer->play();

    //获取当前媒体的时长，通过信号和槽来获取
    connect(MediaPlayer,&QMediaPlayer::durationChanged,this,[=](qint64 duration)
    {
        ui->labelTotal->setText(QString("%1:%2").arg(duration/1000/60,2,10,QChar('0')).arg((duration/1000)%60,2,10,QChar('0')));
        ui->horizontalSlider->setRange(0,duration);

    });
    //获取当前时长
    connect(MediaPlayer,&QMediaPlayer::positionChanged,this,[=](qint64 pos)
    {
        ui->labelCurrent->setText(QString("%1:%2").arg(pos/1000/60,2,10,QChar('0')).arg((pos/1000)%60,2,10,QChar('0')));
        ui->horizontalSlider->setValue(pos);
    });
    //让进度滑块动起来
    //拖动滑块，让音乐播放进度改变
    connect(ui->horizontalSlider,&QSlider::sliderMoved,MediaPlayer,&QMediaPlayer::setPosition);
    AudioOutput->setVolume(1);

    QObject::connect(ui->horizontalSliderVolume,&QSlider::valueChanged,this,[=](int value)
    {
        AudioOutput->setVolume(value/100.0);
    }
    );





}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonOpen_clicked()
{
    auto FilePath=QFileDialog::getExistingDirectory(this,"请选择音乐所在的目录","D:\\音乐");
    QDir dir(FilePath);
    auto MusicList=dir.entryList(QStringList()<<"*.mp3"<<"*.wav");
    ui->listWidget->addItems(MusicList);

    ui->listWidget->setCurrentRow(0);

    for(auto file:MusicList)
    {
        PlayList.append(QUrl::fromLocalFile(FilePath+"/"+file));
    }
}


void Widget::on_pushButtonPause_clicked()
{
    if(PlayList.empty())
    {
        return;
    }
    switch(MediaPlayer->playbackState())
    {
    case QMediaPlayer::PlaybackState::StoppedState:
    {
        CurrentPlayIndex=ui->listWidget->currentRow();
        MediaPlayer->setSource(PlayList[CurrentPlayIndex]);
        MediaPlayer->play();
        ui->pushButtonPause->setText("暂停");
        break;
    }

    case QMediaPlayer::PlaybackState::PlayingState:
    {
        MediaPlayer->pause();
        ui->pushButtonPause->setText("播放");
        break;
    }
    case QMediaPlayer::PlaybackState::PausedState:
    {
        MediaPlayer->play();
        ui->pushButtonPause->setText("暂停");
        break;

    }

    }
    //如果没有播放，播放当前选中音乐



}


void Widget::on_pushButtonFore_clicked()
{
    if(PlayList.empty())
    {
        return;
    }
    if(CurrentPlayIndex==0)
    {
        CurrentPlayIndex=PlayList.size()-1;
    }
    else
    {
        CurrentPlayIndex--;
    }
    ui->listWidget->setCurrentRow(CurrentPlayIndex);
    MediaPlayer->setSource(PlayList[CurrentPlayIndex]);
    MediaPlayer->play();
    ui->pushButtonPause->setText("暂停");


}


void Widget::on_pushButton_4_clicked()
{
    if(PlayList.empty())
    {
        return;
    }

    if(CurrentPlayIndex>=PlayList.size()-1)
    {
        CurrentPlayIndex=0;
    }
    else
    {
        CurrentPlayIndex++;
    }
    ui->listWidget->setCurrentRow(CurrentPlayIndex);
    MediaPlayer->setSource(PlayList[CurrentPlayIndex]);
    MediaPlayer->play();
    ui->pushButtonPause->setText("暂停");


}



void Widget::on_listWidget_doubleClicked(const QModelIndex &index)
{
    CurrentPlayIndex=index.row();
    MediaPlayer->setSource(PlayList[CurrentPlayIndex]);
    MediaPlayer->play();
    ui->pushButtonPause->setText("暂停");

}

