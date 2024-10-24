#include "Scene.h"
#include "GameMain.h"
#include <algorithm>
#include <iostream>

Scene::Scene(GameMain* gameMain) : gameMain(gameMain) {}

void Scene::Loop() {
    // このメソッドは空。ユーザーが継承クラスで実装。
}

void Scene::FixedLoop() {
    // このメソッドは空。ユーザーが継承クラスで実装。
}

void Scene::FixedObjectUpdate() {
    for (auto& gameObject : gameObjects) {
        gameObject->Update();
        gameObject->CheckAndCallFixedUpdate();
        gameObject->Draw();
    }
}

void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.push_back(gameObject);
    gameObject->Start();
}

void Scene::RemoveGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.erase(
        std::remove(gameObjects.begin(), gameObjects.end(), gameObject),
        gameObjects.end()
    );
}