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
    new_node->data = item;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}

Node *preapend(Node *head, int item){
    Node *new_node = create_node(item, head, NULL);
    new_node->next->prev = new_node;
    return new_node;
}

Node *append(int item, Node *head){
    Node *current_node = head;
    while (current_node->next != NULL){
        current_node = current_node->next;
    }
    Node *new_node = create_node(item, NULL, current_node);
    current_node->next = new_node;
    return head;
    
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

Node *sort_nodes(Node *head){
    int len = 0;
    Node *current_node = head;
    while (current_node != NULL){
        len++;
        current_node = current_node->next;
    }
    current_node = head->next;
    if(len > 1){
        for(int i = 1; i < len; i++){
            Node *store_node = current_node->next;
            Node *comp_with = current_node->prev;
            if(comp_with != NULL && comp_with->data > current_node->data){
                comp_with->next = comp_with->next->next;
                if(comp_with->next != NULL){
                comp_with->next->prev = comp_with;

                }
                while (comp_with->prev != NULL && comp_with->prev->data > current_node->data)
                {
                    comp_with = comp_with->prev;
                }
                if(comp_with->prev != NULL){
                    comp_with->prev->next = current_node;
                }
                
                current_node->prev = comp_with->prev;
                comp_with->prev = current_node;
                current_node->next = comp_with;

                
            }
            current_node = store_node;
        }   
    }
    current_node = head;
    while (current_node->prev != NULL){
        current_node = current_node->prev;
    }
    return current_node;
}

Node *reverse_nodes(Node *head){
    Node *current_node = head;
    int count = 1;
    while (current_node->next != NULL){
        count++;
        current_node = current_node->next;
    }
    head = current_node;
    Node *prev_node;
    while (current_node != NULL){
        prev_node = current_node->prev;
        current_node->prev = current_node->next;
        current_node->next = prev_node;

        current_node = prev_node;
    }
    
    // current_node = head;
    // for(int i = 1; i < count; i++){
    //     current_node = current_node->next;
    // }
    // current_node->next = NULL;
    return head;
}

int main(){
    Node *n1, *head;
    n1 = create_node(10, NULL, NULL);
    head = n1;
    head = preapend(head, 20);
    head = append(70, head);
    head = append(50, head);
    head = preapend(head, 90);
    head = append(40, head);
    head = preapend(head, 60);
    head = append(100, head);
    print_nodes(head);

    // head = sort_nodes(head);
    // print_nodes(head);

    head = reverse_nodes(head);
    print_nodes(head);
    
    return 0;
}