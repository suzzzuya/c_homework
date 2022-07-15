#include <stdio.h>
#include <math.h>

struct Rect {
	int x1;
	int y1;
	float width;
	float height;
};

struct Circle {
	int x;
	int y;
	float radius;
};

Rect circle_bounding_rect(Circle c);

int main(void) {
	Circle c{ 0, 0, 5 };
	Rect rect = circle_bounding_rect(c);
	return 0;
}

Rect circle_bounding_rect(Circle c) {
	Rect rect{ 0 };
	rect.x1 += c.x - c.radius;
	rect.y1 -= c.y + c.radius;
	rect.width = c.radius * 2;
	rect.height = c.radius * 2;

	return rect;
}