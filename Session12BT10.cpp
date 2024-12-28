#include <stdio.h>
#define MAX 100
int array[MAX];
int size = 0;
int check = 0;

void inputArray();
void printArray();
void insertArray(int pos, int value);
void editArray(int pos, int value);
void deleteArray(int pos);
void sortArrayDown();
void sortArrayUp();
void findArrayLinear(int value);
void findArrayBinary(int value);

int main() {
    while (true) {
        printf("\n=================MENU=================\n");
        printf("1. Nhập số phần tử cần nhập và giá trị các phần tử\n");
        printf("2. In ra giá trị các phần tử đang quản lý\n");
        printf("3. Thêm một phần từ vào vị trí chỉ định\n");
        printf("4. Sửa một phần từ ở vị trí chỉ định\n");
        printf("5. Xóa một phần từ ở vị trí chỉ định\n");
        printf("6. Sắp xếp các phần tử\n");
        printf("7. Tìm kiếm phần tử nhập vào\n");
        printf("8. Thoát\n");
        int choose;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            inputArray();
            break;
        case 2:
            printArray();
            break;
        case 3: {
            if (size == 0) {
                printf("Ban chua nhap phan tu vao mang");
                break;
            }
            check = 0;
            int pos, value;
            printf("Nhap vi tri ban muon chen: ");
            scanf("%d", &pos);
            printf("Nhap gia tri ban muon chen: ");
            scanf("%d", &value);
            insertArray(pos, value);
            break;
        }
        case 4: {
            if (size == 0) {
                printf("Ban chua nhap phan tu vao mang");
                break;
            }
            check = 0;
            int pos, value;
            printf("Nhap vi tri ban muon sua: ");
            scanf("%d", &pos);
            printf("Nhap gia tri ban muon sua: ");
            scanf("%d", &value);
            editArray(pos, value);
            break;
        }
        case 5: {
            if (size == 0) {
                printf("Ban chua nhap phan tu vao mang");
                break;
            }
            check = 0;
            int pos;
            printf("Nhap vi tri ban muon xoa: ");
            scanf("%d", &pos);
            deleteArray(pos);
            break;
        }
        case 6: {
            if (size == 0) {
                printf("Ban chua nhap phan tu vao mang");
                break;
            }
            check = 1;
            printf("a. Giam dan\n");
            printf("b. Tang dan\n");
            char select;
            printf("Nhap lua chon cua ban: ");
            scanf(" %c", &select);
            if(select == 'a') {
                sortArrayDown();
            }else if (select == 'b') {
                sortArrayUp();
            }else {
                printf("Lua chon cua ban ko hop le");
                break;
            }
            break;
        }
        case 7: {
            if (size == 0) {
                printf("Ban chua nhap phan tu vao mang");
                break;
            }
            printf("a. Tim kiem tuyen tinh\n");
            printf("b. Tim kiem nhi phan\n");
            char select;
            printf("Nhap lua chon cua ban: ");
            scanf(" %c", &select);
            int value;
            if(select == 'a') {
                printf("Nhap gia tri ban muon tim kiem: ");
                scanf("%d", &value);
                findArrayLinear(value);
            }else if (select == 'b') {
                if (check == 0) {
                    printf("Ban chua sap xep mang");
                    break;
                }
                printf("Nhap gia tri ban muon tim kiem: ");
                scanf("%d", &value);
                findArrayBinary(value);
            }else {
                printf("Lua chon cua ban ko hop le");
                break;
            }
            break;
        }
        case 8:
            break;
        default:
            printf("Lua chon ko hop le");
            break;
        }
        if (choose == 8) {
            break;
        }
    }
}


void inputArray() {
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}
void printArray() {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}
void insertArray(int pos, int value) {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    check = 0;
    for (int i = size; i > pos; i--) {
        array[i] = array[i-1];
    }
    size++;
    array[pos] = value;
    return;
}
void editArray(int pos, int value) {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    check = 0;
    array[pos] = value;
    return;
}
void deleteArray(int pos) {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    for (int i = pos; i < size; i++) {
        array[i] = array[i+1];
    }
    size--;
    return;
}
void sortArrayDown() {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    check = 1;
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void sortArrayUp() {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    check = 1;
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void findArrayLinear(int value) {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            printf("Gia tri %d o vi tri %d", value, i);
            return;
        }
    }
    printf("Gia tri %d ko co trong mang", value);
    return;
}
void findArrayBinary(int value) {
    if (size == 0) {
        printf("Ban chua nhap phan tu cho mang");
        return;
    }
    if (check == 0) {
        printf("Ban chua sap xep mang");
        return;
    }
    int l = 0;
    int r = size-1;
    while (l <= r) {
        int m = (l + (r-l))/2;
        if (value = array[m]) {
            printf("Gia tri %d o vi tri %d", value, m);
            return;
        }else if (value > array[m]) {
            l = m+1;
        }else {
            r = m-1;
        }
    }
    printf("Gia tri %d ko co trong mang\n", value);
    return;
}