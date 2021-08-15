#include "algorithms/merge_sort.hpp"
#include "controller.hpp"

void MergeSort::merge(Model &model, Controller &controller, size_t from, size_t to) const {
  size_t mid = (from + to) / 2;
  size_t leftIndex = from;
  size_t rightIndex = mid + 1;
  while (leftIndex <= mid && rightIndex <= to) {
    HIGHLIGHT_COMPARED_AND_UPDATE(model[leftIndex], model[rightIndex], controller);
    if (model[leftIndex] > model[rightIndex]) {
      model[rightIndex].moveToIndex(leftIndex);
      mid++;
      rightIndex++;
    }
    leftIndex++;
  }
}

void MergeSort::mergeSort(Model &model, Controller &controller, size_t from, size_t to) const {
  if (from >= to)
    return;
  size_t mid = (from + to) / 2;
  this->mergeSort(model, controller, from, mid);
  this->mergeSort(model, controller, mid + 1, to);
  this->merge(model, controller, from, to);
}

void MergeSort::sort(Model &model, Controller &controller) const {
  this->mergeSort(model, controller, 0, model.size() - 1);
}
