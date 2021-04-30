#include "bestqtplayer.h"
#include "ui_bestqtplayer.h"

BestQtPlayer::BestQtPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BestQtPlayer)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);

    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::durationChanged, bar, &QProgressBar::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, bar, &QProgressBar::setValue);
}

BestQtPlayer::~BestQtPlayer()
{
    delete ui;
}


void BestQtPlayer::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "open a File", "", "VideoFile (*.*)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}

void BestQtPlayer::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}

void BestQtPlayer::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Paused...");
}

void BestQtPlayer::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped");
}
