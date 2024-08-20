#include <stdio.h>

int fat(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * fat(n - 1);
  }
}

int main() {
  int result = fat(3);
  printf("Result: %d", result);
  return 0;
}