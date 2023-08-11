#include "BackButton.h"

BackButton *BackButton::instance = nullptr;

BackButton::BackButton(QWidget *parent)
    : Button(parent, "assets/BackButton.png", 48, 48, 0, 0) {
    hide();
}

void BackButton::createInstance(QWidget *parent) {
    if (!instance) {
        instance = new BackButton(parent);
    }
}

BackButton *BackButton::getInstance() { return instance; }

void BackButton::deleteInstance() { delete instance; }
