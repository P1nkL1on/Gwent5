#include "cardsingleview.h"

#include <QPaintEvent>

#include "Cards/archieve.h"

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

bool CardSingleView::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::Resize) {
        auto *er = static_cast<QResizeEvent *>(e);
        updateSize(er->size());
    }
    return QWidget::eventFilter(o, e);
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

    QStringList infos {
        QString("Name: %1").arg(QString::fromStdString(_view.name)),
        QString("Faction: %1").arg(QString::fromStdString(stringTag(Tag(_view.faction)))),
        QString("Tags: %1").arg(tags),
        _view.powerBase ? QString("Power = %1").arg(_view.power) : QString("Special"),
        QString("Text: %1").arg(QString::fromStdString(_view.text)),
    };

    for (const auto &it : keywordDescriptions())
        if (_view.text.find(it.first) != std::string::npos)
            infos.append(QString("%1: %2").arg(QString::fromStdString(it.first), QString::fromStdString(it.second)));

    double offsetVertical = 0;
    for (const QString &info : infos){
        QRectF rectRes;
        paintTextInPoint(painter, {}, info, rectCard.bottomLeft() + QPointF(0, offsetVertical), Qt::white, Qt::black, _rect.width(), &rectRes);
        offsetVertical += rectRes.height();
    }
}

void CardSingleView::updateSize(const QSize &size)
{
    const double width = size.width();
    const double height = width / _aspectRatio;
    setFixedHeight(int(height));
}
