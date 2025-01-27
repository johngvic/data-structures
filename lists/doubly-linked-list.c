#include <stdio.h>
#include <stdlib.h>

/*
  Doubly Linked Lists
  - advantages:
    + can traverse the list in both directions
  - disadvantages:
    + higher memory overhead
*/

typedef struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

Node* initialize(int value) {
  Node* node = (Node *) malloc(sizeof(Node));
  node->value = value;
  node->prev = NULL;
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
  current->next->prev = current;
}

void delete(Node *head, int value) {
  // Fix
  Node *current = head;

  while(current->value != value) {
    current = current->next;
  }

  if (current != NULL) {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
  }
}

void print(Node *head) {
  Node *current = head;

  while(current) {
    printf("%d \n", current->value);
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
  push(head, 20);
  print(head);

  printf("==================\n");

  delete(head, 37);
  delete(head, 20);
  print(head);

  return 0;
}