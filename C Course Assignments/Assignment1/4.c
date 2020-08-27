// (4) Write a program that reads the radius of a circle and
// calculates the area and circumference then prints the
// results.


#include "stdio.h"
#include "math.h"

double get_area (double);
double get_circumference (double);

int main (void) {

    float radius = 4;

    printf("For The Circle with Radius %.2f."
           "\n"
           "The Area is %.2f."
           "\n"
           "The Circumference is %.2f."
           "\n", radius, get_area(radius), get_circumference(radius));

    return 0;
}

double get_area (double radius) {
    return M_PI * radius * radius;
}

double get_circumference (double radius) {
    return 2 * M_PI * radius;
}
