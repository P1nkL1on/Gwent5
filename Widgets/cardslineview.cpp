#include "cardslineview.h"

#include <QPaintEvent>
#include <QtDebug>

#include "../Widgets/cardspainting.h"

CardsLineView::CardsLineView(ResourceManager *resourceManager, const std::vector<CardView> &views, const ChoiceView &choice, QWidget *parent) :
    QWidget(parent),
    _resourceManager(resourceManager),
    _views(views),
    _choice(choice)
{
    QObject::connect(resourceManager, &ResourceManager::imageRequestSucceed, this, static_cast<void (CardsLineView::*)()>(&CardsLineView::update));
}

QSize CardsLineView::sizeHint() const
{
    if (_views.size() == 0)
        return QWidget::sizeHint();

    const int height = parentWidget()->contentsRect().height();
    const int width = _aspectRation * height * int(_views.size()) + _spacing * (int(_views.size()) - 1);
    const QSize size(width, height);
    qDebug() << size;
    return size;
}

void CardsLineView::paintEvent(QPaintEvent *e)
{
    const QRect rect = e->rect();
    QPainter painter(this);
    painter.fillRect(rect, Qt::white);

    if (_views.size() == 0)
        return;

    for (size_t i = 0; i < _views.size(); ++i) {
        // const QRectF rectCard(i * rect.height() / 4.0 * 3, 0, rect.height() / 4.0 * 2.5, rect.height());
        const double height = rect.height();
        const double width = _aspectRation * height;
        const QRectF rectCard((width + _spacing) * i, 0, width, height);
        paintCard(painter, _resourceManager, {}, _views[i], _choice, rectCard);
    }
}
