#pragma once
#ifndef GRID_H
#define GRID_H

#include "Shape.h"
#include <vector>
#include <string>
#include <map>

#ifdef GAMEBASELIB_EXPORTS
#define GAMEBASELIB_API __declspec(dllexport)
#else
#define GAMEBASELIB_API __declspec(dllimport)
#endif

class GAMEBASELIB_API Grid {
public:
    Grid(int width, int height, float cellWidth, float cellHeight, const Point& origin);

    // グリッド座標から実際の描画座標への変換
    Point gridToScreen(int x, int y) const;

    // 実際の描画座標からグリッド座標への変換
    void screenToGrid(const Point& screenPos, int& x, int& y) const;
    std::pair<int, int> screenToGrid(const Point& screenPos) const;

    // クリックされたグリッド座標を返す
    std::vector<std::pair<int, int>> getPressedGrid(GameMain* gameMain, bool clickonly = false, int button = GLFW_MOUSE_BUTTON_LEFT);


    // グリッドの範囲内かどうかをチェック
    bool isInBounds(int x, int y) const;

    // グリッドのサイズを取得
    int getWidth() const { return width; }
    int getHeight() const { return height; }


    // セルのサイズを取得
    float getCellWidth() const { return cellWidth; }
    float getCellHeight() const { return cellHeight; }


    void addStateLayer(const std::string& layerName, const std::vector<std::vector<int>>& initialState);
    void updateState(const std::string& layerName, int x, int y, int newState);
    int getState(const std::string& layerName, int x, int y) const;

private:
    int width;  // グリッドの横のマス数
    int height;  // グリッドの縦のマス数
    float cellWidth;  // 1マスの横幅
    float cellHeight;  // 1マスの縦幅
    Point origin;  // グリッドの原点（左上）の実際の描画座標

    std::map<std::string, std::vector<std::vector<int>>> stateLayers;//状態情報を保持

};

#endif // GRID_H