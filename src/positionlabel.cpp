#include "positionlabel.h"

#include <QMouseEvent>

PositionLabel::PositionLabel(QWidget *parent, Qt::WindowFlags f) : QLabel(parent, f) {
}

PositionLabel::PositionLabel(const QString &text, QWidget *parent, Qt::WindowFlags f) : QLabel(text, parent, f) {
}

PositionLabel::~PositionLabel() {
}

void PositionLabel::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    emit checkAreaDirectionEvent(event->pos());
}
