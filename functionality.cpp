#include <iostream>
#include "Header.h"

void add_Student() {
    Student student;
    
    //Prompt for student details
    cout << "Enter last name of the student: ";
	cin.ignore(); 	//Ignore newline character from previous input
    getline(cin, student.lastName);

    cout << "Enter first name of the student: ";
    getline(cin, student.firstName);
    
    cout << "Enter student ID: ";
    cin >> student.studentID;
    
    cout << "How many tests did this student take? ";
    cin >> student.numTestsTaken;
    
    
    //Allocate memory for test scores
    student.testScores = new int[student.numTestsTaken];
    
    cout << endl;
    
    for (int i = 0; i < student.numTestsTaken; i++) {
		cout << "Enter score #" << (i + 1) << ": ";
        cin >> student.testScores[i];
    }
    
    
    //Open the data file student.dat and write the data of the student to the file maintaining the given format
    ofstream fin ("student.dat", ios_base::app | ios_base::in);
    if (fin.fail()) {
        cout << "File error." << endl;
        exit(1);
    }

    //Use the structure members to write student data to file
    fin << "\n" << student.lastName << "," << student.firstName << "," << student.studentID << "," << student.numTestsTaken;
	
    for (int i = 0; i < student.numTestsTaken; i++) {
        fin << "," << student.testScores[i];
    }
	
	fin << ",";
	
    //Close the file
    fin.close();
}


void remove_Student(int studentID) 
{
    //Call function getNumber to get the current number of students in the data file
    int numStudents = getNumber();
	
    if (numStudents == 0) 
	{
        cout << "No students to remove." << endl;
        return;
    }

    //Create a dynamic array of the structure type Student
    Student* students = new Student[numStudents];

    //Open the student.dat file for reading
    ifstream fin("student.dat");
	
    if (fin.fail()) 
	{
        cout << "File error." << endl;
        exit(1);
    }

    bool found = false;
    int validStudentCount = 0;

    for (int i = 0; i < numStudents; i++) 
	{
        string line;
        getline(fin, line);
        if (line.empty()) continue; //Skip empty lines
        istringstream cin(line);
        string token;

        //Read name
        getline(cin, students[validStudentCount].lastName, ',');
        getline(cin, students[validStudentCount].firstName, ',');

        //Read student ID
        getline(cin, token, ',');
        students[validStudentCount].studentID = stoi(token);

        //Read number of tests
        getline(cin, token, ',');
        students[validStudentCount].numTestsTaken = stoi(token);
        students[validStudentCount].testScores = new int[students[validStudentCount].numTestsTaken];

        //Read test scores
        for (int j = 0; j < students[validStudentCount].numTestsTaken; j++) 
		{
            getline(cin, token, ',');
            students[validStudentCount].testScores[j] = stoi(token);
        }

        //Check if the student ID matches the student ID to be removed
        if (students[validStudentCount].studentID == studentID) 
		{
            found = true;
        } 
		
		else 
		{
            validStudentCount++;
        }
    }

    fin.close();

    if (found) 
	{
		//Open the student.dat file for writing
        ofstream fout("student.dat");
		
        if (fout.fail())
		{
            cout << "File error." << endl;
            exit(1);
        }

        for (int i = 0; i < validStudentCount; i++)
		{
            fout << students[i].lastName << "," << students[i].firstName << "," << students[i].studentID << "," << students[i].numTestsTaken;
			
            for (int j = 0; j < students[i].numTestsTaken; j++) 
			{
                fout << "," << students[i].testScores[j];
            }
			
            if (i < validStudentCount - 1) 
			{
                fout << endl; //Add newline except for the last line
            }
        }

        fout.close();
		
        cout << "Student ID has been removed." << endl;
    } 
	
	else 
	{
        cout << "Student does not exist." << endl;
    }

    //Clean up dynamically allocated memory
    for (int i = 0; i < validStudentCount; i++)
	{
        delete[] students[i].testScores;
    }
	
    delete[] students;
}



void display()
{
    //Open the data file for reading
    ifstream fin("student.dat");
    if (fin.fail())
	{
        cout << "File error." << endl;
        exit(1);
    }

    //Get the number of student records
    int numStudents = getNumber();
    Student* students = new Student[numStudents];

    //Read the contents of the file into the dynamic array
    for (int i = 0; i < numStudents; i++)
	{
        string line;
        getline(fin, line);
        istringstream cin(line);
        string token;

        //Read name
        getline(cin, students[i].lastName, ',');
        
        getline(cin, students[i].firstName, ',');
        
        //Read student ID
        getline(cin, token, ',');
        students[i].studentID = stoi(token);

        //Read number of tests
        getline(cin, token, ',');
        students[i].numTestsTaken = stoi(token);
        students[i].testScores = new int[students[i].numTestsTaken];

        //Read test scores
        for (int j = 0; j < students[i].numTestsTaken; j++)
		{
            getline(cin, token, ',');
            students[i].testScores[j] = stoi(token);
        }
    }

    //Display the contents of the array
    for (int i = 0; i < numStudents; i++)
	{
        cout << left << setw(30) << (students[i].lastName + "," + students[i].firstName) << " ";
        cout << left << setw(15) << students[i].studentID << " ";

        for (int j = 0; j < students[i].numTestsTaken; j++)
		{
            cout << left << setw(5) << students[i].testScores[j] << " ";
        }
        cout << endl;

        //Clean up dynamically allocated memory for test scores
        delete[] students[i].testScores;
    }

    //Clean up dynamically allocated memory for students array
    delete[] students;

    //Close the file
    fin.close();
}


void search(int studentID)
{
    ifstream fin("student.dat");
    if (fin.fail())
	{
        cout << "File error." << endl;
        exit(1);
    }

    Student* student = new Student;
    bool found = false;
    string line;

    while (getline(fin, line))
	{
        istringstream cin(line);
        string token;

        //Read name
        getline(cin, student->lastName, ',');
        getline(cin, student->firstName, ',');

        //Read student ID
        getline(cin, token, ',');
        student->studentID = stoi(token);

        //Read number of tests
        getline(cin, token, ',');
        student->numTestsTaken = stoi(token);
        student->testScores = new int[student->numTestsTaken];

        //Read test scores
        for (int i = 0; i < student->numTestsTaken; i++) 
		{
            getline(cin, token, ',');
            student->testScores[i] = stoi(token);
        }

        //Check if the student ID matches the search ID
        if (student->studentID == studentID)
		{
            found = true;
			
			cout << endl;
			
            //Display the data of the matched student
            cout << left << setw(30) << (student->lastName + "," + student->firstName) << " ";
            cout << left << setw(15) << student->studentID << " ";
			
            for (int i = 0; i < student->numTestsTaken; i++)
			{
                cout << left << setw(5) << student->testScores[i] << " ";
            }
			
            cout << endl;

            delete[] student->testScores;
            break;
			
        }
		
		else
		{
			//Clean up dynamically allocated memory for test scores
            delete[] student->testScores;
        }
    }

    if (!found)
	{
        cout << "Student does not exist." << endl;
    }
	
	//Cean up dynamically allocated memory for students
	delete student;
	
	//Close the file
    fin.close();
}


void exportResults()
{
    //Open averages.dat for writing
    ofstream fout("averages.dat");
    if (fout.fail())
	{
        cout << "File error." << endl;
        exit(1);
    }

    //Open student.dat for reading
    ifstream fin("student.dat");
    if (fin.fail())
	{
        cout << "File error." << endl;
        exit(1);
    }

    //Get the number of students
    int numStudents = getNumber();
    
    //Create a dynamic array of type Student
    Student* students = new Student[numStudents];

    //Read the contents of the file and store it in the dynamic array
    string line;
    for (int i = 0; i < numStudents; ++i)
	{
        getline(fin, line);
        istringstream cin(line);
        string token;

        //Read name
        getline(cin, students[i].lastName, ',');
        getline(cin, students[i].firstName, ',');

        //Read student ID
        getline(cin, token, ',');
        students[i].studentID = stoi(token);

        //Read number of tests
        getline(cin, token, ',');
        students[i].numTestsTaken = stoi(token);
        students[i].testScores = new int[students[i].numTestsTaken];

        //Read test scores
        for (int j = 0; j < students[i].numTestsTaken; ++j)
		{
            getline(cin, token, ',');
            students[i].testScores[j] = stoi(token);
        }
    }

    //Process each student to compute the average
    for (int i = 0; i < numStudents; ++i)
	{
        int sum = 0;
	
        for (int j = 0; j < students[i].numTestsTaken; ++j)
		{
            sum += students[i].testScores[j];
        }
		
        int minScore = findMinimum(students[i].testScores, students[i].numTestsTaken);
		
		//Solving the student ID and the average to averages.dat
		if (students[i].numTestsTaken >= 5) 
		{
			sum -= minScore;
			double average = static_cast<double>(sum) / (students[i].numTestsTaken - 1);
			fout << left << setw(15) << students[i].studentID << fixed << setprecision(1) << average << endl;
		}
		
		else 
		{
			double average = static_cast<double>(sum) / students[i].numTestsTaken;
			fout << left << setw(15) << students[i].studentID << fixed << setprecision(1) << average << endl;
		}

        //Clean up dynamically allocated memory for test scores
        delete[] students[i].testScores;
    }

    //Clean up dynamically allocated memory for students
    delete[] students;

    //Close both files
    fin.close();
    fout.close();
	
	cout << "Results exported to file." << endl;

}

int findMinimum(int* scores, int size)
{
    if (size < 5)
	{
        //If fewer than 5 tests, return 0
        return 0;
    } 
	
	else
	{
        //Find the minimum score in the array
        int minScore = scores[0];
		
        for (int i = 1; i < size; ++i)
		{
            if (scores[i] < minScore)
			{
                minScore = scores[i];
            }
        }
        return minScore;
    }
}
