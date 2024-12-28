#include <stdio.h>
int GCD(int a, int b);

int main() {
    int a,b;
    printf("Nhap so thu 1: ");
    scanf("%d", &a);
    printf("Nhap so thu 2: ");
    scanf("%d", &b);
    printf("GCD(a,b) = %d", GCD(a,b));
    return 0;
}
int GCD(int a, int b) {
    int res = (a<b)? a:b;
    for (int i = res; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}