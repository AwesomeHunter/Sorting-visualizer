#pragma once

#include "algorithms/sort_strategy.hpp"
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

  static constexpr int MIN_DELAY = 0;
  static constexpr int MAX_DELAY = 100;
  int delay;

  static constexpr int MAX_MODEL_SIZE = 1024;
  static constexpr int MIN_MODEL_SIZE = 2;

  void increaseModelSize();
  void decreaseModelSize();
  void changeDelay(const sf::Event& event);
  void windowClosed();
  void keyPressedEvent(const sf::Event& event);
  void keyReleasedEvent();
  void handleEvents();
  void runSortingAlgorithm(std::unique_ptr<SortStrategy> algorithm);

public:
  Controller();
  void update();
  bool isAppRunning() const;
  bool isAlgorithmRunning() const;
};
