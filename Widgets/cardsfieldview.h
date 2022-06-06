#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QWidget>

#include "cardspainting.h"

class CardsFieldView : public QWidget
{
    Q_OBJECT
public:
    explicit CardsFieldView(
            ResourceManager *resourceManager,
            const FieldView &view,
            QWidget *parent = nullptr);

signals:
    void hovered(const int id);
    void clicked(const int id);

private:
    bool eventFilter(QObject *o, QEvent *e) override;
    void paintEvent(QPaintEvent *e) override;
    void updateSize(const QSize &size);
    QRectF cardRect(const Row row, const Pos pos, const int nCardsInRow, const bool isAlly) const;
    int idOfCard(const QPoint pos) const;

    ResourceManager *_resourceManager = nullptr;
    FieldView _view;
    int _id = -1;
    int _spacingCard = 20;
    int _spacingRow = 5;
    int _spacingFields = 10;
    int _diameterCoin = 50;
    int _spacingCoin = 10;
    int _spacingCount = 10;
    int _spacingPowerTotal = 20;
    int _spacingPowerRow = 20;
};

#endif // FIELDVIEW_H
