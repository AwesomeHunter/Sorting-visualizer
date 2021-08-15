#pragma once

#include "model.hpp"
#include "sort_context.hpp"
#include "view.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Controller {

private:
  SortContext context;
  View view;
  Model model;

  bool keyPressed;
  bool algorithmRunning;

  const unsigned MIN_DELAY = 0;
  const unsigned MAX_DELAY = 100;
  unsigned delay;

  const unsigned MAX_MODEL_SIZE = 1024;
  const unsigned MIN_MODEL_SIZE = 2;

  void increaseModelSize();
  void decreaseModelSize();
  void changeDelay(sf::Event &event);
  void windowClosed();
  void keyPressedEvent(sf::Event &event);
  void keyReleasedEvent();
  void handleEvents();
  void runSortingAlgorithm(std::unique_ptr<SortStrategy> algorithm);

public:
  Controller();
  void update();
  bool isAppRunning() const;
  bool isAlgorithmRunning() const;
};
