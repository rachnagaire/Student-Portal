#include <cassert>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "student.h"

// Implementations of Student methods
Student::Student() : id(""), name(""), total(0), letterGrade('F')
{
    for (int i = 0; i < CATEGORY_NUM; ++i)
    {
        score[i] = 0;
    }
}

string Student::getID() const
{
    return id;
}

void Student::setID(string newID)
{
    id = newID;
}
string Student::getName() const
{
    return name;
}

void Student::setName(const string &newName)
{
    name = newName;
}
void Student::changeScore(ScoreType scoreName, int scoreValue)
{
    if (scoreName >= CLA && scoreName <= BONUS)
    {
        score[scoreName] = scoreValue;
    }
}

void Student::ComputeTotal()
{
    total = 0;
    for (int i = 0; i < CATEGORY_NUM; ++i)
    {
        total += score[i];
    }
}

int Student::GetTotal() const
{
    return total;
}

void Student::ComputeGrade()
{
    if (total >= 90)
    {
        letterGrade = 'A';
    }
    else if (total >= 80)
    {
        letterGrade = 'B';
    }
    else if (total >= 70)
    {
        letterGrade = 'C';
    }
    else if (total >= 60)
    {
        letterGrade = 'D';
    }
    else
    {
        letterGrade = 'F';
    }
}

char Student::GetGrade() const
{
    return letterGrade;
}
// Implementing getScore method
int Student::getScore(ScoreType scoreName) const
{
    if (scoreName >= CLA && scoreName <= BONUS)
    {
        return score[scoreName];
    }
    return 0; // return 0 or some error value if scoreName is out of range
}

// copy constructor
Student &Student::operator=(const Student &other)
{
    if (this == &other)
    {
        return *this; // Handle self-assignment
    }
    id = other.id;
    name = other.name;
    total = other.total;
    letterGrade = other.letterGrade;
    for (int i = 0; i < CATEGORY_NUM; ++i)
    {
        score[i] = other.score[i];
    }
    return *this;
}
