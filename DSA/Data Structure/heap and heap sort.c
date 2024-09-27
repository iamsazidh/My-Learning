#include <stdio.h>

int left(int i){
    return 2*i;
}
int right(int i){
    return 2 * i + 1;
}
int parent(int i){
    return i / 2;
}

int is_max_heap(int H[], int heap_size){
    int i, p;

    for(i = heap_size; i > 1; i--){
        p = parent(i);
        if(H[p] < H[i]){
            return 0;
        }
    }
    return 1;
}

void max_heapify(int heap[], int heap_size, int i){
    int l, r, largest, temp;
    l = left(i);
    r = right(i);

    if(l <= heap_size && heap[i] < heap[l]){
        largest = l;
    }else{
        largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest]){
        largest = r;
    }

    if(largest != i){
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        max_heapify(heap, heap_size, largest);
    }
}

void build_max_heap(int heap[], int heap_size){
    int i;

    for(i = heap_size/2; i >=1; i--){
        max_heapify(heap, heap_size, i);
    }
}

void print_heap(int heap[], int heap_size){
    int i;
    for(i = 1; i <=heap_size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

void heap_sort(int heap[], int heap_size){
    int i, t;
    for(i = heap_size; i > 1; i--){
        t = heap[1];
        heap[1] = heap[i];
        heap[i] = t;
        heap_size--;
        max_heapify(heap, heap_size, 1);
    }
}

int main(){
    int heap_size = 9;
    int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};
    if(is_max_heap(heap, heap_size)){
        printf("This is a max heap.\n");
    }else{
        printf("This isn't a max heap.\n");
    }

    build_max_heap(heap, heap_size);

    if(is_max_heap(heap, heap_size)){
        printf("This is a max heap.\n");
    }else{
        printf("This isn't a max heap.\n");
    }
    heap_sort(heap, heap_size);
    if(is_max_heap(heap, heap_size)){
        printf("This is a max heap.\n");
    }else{
        printf("This isn't a max heap.\n");
    }
    print_heap(heap, heap_size);


    return 0;
}