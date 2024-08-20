#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

typedef struct {
  int items[MAX];
  int top;
} st;

void createStack(st *s) {
  s->top = -1;
}

int isFull(st *s) {
  if (s->top == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

int isEmpty(st *s) {
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void push(st *s, int value) {
  if (isFull(s)) {
    printf("Stack is full");
  } else {
    s->top++;
    s->items[s->top] = value;
  }
}

void pop(st *s) {
  if (isEmpty(s)) {
    printf("Stack is empty");
  } else {
    s->top--;
  }
}

void console(st *s) {
  if (isEmpty(s)) {
    printf("Stack is empty");
  } else {
    int stackLength = s->top + 1;

    for (int i = 0; i < stackLength; i++) {
      printf("%d ", s->items[i]);
    }
  }
}

int main() {
  printf("\n\n");
  
  st *s = (st *) malloc(sizeof(st));
  createStack(s);

  push(s, 5);
  push(s, 10);
  
  console(s);

  printf("\n\n");
  return 0;
}
