#include <stdio.h>
#include <stdlib.h>

/*
  Singly Linked Lists
  - advantages:
    + dynamic size (unlike arrays, it can dynamically grow or shrink)
    + no memory wastage (each node is allocated separatelly, so no need to reserve extra space)
    + flexible structure (can represent stack, queue or other abstract data type)
    + efficient for sequential access
  - disadvantages:
    + higher memory overhead (as it stores not only the data, but also the pointer for the next node)
    + sequential access (cannot perform random access -> O(n))
    + no binary search (cannot be applied to linked lists because there's no direct indexing of elements)
*/

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* initialize(int value) {
  Node* node = (Node *) malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

void push(Node *head, int value) {
  Node *node = initialize(value);
  Node *current = head;

  while(current->next) {
    current = current->next;
  }

  current->next = node;
}

void print(Node *head) {
  Node *current = head;

  while(current) {
    printf("%d | %d\n", current->value, current);
    current = current->next;
  }
}

void freeList(Node *head) {
  Node *current = head;
  Node *temp;

  while(current != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }
}

int main() {
  Node *head = initialize(10);

  push(head, 15);
  push(head, 37);
  freeList(head);

  return 0;
}