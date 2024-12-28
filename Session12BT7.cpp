#include <stdio.h>
void input2DArray(int array[100][100], int col, int row);
void print2DArray(int array[100][100], int col, int row);

int main() {
    int col,row;
    printf("Nhap vao so cot: ");
    scanf("%d", &col);
    printf("Nhap vao so hang: ");
    scanf("%d", &row);
    int array[100][100];

    input2DArray(array, col, row);
    print2DArray(array, col, row);
    return 0;
}
void input2DArray(int array[100][100], int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("array[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    return;
}

void print2DArray(int array[100][100], int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return;
}