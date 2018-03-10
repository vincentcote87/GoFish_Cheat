#ifndef CHEATUI_H
#define CHEATUI_H

#include "GameUI.h"
#include "Card.h"

class CheatUI : public GameUI {
public:
    CheatUI() {}
    ~CheatUI() {}

    unsigned int requestCard(list<Card*>* hand);
    void playFailed();
    void playSucceeded();
};

#endif 
