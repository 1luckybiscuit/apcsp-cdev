//
// encrypt.c
//

#include <string.h>
#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


// Function to take a character and convert its ASCII index to the array index
// Used in shiftShcar and also separately in the vigenere cypher functions

int findIndex(char c) {
  int index;

  // Check ranges
  if(c >= 97 && c <= 122) {
    // Lowercase ASCII range
    // Subtract the ASCII value for correct index
    index = c - 97;
  }else if( c >= 65 && c <= 90) {
    // Uppercase ASCII range
    // Subtract ASCII index and move past the lowercase letters
    index = c - 65 + 26;
  }else if(c >= 48 && c <= 57) {
    // Number ASCII range
    // Subtract ASCII index and move past both upper and lower case letters
    index = c - 48 + 52;
  }
  return index;
}

char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('s', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'

  // Index stores the location of the char in the CHARS array
  int index;

  // Right = positive = 1 and left = negative = 0
  // So only left or 0 conditions must change sign
  if(direction == 0) {
    // Change sign to the left (negative)
    shift = 0 - shift;
  }

  // Search for char location in the ASCII table
  // Turned this section into a function to apply to EC
  index = findIndex(c);

  // Apply encryption shift
  int result = index + shift;

  // Use loops instead of ifs in case a shift key exceeds the char array size  
  while(result < 0) {
    result += CHARS_LEN;
  }
  while(result >= CHARS_LEN) {
    result -= CHARS_LEN;
  }
  // Return the shifted char according to final location
  return CHARS[result];
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}

void vigDecipher(char str[], char keyword[], int encDec)
{
  // The same process occurs for vigEncrypt AND vigDecrypt
  // The only difference is shifting forward or backward, denoted by encDec

  // First, create the shift pattern based off of the keyword
  int keywordSize = strlen(keyword);

  // If no keyword is entered, load 'a' which will apply 0 shift to all characters
  if(keywordSize == 0) {
    char failsafe = 'a';
    strncat(keyword, &failsafe, 1);

    // Don't forget that the size of the keyword must be updated
    keywordSize++;
  }

  // Initialize the shift pattern array of ints with the same size as the keyword
  int shiftPattern[keywordSize];

  // Use findIndex to convert each char in the keyword to a value for shiftPattern
  for (int i = 0; i < keywordSize; i++) {
    shiftPattern[i] = findIndex(keyword[i]);
  }

  // Apply the corresponding part of the shift pattern to change the string
  int strSize = strlen(str);
  for (int i = 0; i < strSize; i++) {

    // Ensure that the keyword pattern continues iterating
    int temp = i;
    while(temp >= keywordSize) {
      temp -= keywordSize;
    }

    // Finally, enact the shift
    str[i] = shiftChar(str[i], shiftPattern[temp], encDec);
  }

}

void vigEncrypt(char str[], char keyword[])
{
  // Call the shift forward
  vigDecipher(str, keyword, 1);
}

void vigDecrypt(char str[], char keyword[])
{
  // Call the shift backward
  vigDecipher(str, keyword, 0);
}
