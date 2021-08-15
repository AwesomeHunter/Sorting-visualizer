#include "controller.hpp"
#include "algorithms/bubble_sort.hpp"
#include "algorithms/insertion_sort.hpp"
#include "algorithms/merge_sort.hpp"
#include "algorithms/selection_sort.hpp"

Controller::Controller()
    : context(SortContext()), view(View(1920, 1080)), model(Model(64)), keyPressed(false), algorithmRunning(false),
      delay(30) {
}

void Controller::windowClosed() {
  this->algorithmRunning = false;
  this->view.closeWindow();
}

void Controller::keyReleasedEvent() {
  this->keyPressed = false;
}

void Controller::changeDelay(sf::Event &event) {
  if (event.mouseWheel.delta > 0)
    this->delay = std::min(this->delay + 10, this->MAX_DELAY);
  if (event.mouseWheel.delta < 0)
    this->delay = std::max(this->delay - 10, this->MIN_DELAY);
}

void Controller::increaseModelSize() {
  unsigned newSize = this->model.size() * 2;
  if (newSize <= this->MAX_MODEL_SIZE)
    this->model.setSize(newSize);
}

void Controller::decreaseModelSize() {
  unsigned newSize = this->model.size() / 2;
  if (newSize >= this->MIN_MODEL_SIZE)
    this->model.setSize(newSize);
}

void Controller::runSortingAlgorithm(std::unique_ptr<SortStrategy> algorithm) {
  this->algorithmRunning = true;
  this->context.setStrategy(std::move(algorithm));
  this->context.sort(this->model, *this);
  this->algorithmRunning = false;
}

void Controller::update() {
  this->handleEvents();
  this->view.updateScreen(this->model);
  this->view.delay(this->delay);
}

bool Controller::isAppRunning() const {
  return this->view.isWindowOpened();
}

bool Controller::isAlgorithmRunning() const {
  return this->algorithmRunning;
}

void Controller::handleEvents() {
  sf::Event event;
  while (this->view.getEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      this->windowClosed();
      break;
    case sf::Event::KeyPressed:
      this->keyPressedEvent(event);
      break;
    case sf::Event::KeyReleased:
      this->keyReleasedEvent();
      break;
    case sf::Event::MouseWheelMoved:
      this->changeDelay(event);
      break;
    default:
      break;
    }
  }
}

void Controller::keyPressedEvent(sf::Event &event) {
  if (this->keyPressed)
    return;
  this->keyPressed = true;
  if (event.key.code == sf::Keyboard::T)
    this->algorithmRunning = false;
  if (this->algorithmRunning)
    return;
  switch (event.key.code) {
  case sf::Keyboard::S:
    this->model.shuffle();
    break;
  case sf::Keyboard::Hyphen:
    this->decreaseModelSize();
    break;
  case sf::Keyboard::Equal:
    this->increaseModelSize();
    break;
  case sf::Keyboard::Num1:
    this->runSortingAlgorithm(std::make_unique<BubbleSort>());
    break;
  case sf::Keyboard::Num2:
    this->runSortingAlgorithm(std::make_unique<SelectionSort>());
    break;
  case sf::Keyboard::Num3:
    this->runSortingAlgorithm(std::make_unique<InsertionSort>());
    break;
  case sf::Keyboard::Num4:
    this->runSortingAlgorithm(std::make_unique<MergeSort>());
    break;
  default:
    break;
  }
}
