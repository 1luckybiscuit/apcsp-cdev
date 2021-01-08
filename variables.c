#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  int swap = c;
  c = a;
  a = swap;
  printf("A = %d and C = %d\n", a, c);
}
