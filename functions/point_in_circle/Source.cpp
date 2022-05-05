#include <stdio.h>

int point_circle_relation(float cx, float cy, float radius, float px, float py);

int main(void) {
	printf("%d", point_circle_relation(0, 0, 2, -2, 1));
}

int point_circle_relation(float cx, float cy, float radius, float px, float py) {
	float circleEquation = (px - cx) * (px - cx) + (py - cy) * (py - cy);
	const float EPSILON = 0.0001;
	if (circleEquation > radius * radius - EPSILON && circleEquation < radius * radius + EPSILON) {
		return 0;
	}
	if (circleEquation > radius * radius) {
		return 1;
	}
	if (circleEquation < radius * radius) {
		return -1;
	}
}