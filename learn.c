#include <stdio.h>

void print_heap(int heap[], int n){
    for(int i = 1; i <= n; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int left(int n){
    return n*2;
}
int right(int n){
    return 2 * n + 1;
}
int parent(int n){
    return n / 2;
}

int isMaxHeap(int heap[], int n){
    for(int i = n; i > 1; i--){
        if(heap[i] > heap[parent(i)]){
            printf("It's not a heap!\n");
            return 0;
        }
    }
    printf("It's a heap!\n");
    return 1;
}

void max_heapify(int heap[], int i, int n){
    int l, r, largest, temp;
    l = left(i);
    r = right(i);
    if(l <= n && heap[l] > heap[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= n && heap[r] > heap[largest]){
        largest = r;
    }
    if(largest != i){
        temp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = temp;

        max_heapify(heap, largest, n);
    }
}

void build_max_heap(int heap[], int n){
    for(int i = n / 2; i > 0; i--){
        max_heapify(heap, i, n);
    }
}

void heap_sort(int heap[], int n){
    int temp;
    for(int i = n; i > 1; i--){
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;
        n--;
        max_heapify(heap, 1, n);
    }
}

int get_maximum(int heap[]){
    return heap[1];
}
int exact_max(int heap[],int heap_size){
    int max_item = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;
    max_heapify(heap, 1, heap_size);
    return heap_size;
}

int insert_node(int heap[], int heap_size, int node){
    int i, p, t;

    heap_size += 1;
    heap[heap_size] = node;
    i = heap_size;
    while (i > 1 && heap[i] > heap[parent(i)]){
        p = parent(i);
        t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

        i = p;
    }
    return heap_size;
}

int main(){
    int n = 10;
    int heap[] = {0, 1, 6, 8, 9, 45, 10, 15, 16, 99, 24};
    print_heap(heap, n);
    isMaxHeap(heap, n);

    build_max_heap(heap, n);
    print_heap(heap, n);
    isMaxHeap(heap, n);
    printf("\nOn the way of heap sort\n");
    heap_sort(heap, n);
    print_heap(heap, n);
    printf("Let's build max heap again!\n");
    build_max_heap(heap, n);
    print_heap(heap, n);
    n = exact_max(heap, n);
    n = insert_node(heap, n, 1000);
    print_heap(heap, n);
    // printf("%d\n", heap[n]);

    return 0;
}