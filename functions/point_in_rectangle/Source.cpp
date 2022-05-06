#include <stdio.h>

int point_rect_relation(float rx1, float ry1, float rx2, float ry2, float px, float py);

int main(void) {
    printf("%d", point_rect_relation(2, 6, 7, 1, 2, 3));
    return 0;
}

int point_rect_relation(float rx1, float ry1, float rx2, float ry2, float px, float py) {
    if (px > rx1 && py < rx2 && px < rx2 && py > ry2) {
        return 1; // inside
    }
    if ((ry1 <= py <= ry2) && (px == rx1 || px == rx2) || (rx1 <= px <= rx2) && (py == ry1 || py == ry2)) {
        return -1; // in perimeter
    }
    return 0; // outside
}