#include <QtMultimedia>
#include <QtMultimediaWidgets>

#include <QGraphicsView>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QMediaPlayer *player = new QMediaPlayer();
  player->setMedia(QUrl::fromLocalFile("/home/zuka/qt5/sample.mp4"));

  QGraphicsVideoItem *item = new QGraphicsVideoItem;
  player->setVideoOutput(item);

  QGraphicsView *view = new QGraphicsView;
  QGraphicsScene* scene = new QGraphicsScene(view);
  view->setScene(scene);

  // Video
  scene->addItem(item);

  // Text
  scene->addText("Hello! This is a test program of QGraphicsVideoItem");

  // Image
  QImage image("/home/zuka/qt5/sample.png");
  image = image.convertToFormat(QImage::Format_ARGB32);
  for (int x = 0, width = image.width(); x < width; ++x) {
    for (int y = 0, height = image.height(); y < height; ++y) {
      QColor color(image.pixel(x, y));
      color.setAlpha(128);
      image.setPixel(x, y, color.rgba());
    }
  }

  QPixmap pixmap = QPixmap::fromImage(image);
  pixmap.scaled(350, 350, Qt::KeepAspectRatio);
  QGraphicsPixmapItem *g_item = new QGraphicsPixmapItem(pixmap);
  scene->addItem(g_item);

  view->resize(400, 400);
  view->show();
  player->play();

  return app.exec();
}
