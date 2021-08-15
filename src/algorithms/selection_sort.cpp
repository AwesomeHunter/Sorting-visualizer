#include "algorithms/selection_sort.hpp"
#include "controller.hpp"

void SelectionSort::sort(Model &model, Controller &controller) const {
  for (size_t i = 0; i < model.size(); i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < model.size(); j++) {
      HIGHLIGHT_COMPARED_AND_UPDATE(model[minIndex], model[j], controller);
      if (model[j] < model[minIndex])
        minIndex = j;
    }
    model[minIndex].moveToIndex(i);
  }
}