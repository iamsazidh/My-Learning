#include <stdio.h>


int main(){
    int i, j, len, item;
    int arr[] = {5,8,3,88,46,27,48,467,56,58,568,578,5878};
    len = sizeof(arr) / sizeof(arr[0]);

    for(i = 1; i < len; i++){
        item = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = item;
        
    }

    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}