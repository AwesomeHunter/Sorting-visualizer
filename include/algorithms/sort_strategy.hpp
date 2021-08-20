#pragma once

#include "../model.hpp"
#include <initializer_list>

class Controller;

class SortStrategy {
protected:
  void highlightAndUpdate(Model& model, Controller& controller, std::initializer_list<size_t> indexes) const;

public:
  SortStrategy() = default;
  virtual void sort(Model& model, Controller& controller) const = 0;
  virtual ~SortStrategy() = default;
};