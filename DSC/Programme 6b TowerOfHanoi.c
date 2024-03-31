#include <stdio.h>

void ToH(int n, char A, char B, char C);

int main() {
    int n;
    printf("Enter the number of rings: ");
    scanf("%d", &n);
    ToH(n, 'A', 'C', 'B');
    return 0;
}

void ToH(int n, char A, char C, char B) {
    if (n == 1) {
        printf("Move ring 1 from %c to %c\n", A, C);
        return;
    }
    ToH(n - 1, A, B, C);
    printf("Move ring %d from %c to %c\n", n, A, C);
    ToH(n - 1, B, C, A);
}
