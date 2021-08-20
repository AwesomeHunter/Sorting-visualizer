#include "sort_context.hpp"

void SortContext::sort(Model& model, Controller& controller) {
  if (strategy)
    strategy->sort(model, controller);
}
void SortContext::setStrategy(std::unique_ptr<SortStrategy> newStrategy) {
  strategy = std::move(newStrategy);
}
