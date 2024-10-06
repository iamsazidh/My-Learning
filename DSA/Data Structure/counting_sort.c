#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int A[], int n, int m){
    int counter[m + 1];
    memset(counter, 0, (m + 1) * sizeof(int));
    for(int i = 0; i < n; i++){
        counter[A[i]]++;
    }
    for(int i = 0, j = 0; i <= m; i++){
        while ((counter[i]--))
        {
            A[j] = i; j++;
        }
        
    }
    return;
}

int main(){
    int n = 10, limit = 99;
    int A[] = {9, 5, 36, 41, 57, 61, 57, 5, 31, 28};
    counting_sort(A, n, limit);

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}