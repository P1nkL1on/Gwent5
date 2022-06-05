#include "cardsfieldview.h"

#include <QPaintEvent>


CardsFieldView::CardsFieldView(
        ResourceManager *resourceManager,
        const FieldView &view,
        QWidget *parent) :
    QWidget(parent),
    _resourceManager(resourceManager),
    _view(view)
{
}

bool CardsFieldView::eventFilter(QObject *o, QEvent *e)
{
    return QWidget::eventFilter(o, e);
}

void CardsFieldView::paintEvent(QPaintEvent *e)
{
    const QRect _rect = e->rect();
    QPainter painter(this);
    painter.fillRect(_rect, Qt::white);

    const double width = (_rect.width() - _spacingCard * 8 - _diameterCoin - 2 * _spacingCoin - _spacingPowerRow) / 9.0;
    const double height = (_rect.height() - _spacingFields - _spacingRow * 4) / 6.0;

    const auto paintRow = [=, &painter](const QPointF &topLeft, const std::vector<int> &ids) {
        const QPointF topCenterPoint = topLeft + QPointF((width * 9 + _spacingCard * 8) / 2 + _spacingCard / 2.0, 0);
        const size_t nCards = ids.size();
        for (size_t cardInd = 0; cardInd < nCards; ++cardInd) {
            const QPointF topLeft = topCenterPoint + QPointF((cardInd - nCards / 2.0) * width + (int(cardInd) - int(nCards) / 2.0) * _spacingCard, 0);
            const QRectF rect(topLeft, QSizeF(width, height));
            paintCard(painter, _resourceManager, {}, _view.cardView(ids[cardInd]), {},  rect, true);
        }
    };

    /// backgrounds
    const QColor colorEnemy(255, 122, 122);
    const QColor colorAlly(122, 122, 255);

    const QPointF topLeftRows = _rect.topLeft() + QPointF(_diameterCoin + 2 * _spacingCoin + _spacingPowerRow, 0);
    painter.fillRect(QRectF(topLeftRows, QSizeF(width * 9 + _spacingCard * 8, _rect.height() / 2.0)), colorEnemy);
    painter.fillRect(QRectF(topLeftRows + QPointF(0, _rect.height() / 2.0), QSizeF(width * 9 + _spacingCard * 8, _rect.height() / 2.0)), colorAlly);

    painter.setBrush(_view.choices.size() ? colorAlly : colorEnemy);
    painter.drawEllipse(QRectF(_rect.topLeft() + QPointF(0, _rect.height() / 2.0 - _diameterCoin / 2.0), QSizeF(_diameterCoin, _diameterCoin)));
    painter.setBrush({});

    /// texts
    const QString stringAllyScore = QString::number(_view.nPowerRowAllySeige + _view.nPowerRowAllyRange + _view.nPowerRowAllyMeele) + " " + QString().rightJustified(_view.nAllyWins, '*');
    const QString stringEnemyScore = QString::number(_view.nPowerRowEnemySeige + _view.nPowerRowEnemyRange + _view.nPowerRowEnemyMeele) + " " + QString().rightJustified(_view.nEnemyWins, '*');
    paintTextInPoint(painter, {}, stringEnemyScore, _rect.topLeft() + QPointF(_diameterCoin / 2.0, _rect.height() / 2.0 - _diameterCoin / 2.0 - _spacingPowerTotal - Layout().font.pointSizeF()));
    paintTextInPoint(painter, {}, stringAllyScore, _rect.topLeft() + QPointF(_diameterCoin / 2.0, _rect.height() / 2.0 + _diameterCoin / 2.0 + _spacingPowerTotal));
    paintTextInPoint(painter, {}, QString::number(_view.nPowerRowEnemySeige), topLeftRows + QPointF(-_spacingPowerRow, 0));
    paintTextInPoint(painter, {}, QString::number(_view.nPowerRowEnemyRange), topLeftRows + QPointF(-_spacingPowerRow, height + _spacingRow));
    paintTextInPoint(painter, {}, QString::number(_view.nPowerRowEnemyMeele), topLeftRows + QPointF(-_spacingPowerRow, height * 2 + _spacingRow * 2));
    paintTextInPoint(painter, {}, QString::number(_view.nPowerRowAllyMeele), topLeftRows + QPointF(-_spacingPowerRow, height * 3 + _spacingRow * 2 + _spacingFields));
    paintTextInPoint(painter, {}, QString::number(_view.nPowerRowAllyRange), topLeftRows + QPointF(-_spacingPowerRow, height * 4 + _spacingRow * 3 + _spacingFields));
    paintTextInPoint(painter, {}, QString::number(_view.nPowerRowAllySeige), topLeftRows + QPointF(-_spacingPowerRow, height * 5 + _spacingRow * 4 + _spacingFields));

    /// drawing rows
    paintRow(topLeftRows, _view.enemyRowSeigeIds);
    paintRow(topLeftRows + QPointF(0, height + _spacingRow), _view.enemyRowRangeIds);
    paintRow(topLeftRows + QPointF(0, height * 2 + _spacingRow * 2), _view.enemyRowMeeleIds);
    paintRow(topLeftRows + QPointF(0, height * 3 + _spacingRow * 2 + _spacingFields), _view.allyRowMeeleIds);
    paintRow(topLeftRows + QPointF(0, height * 4 + _spacingRow * 3 + _spacingFields), _view.allyRowRangeIds);
    paintRow(topLeftRows + QPointF(0, height * 5 + _spacingRow * 4 + _spacingFields), _view.allyRowSeigeIds);
}
