#include <stdio.h>
#include <math.h>

int point_ring_relation(float cx, float cy, float inner_radius, float external_radius, float px, float py);

int main(void) {
	printf("%d", point_ring_relation(0,0,3,2,7,19));
	return 0;
}

int point_ring_relation(float cx, float cy, float inner_radius, float external_radius, float px, float py) {
	float pointLength = (cx - px) * (cx - px) + (cy - py) * (cy - py); // length from middle to point;
	float squareExternalRadius = external_radius * external_radius;
	float squareInnerRadius = inner_radius * inner_radius;

	if (pointLength > squareExternalRadius || pointLength < squareInnerRadius) {
		return 1; // outside the ring or inside the hole
	}
	if (pointLength > squareInnerRadius && pointLength < squareExternalRadius) {
		return -1; // inside the ring
	}
	return 0;
}