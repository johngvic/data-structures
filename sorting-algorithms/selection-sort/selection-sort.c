#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int array[], int length) {
  int i, j, minIndex;

  for (i = 0; i < length - 1; i++) {
    minIndex = i;

    for (j = i + 1; j < length; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    swap(&array[minIndex], &array[i]);
  }
}

void print(int array[], int length) {
  for (int i = 0; i < length; i++) {
    int value = array[i];
    if (i != length - 1) {
      printf("%d - ", value);
    } else {
      printf("%d", value);
    }
  }
}

int main() {
  printf("\n\n");

  int array[] = {64, 25, 12, 22, 11};
  int length = sizeof(array)/sizeof(array[0]);
  sort(array, length);
  print(array, length);

  printf("\n\n");
  return 0;
}