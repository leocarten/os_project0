#include <stdio.h>

void switchValues(int *a, int *b) {
    int placeHolder = *a;
    *a = *b;
    *b = placeHolder;
}

int main() {
    int a = 21;
    int b = 950;    
    printf("Before we call the switchValues function, a=%d, and b=%d.\n", a, b);
    switchValues(&a, &b);
    printf("After we call the switchValues function, a=%d, and b=%d.\n", a, b);
    return 0;
}
