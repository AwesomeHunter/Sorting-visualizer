#include "algorithms/insertion_sort.hpp"
#include "controller.hpp"

void InsertionSort::sort(Model &model, Controller &controller) const {
  for (size_t i = 0; i < model.size(); i++) {
    for (size_t j = 0; j <= i; j++) {
      HIGHLIGHT_COMPARED_AND_UPDATE(model[i], model[j], controller);
      if (model[j] >= model[i]) {
        model[i].moveToIndex(j);
        break;
      }
    }
  }
}