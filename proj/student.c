//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// Keeps track of the number of students in the students array
int numStudents = 0;

// Holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname arg

  // Follow instructions above for the current student using numStudents 
  students[numStudents] = (Student*)malloc(sizeof(Student));
  students[numStudents]->firstName = (char*)malloc(sizeof(fname));
  students[numStudents]->lastName = (char*)malloc(sizeof(lname));
  strcpy(students[numStudents]->firstName, fname);
  strcpy(students[numStudents]->lastName, lname);
  students[numStudents]->age = age;
  students[numStudents]->id = id;

  // Make sure to increment!
  numStudents++;
}


void deleteStudent(Student* student)
{
  // Free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // Iterate over the students array deleting every student and setting the pointer
  // values to 0 and adjusting the numStudents to 0
  for(int i = 0; i < numStudents; i++) {
    students[i]->firstName = 0;
    students[i]->lastName = 0;
    students[i]->age = 0;
    students[i]->id = 0;
    deleteStudent(students[i]);
  }
  numStudents = 0;
}


void saveStudents(int key)
{

  FILE* sf;
  // Student file

  sf = fopen("studentdata.txt", "w");
  // Save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  if (sf) {
    for(int i = 0; i < numStudents; i++) {
      // Initialize temporary string storage variables
      char ageTemp[4];
      char idTemp[50];

      // Stores the ints as strings. Was this necessary?
      sprintf(ageTemp, "%d", students[i]->age);
      sprintf(idTemp, "%ld", students[i]->id);

      // Encrypt each aspect of the struct
      caesarEncrypt(students[i]->firstName, key);
      caesarEncrypt(students[i]->lastName, key);
      caesarEncrypt(ageTemp, key);
      caesarEncrypt(idTemp, key);

      // Print each struct aspect to the file and record it to user
      fprintf(sf, "%s %s %s %s\n", students[i]->firstName, students[i]->lastName, ageTemp, idTemp);
      printf("Saving: %s %s %s %s\n", students[i]->firstName, students[i]->lastName, ageTemp, idTemp);
    }

    // Report number of students saved to the file
    printf("Saved %d students\n", numStudents);
    fclose(sf);
  } 
}


void loadStudents(int key)
{
  // Load the students from the data file overwriting all existing students in memory
  // Wipes everything to "overwrite"
  deleteStudents();
  FILE* sf;
  sf = fopen("studentdata.txt", "r");
  if (sf) {
    while (1) {
      // Initialize storage variables
      char fname[50];
      char lname[50];
      char ageTemp[50];
      char idTemp[50];
      int age; long int id;

      // Check for a student by looking for lines with four arguments
      if(fscanf(sf, "%s %s %s %s\n", fname, lname, ageTemp, idTemp) == 4) {
        // Looked it up--use sprintf to convert age and id to strings
        // I get the feeling somehow that ints themselves should be able to pass into
        //   the encrypt function with a bit of manipulation not like this. 
        // Am I doing it right??
        //sprintf(ageTemp, "%d", age);
        //sprintf(idTemp, "%ld", id);

        // Decrypt all aspects of the struct
        caesarDecrypt(fname, key);
        caesarDecrypt(lname, key);
        caesarDecrypt(ageTemp, key);
        caesarDecrypt(idTemp, key);

        // Convert age and id back to numbers to recreate student.
        // Again, I think I am supposed to do this without using atoi().
        // If this were required, the instructions would mention it...
        // ...right?
        age = atoi(ageTemp);
        id = atoi(idTemp);
        createStudent(fname, lname, age, id);
      }
      else
        break;
    }
    fclose(sf);
    printf("Loaded %d students\n", numStudents);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    Age: %d\n", student->age);
  printf("    ID: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- Student %d ------\n", i);
    printStudent(students[i]);
  }
}




