#include "cardsingleview.h"

#include <QPaintEvent>

CardSingleView::CardSingleView(ResourceManager *resourceManager, const CardView &view, QWidget *parent) :
    QWidget(parent),
    _resourceManager(resourceManager),
    _view(view)
{
}

void CardSingleView::setCardView(const CardView &view)
{
    _view = view;

    update();
}

void CardSingleView::paintEvent(QPaintEvent *e)
{
    const QRect _rect = e->rect();
    QPainter painter(this);
    painter.fillRect(_rect, Qt::white);
    if (_view.id < 0)
        return;

    const double width = _rect.width();
    const double height = width / _aspectRatio;
    const QRectF rectCard(0, 0, width, height);
    paintCardLarge(painter, _resourceManager, _view, rectCard);

    QString tags;
    for (const Tag tag : _view.tags)
        tags += (tags.isEmpty() ? "" : ", ") + QString::fromStdString(stringTag(tag));

    const QStringList infos {
        QString("Name: %1").arg(QString::fromStdString(_view.name)),
        QString("Faction: %1").arg(QString::fromStdString(stringTag(Tag(_view.faction)))),
        QString("Tags: %1").arg(tags),
        _view.powerBase ? QString("Power = %1").arg(_view.power) : QString("Special"),
        QString("Text: %1").arg(QString::fromStdString(_view.text)),
    };

    double offsetVertical = 0;
    for (const QString &info : infos){
        QRectF rectRes;
        paintTextInPoint(painter, {}, info, rectCard.bottomLeft() + QPointF(0, offsetVertical), Qt::white, Qt::black, _rect.width(), &rectRes);
        offsetVertical += rectRes.height();
    }
}
