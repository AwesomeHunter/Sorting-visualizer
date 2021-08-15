#include "model.hpp"

std::default_random_engine Model::rng{std::random_device()()};

Model::Model(unsigned initSize) {
  this->setSize(initSize);
}

size_t Model::size() const {
  return this->data.size();
}

void Model::setSize(unsigned size) {
  this->data.clear();
  for (unsigned i = 1; i <= size; i++) {
    this->data.emplace_back(Sortable(i, *this));
  }
}

void Model::shuffle() {
  std::shuffle(this->data.begin(), this->data.end(), Model::rng);
}

Model::Sortable &Model::operator[](size_t i) {
  return this->data[i];
}

Model::Sortable Model::operator[](size_t i) const {
  return this->data[i];
}

void Model::moveToIndex(Sortable const &value, size_t newIndex) {
  auto it = std::find_if(this->data.begin(), this->data.end(), [&](Sortable const &el) { return &el == &value; });
  if (it == this->data.end() || newIndex >= this->size())
    return;
  size_t oldIndex = std::distance(this->data.begin(), it);
  if (oldIndex < newIndex) {
    std::rotate(this->data.begin() + oldIndex, this->data.begin() + oldIndex + 1, this->data.begin() + newIndex + 1);
  } else {
    std::rotate(this->data.begin() + newIndex, this->data.begin() + oldIndex, this->data.begin() + oldIndex + 1);
  }
}
