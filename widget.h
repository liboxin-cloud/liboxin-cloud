#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE
class QAudioOutput;
class QMediaPlayer;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonPause_clicked();

    void on_pushButtonFore_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QList<QUrl>PlayList;//播放列表
    int CurrentPlayIndex=0;
    QAudioOutput* AudioOutput;
    QMediaPlayer* MediaPlayer;

};
#endif // WIDGET_H
