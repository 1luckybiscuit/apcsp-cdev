#include <stdio.h>
#include <string.h>

// student structure
//struct Student...
struct Student {
  char firstName[20];
  char lastName[20];
  int age;
  int id;
};

void printStudent(struct Student* student)
{
  printf("First name: %s", student->firstName);
  printf("Last name: %s", student->lastName);
  printf("Age: %d\n", student->age);
  printf("ID: %d\n", student->id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; i++) {
    printf("\nStudent %d\n", i);
    printStudent(&students[i]);
  }
}


int main()
{
  
  // an array of students
  //xxx students;
  struct Student students[10];
  int numStudents = 0;
  while (1)
  {
    char input[256];
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("First name? ");
      fgets(input, 256, stdin);
      strcpy(students[numStudents].firstName, input);
      printf("Last name? ");
      fgets(input, 256, stdin);
      strcpy(students[numStudents].lastName, input);
      while (1) {
        int ageTemp;
        printf("Age? ");
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &ageTemp) == 1 && ageTemp > 0) {
          students[numStudents].age = ageTemp;
          break;
        }
      }
      while (1) {
        int idTemp;
        printf("ID? ");
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &idTemp) == 1) {
          students[numStudents].id = idTemp;
          break;
        }
      }
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
