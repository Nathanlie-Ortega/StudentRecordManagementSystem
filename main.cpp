#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	
	//A display of the title, my name, and e-mail address
    cout << "+-------------------------------------------------+" << endl;
    cout << "|      Student Record Management System		  |" << endl;
    cout << "|      Author name: Nathanlie Ortega              |" << endl;
    cout << "|      NathanlieOrtega.dev@gmail.com              |" << endl;
    cout << "+-------------------------------------------------+\n" << endl;
	
	//Display a menu for the user
    int MenuChoice;
    do {
        cout << "1. Add\n";			//Add a new student record
        cout << "2. Remove\n";		//Remove an existing student record 
        cout << "3. Display\n";		//Display all records 
        cout << "4. Search\n";		//Search for a particular student record using student ID
        cout << "5. Results\n";		//Export the results to a disk file 
        cout << "6. Quit\n";		//Quit the program 
		
        cout << "Enter choice: ";	//Ask the user to make the menu choice using an integer variable
        cin >> MenuChoice;
		
		//Design a switch-case block to implement the following requirements
        switch(MenuChoice)
		{
            case Add:
                add_Student();		//Call the function add_Student 
                break;
				
            case Remove:
                int studentID;
                cout << "Enter student ID of student to remove: ";
                cin >> studentID;
                remove_Student(studentID);	//Call the function remove_Student and pass the student ID entered by the user
                break;
				
            case Display:
                display();			//Call the function display
                break;
				
            case Search:
                cout << "Enter student ID to search: ";
                cin >> studentID;
                search(studentID);			//Call the function search and pass the student ID entered by the user
                break;
				
            case Results:
                exportResults();	//Call the function exportResults
                break;
				
            case Quit:
                cout << "Bye!!!" << endl;	//Exit the program
                break;
				
            default:
                cout << "Incorrect choice. Please enter again." << endl;
        }
    }
	
	while (MenuChoice != Quit);		//Using a suitable loop that ask the user for the choice again
	
    return 0;
}
