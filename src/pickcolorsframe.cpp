#include "pickcolorsframe.h"
#include <QGuiApplication>
#include <QMouseEvent>
#include <QScreen>
PickColorsFrame::PickColorsFrame(QWidget *parent, Qt::WindowFlags f) : QFrame(parent, f) {
}

PickColorsFrame::PickColorsFrame(QFramePrivate &dd, QWidget *parent, Qt::WindowFlags f) : QFrame(dd, parent, f) {
}

void PickColorsFrame::mousePressEvent(QMouseEvent *event) {
    event->accept();
    startRecord = true;
}

void PickColorsFrame::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    startRecord = false;
}

void PickColorsFrame::mouseMoveEvent(QMouseEvent *event) {
    if (startRecord) {
        event->accept();
        // 获取当前鼠标位置
        QPoint cursorPos = QCursor::pos();
        QScreen *screen = QGuiApplication::screenAt(cursorPos);
        // 获取屏幕上的像素颜色
        QPixmap screenshot = screen->grabWindow(0, cursorPos.x(), cursorPos.y(), 1, 1);
        QColor pixelColor = screenshot.toImage().pixel(0, 0);
        emit colorChangeEvent(pixelColor);
    }
}
