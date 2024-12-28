#include <stdio.h>
#define MAX 100
int array[MAX][MAX];
int col, row;

void inputArray(int col, int row);
void printArray(int col, int row);
void printCornerArray(int col, int row);
void printEdgeArray(int col, int row);
void printDiagonalArray(int col, int row);
void printPrimeArray(int col, int row);

int main() {
    while (true) {
        printf("\n=================MENU=================\n");
        printf("1. Nhập giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In ra các phần tử ở góc theo ma trận\n");
        printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7. Thoát\n");
        int choose;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Nhap so cot: ");
            scanf("%d", &col);
            printf("Nhap so hang: ");
            scanf("%d", &row);
            inputArray(col, row);
            break;
        case 2:
            printArray(col, row);
            break;
        case 3:
            printCornerArray(col, row);
            break;
        case 4:
            printEdgeArray(col, row);
            break;
        case 5:
            printDiagonalArray(col, row);
            break;
        case 6:
            printPrimeArray(col, row);
            break;
        case 7:
            break;
        default:
            printf("Lua chon ko hop le");
            break;
        }
        if (choose == 7) {
            break;
        }
    }
}


void inputArray(int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("array[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}
void printArray(int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void printCornerArray(int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if ((i == 0 || i == col - 1) && (j == 0 || j == row - 1)) {
                printf("%d ", array[i][j]);
            }else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void printEdgeArray(int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (i == 0 || i == col - 1 || j == 0 || j == row - 1) {
                printf("%d ", array[i][j]);
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void printDiagonalArray(int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (i == j || i+j == col-1) {
                printf("%d ", array[i][j]);
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void printPrimeArray(int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            int check = 1;
            if (array[i][j] < 2) {
                check = 0;
            }else {
                for (int k = 2; k*k <= array[i][j]; k++) {
                    if (array[i][j] % k == 0) {
                        check = 0;
                        break;
                    }
                }
            }
            if (check) {
                printf("%d ", array[i][j]);
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return;
}