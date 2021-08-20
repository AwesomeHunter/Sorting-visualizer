#pragma once

#include "sort_strategy.hpp"

class BubbleSort : public SortStrategy {

public:
  void sort(Model& model, Controller& controller) const override;
};