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
            const Qt::Orientation orientation,
            const int nLines,
            QWidget *parent = nullptr);
    Qt::Orientation orientation() const;
    void setCardAndChoiceViews(
            const std::vector<CardView> &views,
            const ChoiceView &choice);

signals:
    void hovered(const int id);
    void clicked(const int id);

private:
    bool eventFilter(QObject*, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;
    void updateSize(const QSize &size);

    ResourceManager *_resourceManager = nullptr;
    std::vector<CardView> _views;
    ChoiceView _choice;
    Qt::Orientation _orientation = Qt::Horizontal;
    int _nLines = 1;
    int _spacing = 10;
    int _id = -1;
    double _aspectRatio = 650.0 / 816;
};

#endif // CARDSLINEVIEW_H
