#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>

struct Skyscrapper {
	int x;
	int y;
	int width;
	int height;
	Color color;
};

struct Window {
	int x;
	int y;
	int width;
	int height;
	int offset;
	Color color;
};


int main(void) {
	srand(1);

	const int windowWidth = 1280;
	const int windowHeight = 720;

	InitWindow(windowWidth, windowHeight, "skyscrapper");
	SetTargetFPS(10);

	while (true) {
		
		if (WindowShouldClose()) {
			break;
		}
		if (IsKeyPressed(KEY_F)) {
			ToggleFullscreen();
		}

		BeginDrawing();
		ClearBackground(BLACK);

		Skyscrapper skyscrapper{
			windowWidth / 2,
			20,
			300,
			windowHeight,
			GRAY,
		};

		DrawRectangle(skyscrapper.x, skyscrapper.y, skyscrapper.width, skyscrapper.height, skyscrapper.color); // draw skyscrapper

		Window window {
			skyscrapper.x + 10,
			skyscrapper.x + 35,
			20,
			40,
			50,
			BLACK,
		};

		Color lightsOff = BLACK;
		Color lightsOn = YELLOW;

		for (int j = 0; j < 14; j++, window.y -= window.offset) {
			window.x = skyscrapper.x + 15;
			
			for (int i = 0; i < 6; i++, window.x += window.offset) {
				int randColor = rand() % 5;
				switch (randColor) {
				case 1:
					window.color = BLACK;
					break;
				case 0:
					window.color = lightsOn;
					break;
				default:
					window.color = lightsOn;
					break;
				}
				DrawRectangle(window.x, window.y, window.width, window.height, window.color);
			}
		}
		DrawFPS(0, 0);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}