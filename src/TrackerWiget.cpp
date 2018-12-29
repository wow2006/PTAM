#include <QPainter>

#include <Eigen/Eigen>

#include "GUI/TrackerWiget.hpp"


namespace GUI {

Tracker::Tracker(QWidget *parent) : QWidget{parent} {}

Tracker::~Tracker() {}

void Tracker::addFrame(const uchar *data, const uint width, const uint height,
                       const uint channels) {
}

void Tracker::paintEvent(QPaintEvent* paintEvent) {
  QPainter painter(this);
}

} // namespace GUI
