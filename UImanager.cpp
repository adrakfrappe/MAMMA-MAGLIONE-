#include "UImanager.h"

void UImanager::addbutton(const Button& button) {
    buttons.push_back(button);
}

void UImanager::draw(sf::RenderWindow& window) {
    for (auto& button : buttons) {
        button.draw(window);
    }
}

void UImanager::handleEvents(sf::RenderWindow& window, sf::Event& event, int& clickedIndex) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i].isClicked(mousePos, event)) {
            clickedIndex = static_cast<int>(i);
            return;
        }
    }
    clickedIndex = -1;
}

void UImanager::update(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (auto& button : buttons) {
        button.update(mousePos);
    }
}
