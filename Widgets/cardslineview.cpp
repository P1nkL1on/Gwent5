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
    installEventFilter(this);
    setMouseTracking(true);
}

bool CardsLineView::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::Resize) {
        auto *er = static_cast<QResizeEvent *>(e);
        const int width = widthByHeight(er->size().height());
        setFixedWidth(width);
        return true;
    }

    const bool isPress = e->type() == QEvent::MouseButtonPress;
    const bool isMove = e->type() == QEvent::MouseMove;
    if (!isPress && !isMove)
        return QWidget::eventFilter(o, e);

    auto *em = static_cast<QMouseEvent *>(e);
    const QPoint pos = em->pos();
    const QRect _rect = parentWidget()->contentsRect();

    const int id = [=]{
        for (size_t i = 0; i < _views.size(); ++i) {
            const double height = _rect.height();
            const double width = _aspectRatio * height;
            const QRectF rectCard((width + _spacing) * i, 0, width, height);
            if (rectCard.contains(pos))
                return _views[i].id;
        }
        return -1;
    }();

    if (id != _id) {
        if (isMove)
            emit hovered(id);
        if (isPress)
            emit clicked(id);
        _id = id;
    }
    return QWidget::eventFilter(o, e);
}

void CardsLineView::paintEvent(QPaintEvent *e)
{
    const QRect _rect = e->rect();
    QPainter painter(this);
    painter.fillRect(_rect, Qt::white);

    if (_views.size() == 0)
        return;

    for (size_t i = 0; i < _views.size(); ++i) {
        const double height = _rect.height();
        const double width = _aspectRatio * height;
        const QRectF rectCard((width + _spacing) * i, 0, width, height);
        paintCard(painter, _resourceManager, {}, _views[i], _choice, rectCard);
        paintTextInPoint(painter, {}, QString::number(rectCard.left()), rectCard.topLeft(), Qt::white, Qt::black);
    }
}

int CardsLineView::widthByHeight(const int height) const
{
    const double width = _aspectRatio * height * int(_views.size()) + _spacing * (int(_views.size()) - 1);
    return int(width);
}
