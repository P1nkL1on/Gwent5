#include "cardspainting.h"

void paintCard(QPainter &painter, ResourceManager *resourceManager, const Layout &layout, const CardView &cardView, const ChoiceView &choiceView, const QRectF &rect, const bool isStatusVisible)
{
    Q_ASSERT(!cardView.isAmbush);
    painter.setPen(Qt::black);
    painter.drawRect(rect);

    const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(layout.borderCardPx, layout.borderCardPx, layout.borderCardPx, layout.borderCardPx));

    /// draw url image
    if (cardView.url.size() > 0) {
        const QString url = QString::fromStdString(cardView.url);
        resourceManager->requestImageByUrl(url);
        QImage image = resourceManager->imageByUrl(url);
        if (cardView.count == 0)
            image = image.convertToFormat(QImage::Format_Grayscale8);
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
        const Qt::GlobalColor back = cardView.power > cardView.powerBase ? Qt::green : cardView.power < cardView.powerBase ? Qt::red : Qt::white;
        const Qt::GlobalColor fore = cardView.power > cardView.powerBase ? Qt::darkGreen : cardView.power < cardView.powerBase ? Qt::darkRed : Qt::black;
        width += paintTextInPoint(painter, layout, QString::number(cardView.power), topLeft, back, fore);
        width += layout.borderTextPx;
    }

    if (cardView.count > 1) {
        const QString string = QString("x%1").arg(cardView.count);
        paintTextInPoint(painter, layout, string, rect.topRight() - QPointF(layout.metrics.width(string), 0), Qt::gray, Qt::black);
    }

    /// draw armor
    if (isStatusVisible && cardView.armor) {
        width += paintTextInPoint(painter, layout, "ARMOR " + QString::number(cardView.armor), QPointF(topLeft.x() + width, topLeft.y()), Qt::yellow, Qt::black);
        width += layout.borderTextPx;
    }

    if (isStatusVisible && cardView.isLocked) {
        width += paintTextInPoint(painter, layout, "LOCKED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::white);
        width += layout.borderTextPx;
    }

    if (isStatusVisible && cardView.timer) {
        width += paintTextInPoint(painter, layout, "TIMER " + QString::number(cardView.timer), QPointF(topLeft.x() + width, topLeft.y()), Qt::cyan, Qt::black);
        width += layout.borderTextPx;
    }

    if (isStatusVisible && cardView.isSpy) {
        width += paintTextInPoint(painter, layout, "SPY", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::red);
        width += layout.borderTextPx;
    }

    if (isStatusVisible && cardView.isResilient) {
        width += paintTextInPoint(painter, layout, "RESILIENCE", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::darkGreen);
        width += layout.borderTextPx;
    }

    if (isStatusVisible && cardView.isImmune) {
        width += paintTextInPoint(painter, layout, "IMMUNE", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::green);
        width += layout.borderTextPx;
    }

    if (isStatusVisible && cardView.isDoomed) {
        width += paintTextInPoint(painter, layout, "DOOMED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::cyan);
        width += layout.borderTextPx;
    }

    /// draw name
    const QRectF rectNameText(topLeft.x(), topLeft.y() + rect.height() - layout.metrics.height(), rect.width(), layout.metrics.height());
    paintTextInRect(painter, layout, QString::fromStdString(cardView.name), rectNameText);
}

double paintTextInPoint(QPainter &painter, const Layout &layout, const QString &text, const QPointF &topLeft, const Qt::GlobalColor colorBack, const Qt::GlobalColor colorFore, const int widthMax, QRectF *rectRes)
{
    QRectF rect;
    double width;
    if (widthMax >= 0) {
        rect = layout.metrics.boundingRect(QRectF(topLeft, QSize(widthMax, std::numeric_limits<int>::max())), Qt::AlignLeft | Qt::TextWordWrap, text);
        width = widthMax;
    } else {
        const double textHeight = layout.metrics.height();
        const double textWidth = layout.metrics.width(text);
        rect = QRectF(topLeft, QSizeF(textWidth, textHeight));
        width = textWidth + 2 * layout.borderTextPx;
    }
    painter.fillRect(rect, colorBack);
    painter.setPen(Qt::black);
    painter.drawRect(rect);
    painter.setPen(colorFore);
    painter.setFont(layout.font);
    painter.drawText(rect, text);
    if (rectRes != nullptr)
        *rectRes = rect;
    return width;
}

void paintTextInRect(QPainter &painter, const Layout &layout, const QString &text, const QRectF &rect)
{
    painter.fillRect(rect, Qt::white);
    painter.setPen(Qt::black);
    painter.drawRect(rect);

    const QString textElided = layout.metrics.elidedText(text, Qt::ElideRight, rect.width() - 2 * layout.borderNamePx);
    painter.setFont(layout.font);
    painter.drawText(rect.marginsRemoved(QMarginsF(layout.borderNamePx, 0, layout.borderNamePx, 0)), textElided);
}

void paintCardLarge(QPainter &painter, ResourceManager *resourceManager, const CardView &cardView, const QRectF &rect)
{
    const double wa = 97 / 130.0;
    const double wb = 30 / 130.0;
    const double ha = 138 / 163.0;
    const double hb = 22 / 163.0;
    const QPointF topLeft(rect.left() + rect.width() * wb, rect.top() + rect.height() * hb);
    const QSizeF size(rect.width() * wa, rect.height() * ha);
    const QRectF rectImage(topLeft, size);

    const QMap<int, QString> rarityToBorderUrl {
        {Bronze, "https://gwent.one/image/card/medium/assets/open-beta/border-bronze.png"},
        {Silver, "https://gwent.one/image/card/medium/assets/open-beta/border-silver.png"},
        {Gold, "https://gwent.one/image/card/medium/assets/open-beta/border-gold.png"},
    };
    const QMap<int, QString> factionToSilverCornerUrl {
        {Neutral, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-nt.png"},
        {NothernRealms, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-nr.png"},
        {Monster, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-mo.png"},
        {Nilfgaard, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-ng.png"},
        {Scoiatael, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-st.png"},
        {Skellige, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-sk.png"},
    };
    const QMap<int, QString> factionToGoldCornerUrl {
        {Neutral, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-nt.png"},
        {NothernRealms, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-nr.png"},
        {Monster, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-mo.png"},
        {Nilfgaard, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-ng.png"},
        {Scoiatael, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-st.png"},
        {Skellige, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-sk.png"},
    };

    if (cardView.url.size() > 0) {
        const QString url = QString::fromStdString(cardView.url);
        resourceManager->requestImageByUrl(url);
        const QImage image = resourceManager->imageByUrl(url);
        painter.drawImage(rectImage, image);
    }
    {
        const QString borderUrl = rarityToBorderUrl.value(cardView.rarity);
        resourceManager->requestImageByUrl(borderUrl);
        const QImage image = resourceManager->imageByUrl(borderUrl);
        painter.drawImage(rect, image);
    }
    {
        const QString cornerUrl = cardView.rarity == Gold ? factionToGoldCornerUrl.value(cardView.faction) : factionToSilverCornerUrl.value(cardView.faction);
        resourceManager->requestImageByUrl(cornerUrl);
        const QImage image = resourceManager->imageByUrl(cornerUrl);
        painter.drawImage(rect, image);
    }
}
