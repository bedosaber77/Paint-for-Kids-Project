#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

bool isPointInsideRectangle(const Point& P, const Point& Corner1, const Point& Corner2) {
    return (P.y >= std::min(Corner1.y, Corner2.y) && P.y <= std::max(Corner1.y, Corner2.y)) &&
           (P.x >= std::min(Corner1.x, Corner2.x) && P.x <= std::max(Corner1.x, Corner2.x));
}

int main() {
    // Example usage for a rectangle with corners Corner1 and Corner2
    Point Corner1 = {0.0, 0.0};
    Point Corner2 = {5.0, 3.0};  // Assuming a rectangle with opposite corners

    Point P = {2.0, 2.0};   // The point to check

    if (isPointInsideRectangle(P, Corner1, Corner2)) {
        std::cout << "The point is inside the rectangle." << std::endl;
    } else {
        std::cout << "The point is outside the rectangle." << std::endl;
    }

    return 0;
}
