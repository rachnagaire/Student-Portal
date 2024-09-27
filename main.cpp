

// Author
// Project Description:

// Rachana Gaire

#include <cassert>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "student.cpp"
#include "roster.cpp"

// Main function
int main()
{
    Roster roster("CSCI3110");              // Create a Roster instance
    roster.readStudentRecord("grades.dat"); // Read student records from the file

    cout << roster; // Display all students in the roster

    int numStudents = roster.getStudentNum();
    // Declare variables
    string inputClassID;
    bool hasValidClassID = false;

    // Getting the valid input to display the single student information
    do
    {
        cout << "\nEnter a valid Class ID: ";
        getline(cin, inputClassID);

        // Check if the class ID is valid
        hasValidClassID = roster.isValid(inputClassID); // isvalid method from roster header file

        if (!hasValidClassID)
        {
            cout << "Invalid Class ID. Please try again." << endl;
        }
    } while (!hasValidClassID);

    // Display the student information after a valid class ID is found
    cout << "\nStudent Details for Class ID " << inputClassID << ":\n";
    roster.ShowOneStudent(inputClassID); // Show the student's details
    return 0;
}
