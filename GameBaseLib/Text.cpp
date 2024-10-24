#include "Text.h"
#include "GameMain.h"
#include "CoordinateConverter.h"
#include <GLFW/glfw3.h>

Text::Text(GameMain* gameMain, const std::string& text, float x, float y, FT_Face face)
    : GameObject(0), gameMain(gameMain) {
    float normalizedX, normalizedY;
    CoordinateConverter::PixelToNormalized(gameMain->GetWindow(), x, y, normalizedX, normalizedY);
    textDisplay = std::make_unique<TextDisplay>(text, normalizedX, normalizedY, face);
    SetColor(1.0f, 1.0f, 1.0f);  // デフォルトの色を白に設定
    textDisplay->change_interval(0.0022f, 0.0022f);
    textContent = text;
}

void Text::Start() {
    // 初期化が必要な場合はここに実装
}

void Text::Update() {
    // 更新が必要な場合はここに実装
}

void Text::FixedUpdate() {
    // 固定更新が必要な場合はここに実装
}

void Text::Draw() {
    // テキストの描画前にブレンディングを設定
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    textDisplay->display();
    // ブレンディングを無効化（オプション）
    glDisable(GL_BLEND);
}

void Text::SetText(const std::string& text) {
    textDisplay->change_string(text);
    textContent = text;
}

void Text::SetPosition(float x, float y) {
    float normalizedX, normalizedY;
    CoordinateConverter::PixelToNormalized(gameMain->GetWindow(), x, y, normalizedX, normalizedY);
    textDisplay->change_place(normalizedX, normalizedY);
}

void Text::SetColor(float r, float g, float b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
    textDisplay->set_color(r, g, b);
}

void Text::SetInterval(float x, float y) {
    textDisplay->change_interval(x, y);
}

std::string Text::GetText() {
    return textContent;
}