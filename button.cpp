#include "game.h"


Button::Button(const sf::Vector2f& size, const sf::Vector2f& position,
    const string& text, Font& font) {
    shape.setSize(size);
    shape.setPosition(position);
    normalColor = Color(255, 230, 190);
    hoverColor = Color(150, 10, 10);
    shape.setFillColor(normalColor);
    label.setOutlineThickness(0.5);
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(30);
    label.setOutlineColor(Color::Green);
    label.setFillColor(sf::Color::Red);

sf:FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.left + textBounds.width / 2.0f,
        textBounds.top + textBounds.height / 2.0f);
    label.setPosition(position.x + size.x / 2.0f,
        position.y + size.y / 2.0f);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(label);
}

void Button::update(const sf::Vector2i& mousePos) {
    if (shape.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
        shape.setFillColor(hoverColor);
    }
    else {
        shape.setFillColor(normalColor);
    }
}

bool Button::isClicked(const sf::Vector2i& mousePos, sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left &&
        shape.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
        return true;
    }
    return false;
}
