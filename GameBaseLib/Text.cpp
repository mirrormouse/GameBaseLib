#include "Text.h"
#include "GameMain.h"
#include "CoordinateConverter.h"
#include <GLFW/glfw3.h>

Text::Text(GameMain* gameMain, const std::string& text, float x, float y, FT_Face face)
    : GameObject(0), gameMain(gameMain) {
    float normalizedX, normalizedY;
    CoordinateConverter::PixelToNormalized(gameMain->GetWindow(), x, y, normalizedX, normalizedY);
    textDisplay = std::make_unique<TextDisplay>(text, normalizedX, normalizedY, face);
    SetColor(1.0f, 1.0f, 1.0f);  // �f�t�H���g�̐F�𔒂ɐݒ�
    textDisplay->change_interval(0.0022f, 0.0022f);
    textContent = text;
}

void Text::Start() {
    // ���������K�v�ȏꍇ�͂����Ɏ���
}

void Text::Update() {
    // �X�V���K�v�ȏꍇ�͂����Ɏ���
}

void Text::FixedUpdate() {
    // �Œ�X�V���K�v�ȏꍇ�͂����Ɏ���
}

void Text::Draw() {
    // �e�L�X�g�̕`��O�Ƀu�����f�B���O��ݒ�
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    textDisplay->display();
    // �u�����f�B���O�𖳌����i�I�v�V�����j
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