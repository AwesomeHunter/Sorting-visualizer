#pragma once

#include <algorithm>
#include <random>
#include <vector>

class Model {
private:
  struct Sortable {
  private:
    unsigned value;
    bool highlighted;
    std::reference_wrapper<Model> container;

  public:
    Sortable() = delete;
    Sortable(unsigned value, Model &model) : value(value), highlighted(false), container(model){};
    void highlight() {
      this->highlighted = true;
    }
    void unhighlight() {
      this->highlighted = false;
    }
    bool isHighlighted() const {
      return this->highlighted;
    }
    float heightAsPercentage() const {
      return static_cast<float>(this->value) / this->container.get().size();
    }
    void moveToIndex(size_t index) {
      this->container.get().moveToIndex(*this, index);
    }
    bool operator<(Sortable const &rhs) const {
      return this->value < rhs.value;
    }
    bool operator>(Sortable const &rhs) const {
      return this->value > rhs.value;
    }
    bool operator>=(Sortable const &rhs) const {
      return this->value >= rhs.value;
    }
    bool operator<=(Sortable const &rhs) const {
      return this->value <= rhs.value;
    }
  };

  static std::default_random_engine rng;
  std::vector<Sortable> data;

  void moveToIndex(Sortable const &value, size_t newIndex);

public:
  Model(unsigned initSize = 64);
  size_t size() const;
  void setSize(unsigned size);
  void shuffle();
  Sortable operator[](size_t i) const;
  Sortable &operator[](size_t i);
};