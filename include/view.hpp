#pragma once

#include "model.hpp"
#include <SFML/Graphics.hpp>

class View {

private:
  const unsigned WIDTH, HEIGHT;
  const unsigned FRAME_RATE = 60;
  sf::RenderWindow window;

  void draw(const Model &model);

public:
  View(const unsigned WIDTH, const unsigned HEIGHT);
  void delay(unsigned time) const;
  void updateScreen(const Model &model);
  bool getEvent(sf::Event &event);
  bool isWindowOpened() const;
  void closeWindow();
};