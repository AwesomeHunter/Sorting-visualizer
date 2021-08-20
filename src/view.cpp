#include "view.hpp"

View::View(const int WIDTH, const int HEIGHT)
    : WIDTH(WIDTH), HEIGHT(HEIGHT), window(sf::VideoMode(WIDTH, HEIGHT), "Sorting visualization") {
  window.setFramerateLimit(FRAME_RATE);
}

void View::delay(int time) const {
  sf::sleep(sf::milliseconds(time));
}

void View::draw(const Model& model) {
  float width = static_cast<float>(WIDTH) / model.size();
  for (size_t i = 0; i < model.size(); i++) {
    float height = HEIGHT * model[i].heightAsPercentage();
    sf::RectangleShape rect({width, height});
    rect.setPosition({i * width, HEIGHT - height});
    if (model[i].isHighlighted())
      rect.setFillColor(sf::Color::Red);
    else
      rect.setFillColor(sf::Color::Black);
    window.draw(rect);
  }
}

void View::updateScreen(const Model& model) {
  window.clear(sf::Color::White);
  draw(model);
  window.display();
}

bool View::getEvent(sf::Event& event) {
  return window.pollEvent(event);
}

bool View::isWindowOpened() const {
  return window.isOpen();
}

void View::closeWindow() {
  window.close();
}
