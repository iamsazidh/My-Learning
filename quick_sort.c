#include <stdio.h>

int partition(int A[], int low, int high){
    int i, j, temp;
    int pivot = A[high];
    for(i = low - 1, j = low; j < high; j++){
        if(A[j] < pivot){
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = A[high];
    A[high] = A[i + 1];
    A[i+1] = temp;

    return i + 1;
}

void quick_sort(int A[], int low, int high){
    if(low >= high){
        return;
    }
    int p = partition(A, low, high);
    quick_sort(A, low, p - 1);
    quick_sort(A, p + 1, high);
    return;
}

int main(){
    int n = 10;
    int A[] = {9, 5, 36, 41, 57, 61, 57, 5, 31, 28};
    quick_sort(A, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}