#include <stdio.h>
#include <math.h>

void BubbleSort(int A[], int n) {
    int i, j, temp;
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j <= n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("\nBubbleSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
}

void InsertionSort(int A[], int n) {
    int i, j, temp;
    for (i = 1; i <= n - 1; i++) {
        temp = A[i];
        for (j = i - 1; j >= 0 && A[j] > temp; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = temp;
    }
    printf("\nInsertionSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
}

void SelectionSort(int A[], int n) {
    int i, j, temp;
    for (i = 0; i <= n - 2; i++) {
        for (j = i + 1; j <= n - 1; j++) {
            if (A[i] > A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    printf("\nSelectionSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
}

void Merge(int A[], int low, int mid, int high) {
    int B[10], x, y, i, j;
    x = low;
    y = mid + 1;
    i = low;
    while ((x <= mid) && (y <= high)) {
        if (A[x] < A[y]) {
            B[i] = A[x];
            x++;
        } else {
            B[i] = A[y];
            y++;
        }
        i++;
    }
    if (x <= mid) {
        for (j = x; j <= mid; j++) {
            B[i] = A[j];
            i++;
        }
    } else {
        for (j = y; j <= high; j++) {
            B[i] = A[j];
            i++;
        }
    }
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = ceil((low + high) / 2);
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int partition(int A[], int low, int high) {
    int i, j, pivot, temp;
    i = low;
    j = high;
    pivot = low;
    while (i < j) {
        while (A[i] <= A[pivot])
            i++;
        while (A[j] > A[pivot])
            j--;
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[j];
    A[j] = A[pivot];
    A[pivot] = temp;
    return j;
}

void QuickSort(int A[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(A, low, high);
        QuickSort(A, low, j - 1);
        QuickSort(A, j + 1, high);
    }
}

int main() {
    int A[10], n, opt, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("\nEnter the option:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n");
    scanf("%d", &opt);
    switch (opt) {
    case 1:
        BubbleSort(A, n);
        break;
    case 2:
        InsertionSort(A, n);
        break;
    case 3:
        SelectionSort(A, n);
        break;
    case 4:
        MergeSort(A, 0, n - 1);
        printf("\nSorted Array: ");
        for (i = 0; i < n; i++)
            printf("%d\t", A[i]);
        break;
    case 5:
        QuickSort(A, 0, n - 1);
        printf("\nSorted Array: ");
        for (i = 0; i < n; i++)
            printf("%d\t", A[i]);
        break;
    }
    return 0;
}
