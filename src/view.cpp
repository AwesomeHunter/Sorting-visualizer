#include "view.hpp"

View::View(const unsigned WIDTH, const unsigned HEIGHT)
    : WIDTH(WIDTH), HEIGHT(HEIGHT), window(sf::VideoMode(WIDTH, HEIGHT), "Sorting visualization") {
  window.setFramerateLimit(this->FRAME_RATE);
}

void View::delay(unsigned time) const {
  sf::sleep(sf::milliseconds(time));
}

void View::draw(const Model &model) {
  float width = static_cast<float>(this->WIDTH) / model.size();
  for (size_t i = 0; i < model.size(); i++) {
    float height = this->HEIGHT * model[i].heightAsPercentage();
    sf::RectangleShape rect({width, height});
    rect.setPosition({i * width, this->HEIGHT - height});
    if (model[i].isHighlighted())
      rect.setFillColor(sf::Color::Red);
    else
      rect.setFillColor(sf::Color::Black);
    this->window.draw(rect);
  }
}

void View::updateScreen(const Model &model) {
  this->window.clear(sf::Color::White);
  this->draw(model);
  this->window.display();
}

bool View::getEvent(sf::Event &event) {
  return this->window.pollEvent(event);
}

bool View::isWindowOpened() const {
  return this->window.isOpen();
}

void View::closeWindow() {
  this->window.close();
}
