#pragma once

#include "../model.hpp"

#define HIGHLIGHT_COMPARED_AND_UPDATE(first, second, controller) \
  if (!controller.isAlgorithmRunning())                          \
    return;                                                      \
  first.highlight();                                             \
  second.highlight();                                            \
  controller.update();                                           \
  first.unhighlight();                                           \
  second.unhighlight();

class Controller;

class SortStrategy {

public:
  SortStrategy() = default;
  virtual void sort(Model &model, Controller &controller) const = 0;
  virtual ~SortStrategy() = default;
};