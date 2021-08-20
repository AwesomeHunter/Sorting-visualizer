#include "algorithms/merge_sort.hpp"
#include "controller.hpp"

void MergeSort::merge(Model& model, Controller& controller, size_t from, size_t to) const {
  size_t mid = (from + to) / 2;
  size_t leftIndex = from;
  size_t rightIndex = mid + 1;
  while (leftIndex <= mid && rightIndex <= to) {
    if (!controller.isAlgorithmRunning())
      return;
    highlightAndUpdate(model, controller, {leftIndex, rightIndex});
    if (model[rightIndex] < model[leftIndex]) {
      model[rightIndex].moveToIndex(leftIndex);
      mid++;
      rightIndex++;
    }
    leftIndex++;
  }
}

void MergeSort::mergeSort(Model& model, Controller& controller, size_t from, size_t to) const {
  if (from >= to)
    return;
  size_t mid = (from + to) / 2;
  mergeSort(model, controller, from, mid);
  mergeSort(model, controller, mid + 1, to);
  merge(model, controller, from, to);
}

void MergeSort::sort(Model& model, Controller& controller) const {
  mergeSort(model, controller, 0, model.size() - 1);
}
