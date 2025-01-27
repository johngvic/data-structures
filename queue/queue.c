#include <stdio.h>

#define MAX 10

typedef struct {
  int data[MAX];
  int head, tail;
} Queue;

void createQueue(Queue *q) {
  q->head = q->tail = -1;
}

void enqueue(Queue *q, int value) {
  if (q->tail == MAX - 1) {
    printf("Queue is full");
  } else {
    if (q->head == -1) {
      q->head = 0;
    }
    q->tail++;
    q->data[q->tail] = value;
  }
}

int dequeue(Queue *q) {
  if (q->head == -1) {
    printf("Queue is empty");
    return -1;
  }
  int value = q->data[q->head];
  q->head++;
  return value;
}

int top(Queue *q) {
  return q->data[q->head];
}

int main() {
  printf("\n\n");

  Queue *queue = (Queue *)malloc(sizeof(Queue));
  createQueue(queue);

  for (int i = 0; i < MAX; i++) {
    enqueue(queue, i);
  }

  for (int i = 0; i < MAX; i++) {
    printf("%d, ", dequeue(queue));
  }

  enqueue(queue, 10);
  printf("Top: %d\n", top(queue));

  printf("\n\n");
  return 0;
}