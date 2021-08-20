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
  algorithmRunning = false;
  view.closeWindow();
}

void Controller::keyReleasedEvent() {
  keyPressed = false;
}

void Controller::changeDelay(const sf::Event& event) {
  if (event.mouseWheel.delta > 0)
    delay = std::min(delay + 10, MAX_DELAY);
  if (event.mouseWheel.delta < 0)
    delay = std::max(delay - 10, MIN_DELAY);
}

void Controller::increaseModelSize() {
  int newSize = model.size() * 2;
  if (newSize <= MAX_MODEL_SIZE)
    model.setSize(newSize);
}

void Controller::decreaseModelSize() {
  int newSize = model.size() / 2;
  if (newSize >= MIN_MODEL_SIZE)
    model.setSize(newSize);
}

void Controller::runSortingAlgorithm(std::unique_ptr<SortStrategy> algorithm) {
  algorithmRunning = true;
  context.setStrategy(std::move(algorithm));
  context.sort(model, *this);
  algorithmRunning = false;
}

void Controller::update() {
  handleEvents();
  view.updateScreen(model);
  view.delay(delay);
}

bool Controller::isAppRunning() const {
  return view.isWindowOpened();
}

bool Controller::isAlgorithmRunning() const {
  return algorithmRunning;
}

void Controller::handleEvents() {
  sf::Event event;
  while (view.getEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      windowClosed();
      break;
    case sf::Event::KeyPressed:
      keyPressedEvent(event);
      break;
    case sf::Event::KeyReleased:
      keyReleasedEvent();
      break;
    case sf::Event::MouseWheelMoved:
      changeDelay(event);
      break;
    default:
      break;
    }
  }
}

void Controller::keyPressedEvent(const sf::Event& event) {
  if (keyPressed)
    return;
  keyPressed = true;
  if (event.key.code == sf::Keyboard::T)
    algorithmRunning = false;
  if (algorithmRunning)
    return;
  switch (event.key.code) {
  case sf::Keyboard::S:
    model.shuffle();
    break;
  case sf::Keyboard::Hyphen:
    decreaseModelSize();
    break;
  case sf::Keyboard::Equal:
    increaseModelSize();
    break;
  case sf::Keyboard::Num1:
    runSortingAlgorithm(std::make_unique<BubbleSort>());
    break;
  case sf::Keyboard::Num2:
    runSortingAlgorithm(std::make_unique<SelectionSort>());
    break;
  case sf::Keyboard::Num3:
    runSortingAlgorithm(std::make_unique<InsertionSort>());
    break;
  case sf::Keyboard::Num4:
    runSortingAlgorithm(std::make_unique<MergeSort>());
    break;
  default:
    break;
  }
}
