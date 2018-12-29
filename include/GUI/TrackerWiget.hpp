#pragma once
#include <QImage>
#include <QWidget>



namespace GUI {

class Tracker : QWidget {
  Q_OBJECT
public:
  explicit Tracker(QWidget *parent = nullptr);

  ~Tracker() override;

  void addFrame(const uchar *data, const uint width, const uint height,
                const uint channels);

  void paintEvent(QPaintEvent* paintEvent) override;

protected:
  QImage mImage;

};

} // namespace GUI
