#include <stdio.h>

int main() {
    int x = -5;  // Negative number
    int y = 10;  // Positive number
    
    int result = x && y;  // Logical AND operation
    
    printf("x: %d, y: %d\n", x, y);
    printf("Result of x && y: %d\n", result);  // Should print 1 (true)

    return 0;
}
