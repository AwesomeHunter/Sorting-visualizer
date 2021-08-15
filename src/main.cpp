#include "controller.hpp"

int main() {
  Controller app;
  while (app.isAppRunning()) {
    app.update();
  }
}