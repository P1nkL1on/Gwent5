#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Cards/view.h"

class QCheckBox;
class QLineEdit;
class CardsLineView;
class CardSingleView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    bool putCardToDeck(const int id);
    bool putCardBack(const int id);
    void updateCardsList();

private:
    CardsLineView *_cardsLineView = nullptr;
    CardsLineView *_cardsLineView2 = nullptr;
    CardsLineView *_cardsLineViewOptions = nullptr;
    CardSingleView *_cardSingleView = nullptr;
    QCheckBox *_checkBoxGold = nullptr;
    QCheckBox *_checkBoxSilver = nullptr;
    QCheckBox *_checkBoxBronze = nullptr;
    QCheckBox *_checkBoxNeutral = nullptr;
    QCheckBox *_checkBoxMonster = nullptr;
    QCheckBox *_checkBoxNilfgaard = nullptr;
    QCheckBox *_checkBoxNothernRealms = nullptr;
    QCheckBox *_checkBoxScoiatael = nullptr;
    QCheckBox *_checkBoxSkellige = nullptr;
    QLineEdit *_lineEditSearch = nullptr;
    std::vector<CardView> _allCardViews;
    std::vector<CardView> _deckCardViews;

    bool isDeckOk(int &nBronze, int &nSilver, int &nGold, QString &err);
};

#endif // MAINWINDOW_H
