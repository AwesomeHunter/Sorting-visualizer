#pragma once

#include "sort_strategy.hpp"

class InsertionSort : public SortStrategy {

public:
  void sort(Model &model, Controller &controller) const override;
};