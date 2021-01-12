#include <stdio.h>
#include <math.h>

float min;
float max;

// for testing only - do not change
void checkCommand(int argc, char* argv[], float* a, float* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%f", b);
  }
  else {
    char minInput[256];
    char maxInput[256];
    printf("Enter minimum\n");
    while (1) {
      fgets(minInput, 256, stdin);
      if(sscanf(minInput, "%f", a) == 1 && *a >= 0) break;
      printf("Not a valid number. Please try again!\n");
    }
    printf("Enter maximum\n");
    while (1) {
      fgets(maxInput, 256, stdin);
      if(sscanf(maxInput, "%f", b) == 1 && *b > *a) break;
      printf("Not a valid number. Please try again!\n");
    }
  }
}

void inputFloats() {
  
}
// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float radius)
{
  float area = M_PI*radius*radius;
  return area;
}



int main(int argc, char* argv[]) 
{
  
  // for testing only - do not change
  checkCommand(argc, argv, &min, &max);

  printf("Calculating area of circles starting at %f, and ending at %f\n", min, max);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
  for(float i = min; i <= max; i++) {
    float rad = i;
    printf("The area of a circle with radius %f is %f\n", rad, areaOfCircle(rad));
  }


  
}
