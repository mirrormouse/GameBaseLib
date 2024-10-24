#include "Grid.h"
#include <algorithm>
#include <stdexcept>

Grid::Grid(int width, int height, float cellWidth, float cellHeight, const Point& origin)
    : width(width), height(height), cellWidth(cellWidth), cellHeight(cellHeight), origin(origin)
{
}

Point Grid::gridToScreen(int x, int y) const
{
    return Point{
        origin.x + x * cellWidth,
        origin.y + y * cellHeight 
    };
}

void Grid::screenToGrid(const Point& screenPos, int& x, int& y) const
{
    x = static_cast<int>((screenPos.x - origin.x) / cellWidth);
    y = static_cast<int>((screenPos.y - origin.y) / cellHeight); 
}

bool Grid::isInBounds(int x, int y) const
{
    return x >= 0 && x < width&& y >= 0 && y < height;
}

void Grid::addStateLayer(const std::string& layerName, const std::vector<std::vector<int>>& initialState) {
    if (initialState.size() != height || initialState[0].size() != width) {
        throw std::invalid_argument("Initial state dimensions do not match grid dimensions");
    }
    stateLayers[layerName] = initialState;
}

void Grid::updateState(const std::string& layerName, int x, int y, int newState) {
    if (!isInBounds(x, y)) {
        throw std::out_of_range("Coordinates out of grid bounds");
    }
    if (stateLayers.find(layerName) == stateLayers.end()) {
        throw std::invalid_argument("State layer does not exist");
    }
    stateLayers.at(layerName).at(y).at(x) = newState;
}

int Grid::getState(const std::string& layerName, int x, int y) const {
    if (!isInBounds(x, y)) {
        throw std::out_of_range("Coordinates out of grid bounds");
    }
    if (stateLayers.find(layerName) == stateLayers.end()) {
        throw std::invalid_argument("State layer does not exist");
    }
    return stateLayers.at(layerName).at(y).at(x);
}