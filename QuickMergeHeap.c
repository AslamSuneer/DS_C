#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void heapify(int A[], int n, int i);
void BuildMaxHeap(int A[], int n);
void heapSort(int A[], int n);
void merge(int A[], int low, int mid, int high);
void mergeSort(int A[], int low, int high);
int partition(int A[], int low, int high);
void quickSort(int A[], int low, int high);
void printArray(int A[], int n);

int main() {
    int A[50], n, i;

    // Get array size and elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Choose a sorting algorithm
    printf("Choose a sorting algorithm:\n");
    printf("1. Heap Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Quick Sort\n");

    int choice;
    scanf("%d", &choice);

    // Print array before sorting
    printf("Before sorting array elements are - \n");
    printArray(A, n);

    // Apply the selected sorting algorithm
    switch (choice) {
    case 1:
        heapSort(A, n);
        break;
    case 2:
        mergeSort(A, 0, n - 1);
        break;
    case 3:
        quickSort(A, 0, n - 1);
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    // Print array after sorting
    printf("\nAfter sorting array elements are \n");
    printArray(A, n);

    return 0;
}

// Heap Sort
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}

void BuildMaxHeap(int A[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }
}

void heapSort(int A[], int n) {
    int i;
    BuildMaxHeap(A, n);

    for (i = n - 1; i >= 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}

// Merge Sort
void merge(int A[], int low, int mid, int high) {
    int B[50], x, y, i, j;
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

void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = ceil((low + high) / 2);
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

// Quick Sort
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

void quickSort(int A[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(A, low, high);
        quickSort(A, low, j - 1);
        quickSort(A, j + 1, high);
    }
}

// Print array elements
void printArray(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
