#include "algorithms/sort_strategy.hpp"
#include "controller.hpp"

void SortStrategy::highlightAndUpdate(Model& model, Controller& controller,
                                      std::initializer_list<size_t> indexes) const {
  for (auto index : indexes) {
    model[index].highlight();
  }
  controller.update();
  for (auto index : indexes) {
    model[index].unhighlight();
  }
}