#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint(float x, float y) {
    Point new;
    new.x = x;
    new.y = y;
    return new;
}

Line makeLine(Point p1, Point p2) {
    Line new;
    new.p[0] = p1;
    new.p[1] = p2;
    return new;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle new;
    new.p[0] = p1;
    new.p[1] = p2;
    new.p[2] = p3;
    return new;
}

float lineLength(Line l) {
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;
    return sqrt(dx * dx + dy * dy);
}

float triangleArea(Triangle t) {
    float x1 = t.p[0].x;
    float y1 = t.p[0].y;
    float x2 = t.p[1].x;
    float y2 = t.p[1].y;
    float x3 = t.p[2].x;
    float y3 = t.p[2].y;

    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool samePoint(Point p1, Point p2) {
    return fabs(p1.x - p2.x) < 1.0e-6 && fabs(p1.y - p2.y) < 1.0e-6;
}

bool pointInLine(Point p, Line l) {
    return samePoint(p, l.p[0]) || samePoint(p, l.p[1]);
}

bool pointInTriangle(Point p, Triangle t) {
    return samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2]);
}