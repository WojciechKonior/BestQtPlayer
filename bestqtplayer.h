#ifndef BESTQTPLAYER_H
#define BESTQTPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui { class BestQtPlayer; }
QT_END_NAMESPACE

class BestQtPlayer : public QMainWindow
{
    Q_OBJECT

public:
    BestQtPlayer(QWidget *parent = nullptr);
    ~BestQtPlayer();

private slots:

    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

private:
    Ui::BestQtPlayer *ui;
    QMediaPlayer *player;
    QVideoWidget *vw;
    QProgressBar *bar;
    QSlider *slider;
};
#endif // BESTQTPLAYER_H
