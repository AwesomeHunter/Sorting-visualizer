#include "sort_context.hpp"

void SortContext::sort(Model &model, Controller &controller) {
  if (this->strategy)
    this->strategy->sort(model, controller);
}
void SortContext::setStrategy(std::unique_ptr<SortStrategy> newStrategy) {
  this->strategy = std::move(newStrategy);
}
