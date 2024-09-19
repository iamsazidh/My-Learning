#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
    Node *prev;

};

Node *create_node(int item, Node *next, Node *prev){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Can't create new node\n");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}

Node *prepend(Node *head, int item){
    Node *new_node = create_node(item, head, NULL);
    new_node->next->prev = new_node;
    return new_node;

}

Node *append(Node *head, int item){
    Node *current_node = head;
    while (current_node->next != NULL){
        current_node = current_node->next;
    }
    Node *new_node = create_node(item, NULL, current_node);
    current_node->next = new_node;
    return head;
    
}

Node *remove_node(Node *head, Node *node){
    if(head == node){
        head = node->next;
        head->prev = NULL;
        free(node);
        return head;
    }
    Node *prev_node = node->prev;
    Node *next_node = node->next;

    prev_node->next = next_node;
    if(next_node != NULL){
    next_node->prev = prev_node;
    }
    free(node);

    return head;
}

void insert(Node *after, int item){
    Node *new_node = create_node(item, after->next, after);
    after->next = new_node;
    if(new_node->next != NULL){
    new_node->next->prev = new_node;   
    }
    return;
}

void print_nodes(Node *head){
    Node *current_node = head;
    while (current_node != NULL){
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return;
}

int main(){
    Node *n1, *head;
    n1 = create_node(10, NULL, NULL);
    head = n1;
    print_nodes(head);

    head = prepend(head, 20);
    print_nodes(head);

    head = append(head, 30);
    print_nodes(head);

    head = remove_node(head, head->next);
    print_nodes(head);  

    insert(head->next, 40);
    print_nodes(head);  

    return 0;
}