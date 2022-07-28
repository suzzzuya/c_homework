#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "raylib.h"

int main(void) {
	const int windowWidth = 1280;
	const int windowHeight = 720;

	InitWindow(windowWidth, windowHeight, "chess_board");
	SetTargetFPS(60);

	while (true) {
		if (WindowShouldClose()) {
			break;
		}
		if (IsKeyPressed(KEY_F)) {
			ToggleFullscreen();
		}

		BeginDrawing();
		ClearBackground(BLACK);

		Color squareColor = WHITE;
		int colorNum = 0;

		for (int i = 0, rx = 0, ry = 0; i < 8; i++, ry += 720 / 8) {
			rx = 0;
			colorNum++;
			for (int j = 0; j < 8; j++, rx += 1280 / 8, colorNum++) {
				if (colorNum % 2 == 0) {
					squareColor = WHITE;
				} else {
					squareColor = BROWN;
				}
				DrawRectangle(rx, ry, 1280 / 8, 720 / 8, squareColor);
			}
		}
		DrawFPS(0, 0);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}