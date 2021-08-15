#pragma once

#include "algorithms/sort_strategy.hpp"
#include "model.hpp"

#include <memory>

class Controller;

class SortContext {

private:
  std::unique_ptr<SortStrategy> strategy;

public:
  void setStrategy(std::unique_ptr<SortStrategy> newStrategy);
  void sort(Model &model, Controller &controller);
};
