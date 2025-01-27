#include <stdio.h>
#include <stdlib.h>

typedef struct {
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

  while(current->next != NULL) {
    current = current->next;
  }

  current->next = node;
}

void print(Node *head) {
  Node *current = head;

  while(current != NULL) {
    printf("%d | %d\n", current->value, current);
    current = current->next;
  }
}

int main() {
  Node *head = initialize(10);

  push(head, 15);
  print(head);

  return 0;
}