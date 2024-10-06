#include <stdio.h>

int left(int i){
    return i * 2;
}
int right(int i){
    return i * 2 + 1;
}
int parent(int i){
    return i / 2;
}

int is_min_heap(int heap[], int length){
    for(int i = length; i > 1; i--){
        if(heap[i] < heap[parent(i)]){
            printf("This isn't a min heap.\n");
            return 0;
        }
    }
        printf("This is a min heap.\n");
        return 1;
}

void min_heapify(int heap[], int length, int index){
    int l, r, smallest, temp;
    l = left(index);
    r = right(index);
    if(l <= length && heap[index] > heap[l]){
        smallest = l;
    }else{
        smallest = index;
    }
    if(r <= length && heap[smallest] > heap[r]){
        smallest = r;
    }

    if(smallest != index){
        temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        min_heapify(heap, length, smallest);
    }
}

void build_min_heap(int heap[], int length){
    for(int i = length / 2; i >= 1; i--){
        min_heapify(heap, length, i);
    }
}

void print_heap(int heap[], int length){
    for(int i = 1; i <= length; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int extract_min(int heap[], int length){
    heap[1] = heap[length];
    length--;
    min_heapify(heap, length, 1);
    return length;
}

int insert_node(int heap[], int length, int item){
    length++;
    heap[length] = item;
    int i = length, p, temp;
    while(i > 1 && heap[i] < heap[parent(i)]){
        p = parent(i);
        temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;
        i = p;
    }
    return length;
}
int main(){
    int length = 10;
    int heap[20] = {0, 500, 9, 8, 200, 1, 6, 3, 4, 7, 10};
    print_heap(heap, length);
    is_min_heap(heap, length);
    build_min_heap(heap, length);
    print_heap(heap, length);
    is_min_heap(heap, length);
    length = extract_min(heap, length);
    print_heap(heap, length);
    is_min_heap(heap, length);
    length = insert_node(heap, length, -1);
    print_heap(heap, length);
    length = insert_node(heap, length, -1);
    print_heap(heap, length);
    is_min_heap(heap, length);
}