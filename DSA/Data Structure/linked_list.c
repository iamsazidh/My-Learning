#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

//Node *head;

Node *create_node(int item, Node *next){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error! Could not create a new node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
    
}

Node *prepend(Node *head, int item){
    Node *new_node = create_node(item, head);
    
    return new_node;
}

Node *append(Node *head, int item){
    Node *new_node = create_node(item, NULL);

    if(head == NULL){
        return new_node;
    }

    Node *current_node = head;

    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

void insert_after(Node *node, int item){
    Node *new_node = create_node(item, node->next);
    node->next = new_node;
    return 0;
}
void inser_after_by_value(Node *head, int insertAfter, int item){
    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->data == insertAfter){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node == NULL){
        printf("Error 404: Given value not found! (-.-) \n");
        return;
    }
    Node *new_node = create_node(item, current_node->next);
    current_node->next = new_node;
    
}

Node *remove_node(Node *head, Node *node){
    if(node == head){
        head = node->next;
        free(node);
        return head;
    }

    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node == NULL){
        return head;
    }

    current_node->next = node->next;

    free(node);

    return head;
}

Node *remove_node_by_value(Node *head, int item){
    Node *current_node = head;
    while (current_node->next != NULL){
        if(current_node->next->data == item){
            break;
        }
        current_node = current_node->next;
    }
    current_node = current_node->next;
    if(current_node == NULL){
        printf("Error 404: Node with value %d not found. \n", item);
        return head;
    }
    Node *node_to_remove = current_node->next;
    current_node->next = node_to_remove->next;
    free(node_to_remove);

    return head;
    
}

void print_linked_list(Node *head){
    Node *current_node = head;
    while(current_node != NULL){
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int count(Node *head){
    int count = 0;
    Node *current_node = head;
    while (current_node != NULL){
        count++;
        current_node = current_node->next;

    }
    return count;
    
}
Node *search(Node *head, int item){
    if (head == NULL)
    {
        printf("Empty Nodes!\n");
        exit(1);
    }
    
    Node *current_node = head;
    while (current_node->data != item){
        current_node = current_node->next;
    }
    return current_node;
    
}

int main(){
    Node *n1, *head, *n2;

    n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    head = remove_node_by_value(head, 10);
    print_linked_list(head);

    head = remove_node_by_value(head, 100);
    print_linked_list(head);

    insert_after(head, 40);
    print_linked_list(head);

    inser_after_by_value(head, 100, 50);
    print_linked_list(head);


    printf("Total node: %d\n", count(head));

    return 0;
}