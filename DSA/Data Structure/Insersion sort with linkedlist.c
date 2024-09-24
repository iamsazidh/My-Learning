#include <stdio.h>
#include <stdlib.h>
#include "doubly linked list.h"

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

    head = sort_nodes(head);
    print_nodes(head);

    head = reverse_nodes(head);
    print_nodes(head);
    
    return 0;
}