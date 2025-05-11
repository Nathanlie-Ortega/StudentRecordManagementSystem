# Student Record Management System

**Author**: Nathanlie Ortega


**Email**: NathanlieOrtega.Dev@gmail.com

## Brief Description
A C++ console application that manages student records (names, IDs, test scores) stored in `student.dat`. Features include adding, removing, displaying, searching, dropping the lowest score for 5+ tests. Uses structures, dynamic memory, and file I/O.

## Files and Structure
- `main.cpp`: Main logic and menu interface.
- `Header.h`: Declares `Student` structure and function prototypes.
- `functionality.cpp`: Implements record management functions.
- `getNumber.cpp`: Reads and get student data.
- `student.dat`: Data of student records.

## Compilation and Execution
1. Navigate to the project folder:

   cd StudentRecordManagementSystem

2. Compile:

    g++ functionality.cpp getNumber.cpp main.cpp

3. Run:

    ./a.exe


## Alternative Way to Compile and Execute:

1. Navigate to the project folder:

   cd StudentRecordManagementSystem

2. Compile:

    g++ functionality.cpp getNumber.cpp main.cpp -o StudentRecordManagementSystem.exe


3. Run:

    ./StudentRecordManagementSystem.exe


## Expected Output:
``````````````````````````````````````````````````````

+-------------------------------------------------+
|      Student Record Management System           |
|      Author name: Nathanlie Ortega              |
|      NathanlieOrtega.dev@gmail.com              |
+-------------------------------------------------+

1. Add
2. Remove
3. Display
4. Search
5. Results
6. Quit
Enter choice: 1
Enter last name of the student: Ortega 
Enter first name of the student: Nathanlie
Enter student ID: 1155667
How many tests did this student take? 2

Enter score #1: 87
Enter score #2: 94

(Continuation)......

````````````````````````````````````````````````````````
