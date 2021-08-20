#pragma once

#include <algorithm>
#include <random>
#include <vector>

class Model {
private:
  struct Sortable {
  private:
    int value;
    bool highlighted;
    std::reference_wrapper<Model> container;

  public:
    Sortable() = delete;
    Sortable(int value, Model& model) : value(value), highlighted(false), container(model){};
    void highlight() {
      highlighted = true;
    }
    void unhighlight() {
      highlighted = false;
    }
    bool isHighlighted() const {
      return highlighted;
    }
    float heightAsPercentage() const {
      return static_cast<float>(value) / container.get().size();
    }
    void moveToIndex(size_t index) {
      container.get().moveToIndex(*this, index);
    }
    bool operator<(const Sortable& rhs) const {
      return value < rhs.value;
    }
  };

  static std::default_random_engine rng;
  std::vector<Sortable> data;

  void moveToIndex(const Sortable& value, size_t newIndex);

public:
  Model(int initSize = 64);
  size_t size() const;
  void setSize(int size);
  void shuffle();
  Sortable operator[](size_t i) const;
  Sortable& operator[](size_t i);
};