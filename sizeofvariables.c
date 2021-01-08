#include<stdio.h>

int main()
{
  int a = 545;
  float b = 5.45;
  char c = 'c';
  double d = 5.4545;
  unsigned int e = 0;
  short int f = 130;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("float b value: %f and size: %lu bytes\n", b, sizeof(b));
  printf("char c value: %c and size: %lu bytes\n", c, sizeof(c));
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

