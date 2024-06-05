/*
 *该程序实现对二维数组任意元素A[m,n]的访问
 *
 */



#include <stdio.h>

int two_dim_array_access(int *x, int i, int j, int m, int n, int C) {
    int d = m * C + n;//d为较第一个元素地址的偏移量
    return d;
}

int main() {

    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int v1 = two_dim_array_access(&A[0][0], 0, 0, 1, 2, 3);
    printf("two_dim_array_access(&A[0][0], 0, 0, 1, 2, 3)): %d\n", v1);

    int v2 = two_dim_array_access(&A[1][2], 1, 2, 1, 2, 3);
    printf("two_dim_array_access(&A[1][2], 1, 2, 1, 2, 3)): %d\n", v2);

    return 0;
}

