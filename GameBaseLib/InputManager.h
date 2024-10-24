#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <GLFW/glfw3.h>
#include <vector>

#ifdef GAMEBASELIB_EXPORTS
#define GAMEBASELIB_API __declspec(dllexport)
#else
#define GAMEBASELIB_API __declspec(dllimport)
#endif


class GAMEBASELIB_API InputManager {
public:
    InputManager(GLFWwindow* window);

    void Update();
    bool IsMouseButtonPressed(int button) const;
    void GetMousePosition(double& x, double& y) const;

private:
    GLFWwindow* window;
    std::vector<int> pressedButtons;
    double mouseX, mouseY;
};

#endif // INPUT_MANAGER_H