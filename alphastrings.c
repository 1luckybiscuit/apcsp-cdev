#include <stdio.h>
#include <string.h>

int main() {
  char string1[26];
  char string2[] = "abcdefghijklmnopqrstuvwxyz";
  char letter = 'a';

  for(int i = 0; i < 26; i++) {
    string1[i] = letter;
    letter++;
  }

  printf("%s\n%s\n", string1, string2);
  printf("%d and %d\n", strlen(string2), strlen(string1));

  if(strcmp(string1, string2) == 0)
    printf("These strings are identical!\n");
  else
    printf("These strings are different!\n");

  for(int i = 0; i < 26; i++) {
    string1[i] -= 32;
  }

  char string3[52];
  strcpy(string3, string1);
  strcat(string3, string2);
  printf("String 1: %s\nString 2: %s\nString 3: %s\n", string1, string2, string3);
}

  


