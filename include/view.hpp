#pragma once

#include "model.hpp"
#include <SFML/Graphics.hpp>

class View {

private:
  const int WIDTH, HEIGHT;
  const int FRAME_RATE = 60;
  sf::RenderWindow window;

  void draw(const Model& model);

public:
  View(const int WIDTH, const int HEIGHT);
  void delay(int time) const;
  void updateScreen(const Model& model);
  bool getEvent(sf::Event& event);
  bool isWindowOpened() const;
  void closeWindow();
};