#include <stdio.h>

void main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
}

// Merge sort function inside main
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// Merge function inside main
void merge(int arr[], int l, int m, int r)
{
    int i = 0, j = 0, k = l;
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = j = 0;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    // Print array function inside main
    void print(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    printf("Original array: ");
    print(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    print(arr, n);
    getch();
}
