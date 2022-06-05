#ifndef CARDSPAINTING_H
#define CARDSPAINTING_H

#include <qpainter.h>

#include "../Cards/view.h"

class ResourceManager;

struct Layout
{
    int borderCardPx = 1;
    int borderTextPx = 2;
    int borderNamePx = 5;
    QFont font = QFont("Mono", 12);
    QFontMetricsF metrics = QFontMetricsF(font);
};

double paintTextInPoint(
        QPainter &painter,
        const Layout &layout,
        const QString &text,
        const QPointF &topLeft,
        const Qt::GlobalColor colorBack = Qt::white,
        const Qt::GlobalColor colorFore = Qt::black,
        const int widthMax = -1,
        QRectF *rectRes = nullptr);

void paintTextInRect(
        QPainter &painter,
        const Layout &layout,
        const QString &text,
        const QRectF &rect);

void paintCard(
        QPainter &painter,
        ResourceManager *resourceManager,
        const Layout &layout,
        const CardView &cardView,
        const ChoiceView &choiceView,
        const QRectF &rect,
        const bool isStatusVisible = true);

void paintCardLarge(
        QPainter &painter,
        ResourceManager *resourceManager,
        const CardView &cardView,
        const QRectF &rect);

#endif // CARDSPAINTING_H
