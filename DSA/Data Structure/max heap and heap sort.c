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

int insert_heap(int heap[], int length, int item){
    int temp, index;
    length++;
    heap[length] = item;
    index = length;
    while (index > 1 && heap[parent(index)] < heap[index]){
        int p = parent(index);
        temp = heap[index];
        heap[index] = heap[p];
        heap[p] = temp;
        index = p;
    }
    return length;
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

void increase_key(int heap[], int i, int new_value){
    // int p = parent(i);
    int temp;
    if(new_value < heap[i]){
        printf("New value must be bigger than the previous!\n");
        return;
    }
    heap[i] = new_value;
    while(i > 1 && heap[i] > heap[parent(i)]){
        int p = parent(i);
        temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;
        i = p;
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