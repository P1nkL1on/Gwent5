#include "cardslineview.h"

#include <QPaintEvent>
#include <QtDebug>

#include "../Widgets/resourcemanager.h"
#include "../Widgets/cardspainting.h"

CardsLineView::CardsLineView(ResourceManager *resourceManager, const std::vector<CardView> &views, const ChoiceView &choice, const Qt::Orientation orientation, const int nLines, QWidget *parent) :
    QWidget(parent),
    _resourceManager(resourceManager),
    _views(views),
    _choice(choice),
    _orientation(orientation),
    _nLines(nLines)
{
    QObject::connect(resourceManager, &ResourceManager::imageRequestSucceed, this, static_cast<void (CardsLineView::*)()>(&CardsLineView::update));
    installEventFilter(this);
    setMouseTracking(true);
}

void CardsLineView::setCardAndChoiceViews(const std::vector<CardView> &views, const ChoiceView &choice)
{
    _views = views;
    _choice = choice;

    updateSize(rect().size());
    update();
}

bool CardsLineView::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::Resize && _views.size()) {
        auto *er = static_cast<QResizeEvent *>(e);
        updateSize(er->size());
        return true;
    }

    const bool isPress = e->type() == QEvent::MouseButtonRelease;
    const bool isMove = e->type() == QEvent::MouseMove;
    if (!isPress && !isMove)
        return QWidget::eventFilter(o, e);

    auto *em = static_cast<QMouseEvent *>(e);
    const QPoint pos = em->pos();
    const QRect _rect = parentWidget()->contentsRect();

    const int id = [=]{
        for (size_t i = 0; i < _views.size(); ++i) {
            if (_orientation == Qt::Horizontal) {
                const double height = _rect.height();
                const double width = _aspectRatio * height;
                const QRectF rectCard((width + _spacing) * i, 0, width, height);
                if (rectCard.contains(pos))
                    return _views[i].id;
            } else if (_orientation == Qt::Vertical) {
                const int x = int(i) % _nLines;
                const int y = int(i) / _nLines;
                const double width = (_rect.width() - (_nLines - 1) * _spacing) / double(_nLines);
                const double height = width / _aspectRatio;
                const QRectF rectCard((width + _spacing) * x, (height + _spacing) * y, width, height);
                if (rectCard.contains(pos))
                    return _views[i].id;
            } else {
                Q_UNREACHABLE();
            }
        }
        return -1;
    }();

    if (isPress)
        emit clicked(id);

    if (id != _id) {
        if (isMove)
            emit hovered(id);
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
        const QRectF rectCard = [=]{
            if (_orientation == Qt::Horizontal) {
                const double height = _rect.height();
                const double width = _aspectRatio * height;
                return QRectF((width + _spacing) * i, 0, width, height);
            } else if (_orientation == Qt::Vertical) {
                const int x = int(i) % _nLines;
                const int y = int(i) / _nLines;
                const double width = (_rect.width() - (_nLines - 1) * _spacing) / double(_nLines);
                const double height = width / _aspectRatio;
                return QRectF((width + _spacing) * x, (height + _spacing) * y, width, height);
            }
            Q_UNREACHABLE();
        }();
        paintCard(painter, _resourceManager, {}, _views[i], _choice, rectCard, false);
    }
}

void CardsLineView::updateSize(const QSize &size)
{
    const int nTuples = int(std::ceil(_views.size() / double(_nLines)));
    if (_orientation == Qt::Horizontal) {
        const double height = size.height();
        const double width = _aspectRatio * height * nTuples + _spacing * (nTuples - 1);
        setFixedWidth(int(width));
        return;
    } else if (_orientation == Qt::Vertical) {
        const double width = (size.width() - (_nLines - 1) * _spacing) / double(_nLines);
        const double height = width / _aspectRatio * nTuples + _spacing * (nTuples - 1);
        setFixedHeight(int(height));
        return;
    }
    Q_UNREACHABLE();
}

Qt::Orientation CardsLineView::orientation() const
{
    return _orientation;
}
