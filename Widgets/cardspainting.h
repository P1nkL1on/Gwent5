#ifndef CARDSPAINTING_H
#define CARDSPAINTING_H

#include <qpainter.h>

#include "../Widgets/resourcemanager.h"
#include "../Cards/view.h"

struct Layout
{
    int borderCardPx = 1;
    int borderTextPx = 2;
    int borderNamePx = 5;
    QFontMetricsF metrics = QFontMetricsF(QFont{});
};

double paintTextInPoint(
        QPainter &painter,
        const Layout &layout,
        const QString &text,
        const QPointF &topLeft,
        const Qt::GlobalColor colorBack = Qt::white,
        const Qt::GlobalColor colorFore = Qt::black,
        QRectF *rectRes = nullptr);;

void paintTextInRect(
        QPainter &painter,
        const Layout &layout,
        const QString &text,
        const QRectF &rect);;

void paintCard(
        QPainter &painter,
        ResourceManager *resourceManager,
        const Layout &layout,
        const CardView &cardView,
        const ChoiceView &choiceView,
        const QRectF &rect
        );

#endif // CARDSPAINTING_H
