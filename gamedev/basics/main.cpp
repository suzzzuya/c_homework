#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "raylib.h"

Vector2 sumVector(Vector2 vector1, Vector2 vector2);
Vector2 multVector(Vector2 vector1, float scalar);

int main(void) {
	const int windowWidth = 1280;
	const int windowHeight = 720;

	InitWindow(windowWidth, windowHeight, "basics");
	SetTargetFPS(60);

	Vector2 pos = { windowWidth / 2, windowHeight / 2 };
	Vector2 posControl = pos;
	Vector2 direction = { 500 , -500 };

	Color circleColor = RED;

	while (true) {
		pos = sumVector(pos, multVector(direction, GetFrameTime()));
		if (pos.y <= 0 || pos.y >= windowHeight) {
			direction.y *= -1;
		}
		if (pos.x <= 0 || pos.x >= windowWidth) {
			direction.x *= -1;
		}
		if (WindowShouldClose()) {
			break;
		}
		if (IsKeyPressed(KEY_F)) {
			ToggleFullscreen();
		}

		BeginDrawing();

		if (IsKeyPressed(KEY_ONE)) {
			circleColor = RED; // green
		} 
		if (IsKeyPressed(KEY_TWO)) {
			circleColor = GREEN; // blue
		}
		if (IsKeyPressed(KEY_THREE)) {
			circleColor = BLUE; // white
		}
		if (IsKeyPressed(KEY_FOUR)) {
			circleColor = YELLOW; // yellow
		}
		if (IsKeyPressed(KEY_FIVE)) {
			circleColor = WHITE; // yellow
		}

		if (IsKeyPressed(KEY_SPACE)) {
			direction.x *= 1.5;
			direction.y *= 1.5;
		}

		ClearBackground(BLACK);
		DrawCircleV(pos, 50, circleColor);
		DrawCircleV(posControl, 60, BLUE);

		if (IsKeyDown(KEY_W)) {
			posControl.y -= 20;
		}
		if (IsKeyDown(KEY_A)) {
			posControl.x -= 20;
		}
		if (IsKeyDown(KEY_S)) {
			posControl.y += 20;
		}
		if (IsKeyDown(KEY_D)) {
			posControl.x += 20;
		}

		DrawFPS(0,0);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}

Vector2 sumVector(Vector2 vector1, Vector2 vector2) {
	Vector2 vector3;
	vector3.x = vector1.x + vector2.x;
	vector3.y = vector1.y + vector2.y;
	return vector3;
}

Vector2 multVector(Vector2 vector1, float scalar) {
	Vector2 vector2;
	vector2.x = vector1.x * scalar;
	vector2.y = vector1.y * scalar;

	return vector2;
}