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
    void paintEvent(QPaintEvent *e) override;

    ResourceManager *_resourceManager = nullptr;
    CardView _view;
    double _aspectRatio = 650.0 / 816;
};

#endif // CARDSINGLEVIEW_H
