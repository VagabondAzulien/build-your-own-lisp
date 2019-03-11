#include <stdio.h>

int n_world (int n) {
    int x = 0;
    while (x < n) {
        puts("Howdy, Earth.");
        x++;
    }
    return 0;
}

int main(int argc, char** argv) {
    n_world(10);
    return 0;
}
