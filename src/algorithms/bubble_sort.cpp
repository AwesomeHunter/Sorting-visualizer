#include "algorithms/bubble_sort.hpp"
#include "controller.hpp"

void BubbleSort::sort(Model& model, Controller& controller) const {
  int changes = 1;
  while (changes > 0) {
    changes = 0;
    for (size_t i = 0; i < model.size() - 1; i++) {
      if (model[i + 1] < model[i]) {
        changes++;
        std::swap(model[i], model[i + 1]);
      }
      if (!controller.isAlgorithmRunning())
        return;
      highlightAndUpdate(model, controller, {i, i + 1});
    }
  }
}