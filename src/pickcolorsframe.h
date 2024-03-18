#ifndef PICKCOLORSFRAME_H
#define PICKCOLORSFRAME_H

#include <QFrame>

class PickColorsFrame : public QFrame {
    Q_OBJECT
public:
    explicit PickColorsFrame(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
protected:
    PickColorsFrame(QFramePrivate &dd, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
signals:
    void colorChangeEvent(QColor color);
    void selectColorEndEvent(QColor color);
private:
    bool startRecord = false;
    QColor lastColor;
};

#endif // PICKCOLORSFRAME_H
