#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Cards/cards.h"

struct View
{
    int spacingPx = 20;
    int borderCardPx = 5;
    int borderTextPx = 2;
    int borderNamePx = 5;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    bool eventFilter(QObject*, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;

    View _view;

    std::vector<Card *> _cards;
    Field _ally ;
    Field _enemy;
};

#endif // MAINWINDOW_H
