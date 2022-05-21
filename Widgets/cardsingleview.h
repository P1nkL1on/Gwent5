#ifndef CARDSINGLEVIEW_H
#define CARDSINGLEVIEW_H

#include <QWidget>

#include "cardspainting.h"

class CardSingleView : public QWidget
{
    Q_OBJECT
public:
    CardSingleView(
            ResourceManager *resourceManager,
            const CardView &view,
            QWidget *parent = nullptr);
    void setCardView(const CardView &view);

private:
    bool eventFilter(QObject*o, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;
    void updateSize(const QSize &size);

    ResourceManager *_resourceManager = nullptr;
    CardView _view;
    double _aspectRatio = 650.0 / 816;
};

#endif // CARDSINGLEVIEW_H
