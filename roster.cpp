
#include <cassert>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "roster.h"

// Accessing from roaster

const Student *Roster::getStudents() const
{
    return students; // Return the pointer to the array of students
}
int Roster::getStudentNum() const
{
    return studentNum; // Return the current number of students
}

// Constructor for roster
Roster::Roster(string courseName) : courseName(courseName), studentNum(0)
{
    // Additional initialization if needed
}
string Roster::getCourseName() const
{
    return courseName; // Return the course name
}
void Roster::readStudentRecord(string filename)
{
    ifstream gradeFile(filename);
    assert(gradeFile.is_open());

    // Read students from the file
    string temp;              // to skip first lines if needed
    getline(gradeFile, temp); // Skip first line
    getline(gradeFile, temp); // Skip header

    while (studentNum < MAX_NUM && gradeFile)
    {
        string id, name;
        int cla, ola, quiz, homework, exam, bonus;

        gradeFile >> id >> name >> cla >> ola >> quiz >> homework >> exam >> bonus;

        if (gradeFile.fail())
        {
            break; // Break if reading fails
        }

        students[studentNum].setID(id);
        students[studentNum].setName(name);
        students[studentNum].changeScore(Student::CLA, cla);
        students[studentNum].changeScore(Student::OLA, ola);
        students[studentNum].changeScore(Student::QUIZ, quiz);
        students[studentNum].changeScore(Student::HOMEWORK, homework);
        students[studentNum].changeScore(Student::EXAM, exam);
        students[studentNum].changeScore(Student::BONUS, bonus);

        students[studentNum].ComputeTotal();
        students[studentNum].ComputeGrade();

        studentNum++;
    }
}

// function to print information of one students in table form.
void Roster::ShowOneStudent(const std::string &id) const
{
    for (int i = 0; i < studentNum; ++i)
    {
        if (students[i].getID() == id)
        {
            cout << "-------------------------------------------------------" << endl;
            std::cout << "ID: " << students[i].getID() << std::endl;
            std::cout << "Name: " << students[i].getName() << std::endl;
            std::cout << "CLA Score: " << students[i].getScore(Student::CLA) << std::endl;
            std::cout << "OLA Score: " << students[i].getScore(Student::OLA) << std::endl;
            std::cout << "Quiz Score: " << students[i].getScore(Student::QUIZ) << std::endl;
            std::cout << "Homework Score: " << students[i].getScore(Student::HOMEWORK) << std::endl;
            std::cout << "Exam Score: " << students[i].getScore(Student::EXAM) << std::endl;
            std::cout << "Bonus Score: " << students[i].getScore(Student::BONUS) << std::endl;
            cout << "--------------------------------------------------------" << endl;
            std::cout << "Total Score: " << students[i].GetTotal() << std::endl;
            std::cout << "Letter Grade: " << students[i].GetGrade() << std::endl;
            return; // Found and displayed the student
        }
    }
    std::cout << "Student ID not found." << std::endl; // ID not found
}

// checking the validity of the student through entered student ID
bool Roster::isValid(string id) const
{
    for (int i = 0; i < studentNum; ++i)
    {
        if (students[i].getID() == id)
        {
            return true; // ID is valid
        }
    }
    return false; // ID not found
}
// Displaying single information
void Student::DisplayInfo() const
{
    std::cout << "Name: " << name << std::endl; // Access private member name
    std::cout << "CLA Score: " << getScore(CLA) << std::endl;
    std::cout << "OLA Score: " << getScore(OLA) << std::endl;
    std::cout << "Quiz Score: " << getScore(QUIZ) << std::endl;
    std::cout << "Homework Score: " << getScore(HOMEWORK) << std::endl;
    std::cout << "Exam Score: " << getScore(EXAM) << std::endl;
    std::cout << "Bonus Score: " << getScore(BONUS) << std::endl;
    std::cout << "Total Score: " << GetTotal() << std::endl;
    std::cout << "Letter Grade: " << GetGrade() << std::endl;
}

// Overloaded operator to display Roster details
ostream &operator<<(ostream &os, const Roster &oneClass)
{
    os << "Roster for course: " << oneClass.getCourseName() << endl;
    os << left << setw(15) << "ID"
       << setw(20) << "Name"
       << setw(10) << "CLA"
       << setw(10) << "OLA"
       << setw(10) << "Quiz"
       << setw(10) << "Homework"
       << setw(10) << "Exam"
       << setw(10) << "Bonus" << endl;
    for (int i = 0; i < oneClass.getStudentNum(); ++i)
    {
        os << left << setw(15) << oneClass.getStudents()[i].getID()
           << setw(20) << oneClass.getStudents()[i].getName()
           << setw(10) << oneClass.getStudents()[i].getScore(Student::CLA)
           << setw(10) << oneClass.getStudents()[i].getScore(Student::OLA)
           << setw(10) << oneClass.getStudents()[i].getScore(Student::QUIZ)
           << setw(10) << oneClass.getStudents()[i].getScore(Student::HOMEWORK)
           << setw(10) << oneClass.getStudents()[i].getScore(Student::EXAM)
           << setw(10) << oneClass.getStudents()[i].getScore(Student::BONUS) << endl;
    }
    return os;
}
