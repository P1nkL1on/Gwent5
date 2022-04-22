#ifndef CARDSLINEVIEW_H
#define CARDSLINEVIEW_H

#include <QWidget>

#include "cardspainting.h"

class CardsLineView : public QWidget
{
    Q_OBJECT
public:
    explicit CardsLineView(
            ResourceManager *resourceManager,
            const std::vector<CardView> &views,
            const ChoiceView &choice,
            QWidget *parent = nullptr);

private:
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *e) override;

    ResourceManager *_resourceManager = nullptr;
    std::vector<CardView> _views;
    ChoiceView _choice;
    int _spacing = 10;
    double _aspectRation = 650.0 / 816;
};

#endif // CARDSLINEVIEW_H
