#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* address;
    int x, y;
} Address;

int abs_value(int number) {
    if (number < 0) number = -number;
    return number;
}

int getManhattanDistance(Address* from, Address* to) {
    return abs_value(from->x - to->x) + abs_value(from->y - to->y);
}

int getGoogleMapsRoute(Address* start, Address* end) {
    // Google Maps doesn't provide an official API for routing requests
    // between arbitrary addresses. To achieve this functionality, we
    // can utilize an unofficial API or implement our own routing
    // algorithm, such as the A* search algorithm.
    // 
    // However, as per the usage guidelines, the best approach is to
    // redirect the user to the official Google Maps application
    // on their device, with the appropriate start and end coordinates.

    printf("Building route from %s to %s\n", start->address, end->address);
    return getManhattanDistance(start, end);
}

int main() {
    printf("START\n\n");
    Address start = {"123 Main St, Anytown, USA", 10, 20};
    Address end = {"456 Central Ave, Anytown, USA", 30, 40};

    int distance = getGoogleMapsRoute(&start, &end);
    printf("Route distance: %d\n", distance);

    system("pause");
    return 0;
}