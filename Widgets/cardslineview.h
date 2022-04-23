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

signals:
    void hovered(const int id);
    void clicked(const int id);

private:
    bool eventFilter(QObject*, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;
    int widthByHeight(const int height) const;

    ResourceManager *_resourceManager = nullptr;
    std::vector<CardView> _views;
    ChoiceView _choice;
    int _spacing = 10;
    int _id = -1;
    double _aspectRatio = 650.0 / 816;
};

#endif // CARDSLINEVIEW_H
