#include <stdio.h>

int main() {
    int b[10][10], b1[10][10], b2[10][10], i, j, k = 1, t = -1, m, n, p, l;
    printf("Enter the rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Original matrix is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (b[i][j] != 0) {
                b1[k][0] = i;
                b1[k][1] = j;
                b1[k][2] = b[i][j];
                k++;

                if (j > t) {
                    t = j;
                }
            }
        }
    }

    b1[0][0] = m;
    b1[0][1] = n;
    b1[0][2] = k - 1;

    printf("Sparse matrix is:\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", b1[i][0], b1[i][1], b1[i][2]);
    }

    p = 1;
    l = k - 1;
    printf("Non zero = %d\n", l);

    for (i = 0; i <= t; i++) {
        k = 1;
        for (j = 1; j <= l; j++) {
            if (b1[k][1] == i) {
                b2[p][0] = b1[k][0];
                b2[p][1] = b1[k][1];
                b2[p][2] = b1[k][2];
                k++;
                p++;
            } else {
                k++;
            }
        }
    }

    b2[0][0] = n;
    b2[0][1] = m;
    b2[0][2] = l;

    printf("Transpose of Sparse matrix is:\n");
    for (i = 0; i <= l; i++) {
        printf("%d\t%d\t%d\n", b2[i][0], b2[i][1], b2[i][2]);
    }

    return 0;
}
