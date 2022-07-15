#include <stdio.h>
#include <math.h>

struct Circle {
	int x;
	int y;
	float radius;
};

enum Intersection {
	NONE,
	PARTIAL,
	CONTAINS
};

Intersection circles_intersect(Circle c1, Circle c2);

int main(void) {
	Circle c1 { 0, 5, 5 };
	Circle c2 { 0, 10, 3 };
	printf("%d", circles_intersect(c1, c2));
	return 0;
}

Intersection circles_intersect(Circle c1, Circle c2) {
	float distance_squared = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);

	if ((c1.radius + c2.radius) * (c1.radius + c2.radius) > distance_squared || (c1.x == c2.x && c1.y == c2.y)) {
		return CONTAINS;
	}
	if ((c1.radius + c2.radius) * (c1.radius + c2.radius) < distance_squared) {
		return NONE;
	}
	return PARTIAL;
}