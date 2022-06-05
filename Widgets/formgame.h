#ifndef FORMGAME_H
#define FORMGAME_H

#include <QMainWindow>

class CardsFieldView;
class ResourceManager;

class FormGame : public QMainWindow
{
    Q_OBJECT
public:
    explicit FormGame(QWidget *parent = nullptr);

private:
    ResourceManager *_resourceManager = nullptr;
    CardsFieldView *_cardsFieldView = nullptr;
};

#endif // FORMGAME_H
