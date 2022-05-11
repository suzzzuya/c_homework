#include <stdio.h>

enum Relation {
    INSIDE,
    OUTSIDE,
    RIM
};

Relation point_rect_relation(float rx1, float ry1, float rx2, float ry2, float px, float py);
Relation point_circle_relation(float cx, float cy, float radius, float px, float py);
Relation point_ring_relation(float cx, float cy, float inner_radius, float external_radius, float px, float py);

int main(void) {
    printf("%d\n", point_rect_relation(2, 6, 7, 1, 2, 3));
    printf("%d\n", point_circle_relation(0, 0, 2, -2, 1));
    printf("%d\n", point_ring_relation(0, 0, 3, 2, 7, 19));

    return 0;
}

Relation point_rect_relation(float rx1, float ry1, float rx2, float ry2, float px, float py) {
    if (px > rx1 && py < rx2 && px < rx2 && py > ry2) {
        return INSIDE;
    }
    if ((ry1 <= py && py <= ry2) && (px == rx1 || px == rx2) || (rx1 <= px && px <= rx2) && (py == ry1 || py == ry2)) {
        return RIM;
    }
    return OUTSIDE;
}

Relation point_circle_relation(float cx, float cy, float radius, float px, float py) {
    float circleEquation = (px - cx) * (px - cx) + (py - cy) * (py - cy);
    const float EPSILON = 0.0001;
    if (circleEquation > radius * radius - EPSILON && circleEquation < radius * radius + EPSILON) {
        return RIM;
    }
    if (circleEquation > radius * radius) {
        return OUTSIDE;
    }
    if (circleEquation < radius * radius) {
        return INSIDE;
    }
}

Relation point_ring_relation(float cx, float cy, float inner_radius, float external_radius, float px, float py) {
    float pointLength = (cx - px) * (cx - px) + (cy - py) * (cy - py); // length from middle to point;
    float squareExternalRadius = external_radius * external_radius;
    float squareInnerRadius = inner_radius * inner_radius;

    if (pointLength > squareExternalRadius || pointLength < squareInnerRadius) {
        return OUTSIDE; // outside the ring or inside the hole
    }
    if (pointLength > squareInnerRadius && pointLength < squareExternalRadius) {
        return INSIDE; // inside the ring
    }
    return RIM;
}