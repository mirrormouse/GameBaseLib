#include "InputManager.h"
#include <algorithm>
#include <iostream>

InputManager::InputManager(GLFWwindow* window) : window(window), mouseX(0), mouseY(0) {}

void InputManager::Update() {
    pressedButtons.clear();
    for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; ++i) {
        if (glfwGetMouseButton(window, i) == GLFW_PRESS) {
            pressedButtons.push_back(i);
        }
    }
    glfwGetCursorPos(window, &mouseX, &mouseY);
}

bool InputManager::IsMouseButtonPressed(int button) const {
    return std::find(pressedButtons.begin(), pressedButtons.end(), button) != pressedButtons.end();
}

void InputManager::GetMousePosition(double& x, double& y) const {
    x = mouseX;
    y = mouseY;
}