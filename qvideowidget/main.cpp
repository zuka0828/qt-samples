#include <QtMultimedia>
#include <QtMultimediaWidgets>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QMediaPlayer *player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile("/home/zuka/qt5/sample.mp4"));

	QVideoWidget *videoWidget = new QVideoWidget;
	player->setVideoOutput(videoWidget);

	videoWidget->show();
	videoWidget->resize(300, 300);
	player->play();

	return app.exec();
}
