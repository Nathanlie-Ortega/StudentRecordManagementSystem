#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Global integer constants
const int NUM_TESTS = 5;

//Enumeration constant with values for menu choices
enum MenuChoice {Add = 1, Remove, Display, Search, Results, Quit};

//Structure for Student with the following members
struct Student {
    string lastName;
    string firstName;
    int studentID;
    int numTestsTaken;
    int* testScores;
    double averageScore;
};

//Function Prototypes
void add_Student();
void remove_Student(int studentID);
void display();
void search(int studentID);
void exportResults();
int findMinimum(int* scores, int size);
int getNumber(); 	//This function is defined in getNumber.cpp
