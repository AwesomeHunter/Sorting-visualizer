#include "model.hpp"

std::default_random_engine Model::rng{std::random_device()()};

Model::Model(int initSize) {
  setSize(initSize);
}

size_t Model::size() const {
  return data.size();
}

void Model::setSize(int size) {
  data.clear();
  for (int i = 1; i <= size; i++) {
    data.emplace_back(Sortable(i, *this));
  }
}

void Model::shuffle() {
  std::shuffle(data.begin(), data.end(), Model::rng);
}

Model::Sortable& Model::operator[](size_t i) {
  return data[i];
}

Model::Sortable Model::operator[](size_t i) const {
  return data[i];
}

void Model::moveToIndex(const Sortable& value, size_t newIndex) {
  auto it = std::find_if(data.begin(), data.end(), [&](const Sortable& el) { return &el == &value; });
  if (it == data.end() || newIndex >= size())
    return;
  size_t oldIndex = std::distance(data.begin(), it);
  if (oldIndex < newIndex) {
    std::rotate(data.begin() + oldIndex, data.begin() + oldIndex + 1, data.begin() + newIndex + 1);
  } else {
    std::rotate(data.begin() + newIndex, data.begin() + oldIndex, data.begin() + oldIndex + 1);
  }
}
