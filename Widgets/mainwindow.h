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
    void updateCardsList();

private:
    CardsLineView *_cardsLineView = nullptr;
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
};

#endif // MAINWINDOW_H
