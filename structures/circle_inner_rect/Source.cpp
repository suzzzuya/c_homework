#include <stdio.h>
#include <math.h>

struct Rect {
	int x;
	int y;
	float width;
	float height;
};

struct Circle {
	int x;
	int y;
	float radius;
};

Rect circle_inner_rect(Circle c);

int main(void) {
	Circle c{ 0, 0, 5 };
	Rect rect = circle_inner_rect(c);
	return 0;
}

Rect circle_inner_rect(Circle c) {
	float diagonal = c.radius * 2;
	Rect rect{ 0 };
	rect.width = diagonal * sqrt(2) / 2;
	rect.height = diagonal * sqrt(2) / 2;
	rect.x = c.x - rect.width / 2;
	rect.y = c.y + rect.height / 2;

	return rect;
}