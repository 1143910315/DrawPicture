#ifndef POSITIONLABEL_H
#define POSITIONLABEL_H

#include <QLabel>

class PositionLabel : public QLabel {
    Q_OBJECT
public:
    explicit PositionLabel(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    explicit PositionLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~PositionLabel();

    // QWidget interface
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:
    void checkAreaDirectionEvent(QPoint point);
};

#endif // POSITIONLABEL_H
