#include "cardspainting.h"

void paintCard(QPainter &painter, ResourceManager *resourceManager, const Layout &layout, const CardView &cardView, const ChoiceView &choiceView, const QRectF &rect)
{
    Q_ASSERT(!cardView.isAmbush);
    painter.setPen(Qt::black);
    painter.drawRect(rect);

    const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(layout.borderCardPx, layout.borderCardPx, layout.borderCardPx, layout.borderCardPx));

    /// draw url image
    if (cardView.url.size() > 0) {
        const QString url = QString::fromStdString(cardView.url);
        resourceManager->requestImageByUrl(url);
        const QImage image = resourceManager->imageByUrl(url);
        painter.drawImage(rectBorder, image);
    }

    /// draw rarity
    painter.setPen(cardView.rarity == Bronze ? Qt::darkRed : cardView.rarity == Silver ? Qt::gray : Qt::yellow);
    painter.drawRect(rectBorder);

    /// draw selection border
    if (isIn(cardView.id, choiceView.cardOptionIds)) {
        painter.setPen(Qt::green);
        painter.drawLine(rect.topLeft(), rect.bottomRight());
        painter.drawLine(rect.topRight(), rect.bottomLeft());
    }

    /// draw selected border
    if (isIn(cardView.id, choiceView.cardOptionIdsSelected)) {
        painter.setPen(Qt::red);
        painter.drawLine(rect.topLeft(), rect.bottomRight());
        painter.drawLine(rect.topRight(), rect.bottomLeft());
    }

    /// draw source border
    if (choiceView.cardSourceId >= 0 && cardView.id == choiceView.cardSourceId) {
        painter.setPen(Qt::cyan);
        painter.drawLine(rect.topLeft(), rect.bottomRight());
        painter.drawLine(rect.topRight(), rect.bottomLeft());
    }

    /// draw power
    const QPointF topLeft = rect.topLeft();
    double width = 0;
    if (cardView.power) {
        const Qt::GlobalColor back = cardView.power > cardView.powerBase ? Qt::green : cardView.power < cardView.powerBase ? Qt::red : Qt::gray;
        const Qt::GlobalColor fore = cardView.power > cardView.powerBase ? Qt::darkGreen : cardView.power < cardView.powerBase ? Qt::darkRed : Qt::black;
        width += paintTextInPoint(painter, layout, QString::number(cardView.power), topLeft, back, fore);
        width += layout.borderTextPx;
    }

    /// draw armor
    if (cardView.armor) {
        width += paintTextInPoint(painter, layout, "ARMOR " + QString::number(cardView.armor), QPointF(topLeft.x() + width, topLeft.y()), Qt::yellow, Qt::black);
        width += layout.borderTextPx;
    }

    if (cardView.isLocked) {
        width += paintTextInPoint(painter, layout, "LOCKED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::white);
        width += layout.borderTextPx;
    }

    if (cardView.timer) {
        width += paintTextInPoint(painter, layout, "TIMER " + QString::number(cardView.timer), QPointF(topLeft.x() + width, topLeft.y()), Qt::cyan, Qt::black);
        width += layout.borderTextPx;
    }

    if (cardView.isSpy) {
        width += paintTextInPoint(painter, layout, "SPY", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::red);
        width += layout.borderTextPx;
    }

    if (cardView.isResilient) {
        width += paintTextInPoint(painter, layout, "RESILIENCE", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::darkGreen);
        width += layout.borderTextPx;
    }

    if (cardView.isImmune) {
        width += paintTextInPoint(painter, layout, "IMMUNE", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::green);
        width += layout.borderTextPx;
    }

    if (cardView.isDoomed) {
        width += paintTextInPoint(painter, layout, "DOOMED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::cyan);
        width += layout.borderTextPx;
    }

    /// draw name
    const QRectF rectNameText(topLeft.x(), topLeft.y() + rect.height() - layout.metrics.height(), rect.width(), layout.metrics.height());
    paintTextInRect(painter, layout, QString::fromStdString(cardView.name), rectNameText);
}

double paintTextInPoint(QPainter &painter, const Layout &layout, const QString &text, const QPointF &topLeft, const Qt::GlobalColor colorBack, const Qt::GlobalColor colorFore, QRectF *rectRes)
{
    const double textHeight = layout.metrics.height();
    const double textWidth = layout.metrics.width(text);
    const QRectF rect(topLeft, QSizeF(textWidth + 2 * layout.borderTextPx, textHeight));
    painter.fillRect(rect, colorBack);
    painter.setPen(Qt::black);
    painter.drawRect(rect);
    painter.setPen(colorFore);
    const QRectF rectText(QPointF(topLeft.x() + layout.borderTextPx, topLeft.y()), QSizeF(textWidth, textHeight));
    painter.drawText(rectText, text);
    if (rectRes != nullptr)
        *rectRes = rect;
    return textWidth + 2 * layout.borderTextPx;
}

void paintTextInRect(QPainter &painter, const Layout &layout, const QString &text, const QRectF &rect)
{
    painter.fillRect(rect, Qt::white);
    painter.setPen(Qt::black);
    painter.drawRect(rect);

    const QString textElided = layout.metrics.elidedText(text, Qt::ElideRight, rect.width() - 2 * layout.borderNamePx);
    painter.drawText(rect.marginsRemoved(QMarginsF(layout.borderNamePx, 0, layout.borderNamePx, 0)), textElided);
}
