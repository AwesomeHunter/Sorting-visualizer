#pragma once

#include "sort_strategy.hpp"

class MergeSort : public SortStrategy {
private:
  void merge(Model &model, Controller &controller, size_t from, size_t to) const;
  void mergeSort(Model &model, Controller &controller, size_t from, size_t to) const;

public:
  void sort(Model &model, Controller &controller) const override;
};
