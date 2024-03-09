#include <iostream>
#include <string>
using namespace std;

class student {
protected:
    int studentNumber;
    string studentName;
    double studentAverage;

public:
    student() : studentNumber(0), studentName(""), studentAverage(0.0) {}

    void setStudentNumber(int number) { studentNumber = number; }
    int getStudentNumber() const { return studentNumber; }

    void setStudentName(string name) { studentName = name; }
    string getStudentName() const { return studentName; }

    void setStudentAverage(double average) { studentAverage = average; }
    double getStudentAverage() const { return studentAverage; }

    void print() const {
        cout << "Student Number: " << studentNumber << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Student Average: " << studentAverage << endl;
    }
};
class graduatestudent : public student {
protected:
    int level;
    int year;

public:
    graduatestudent() : student(), level(0), year(0) {}

    void setLevel(int lv) { level = lv; }
    int getLevel() const { return level; }

    void setYear(int yr) { year = yr; }
    int getYear() const { return year; }

    void print() const {
        student::print(); // Call base class print function
        cout << "Level: " << level << endl;
        cout << "Year: " << year << endl;
    }
};
class master : public graduatestudent {
private:
    int newid;

public:
    master() : graduatestudent(), newid(0) {}

    void setNewid(int id) { newid = id; }
    int getNewid() const { return newid; }

    void print() const {
        graduatestudent::print(); // Call base class print function
        cout << "New ID: " << newid << endl;
    }
};
int main() {
    // Declare and initialize a student object
    student std;
    std.setStudentNumber(1);
    std.setStudentName("Ronish Shrestha");
    std.setStudentAverage(89.5);
    cout << "Student Information:" << endl;
    std.print();

    // Declare and initialize a master object
    master mst;
    mst.setStudentNumber(2);
    mst.setStudentName("John Wick");
    mst.setStudentAverage(91.2);
    mst.setLevel(2);
    mst.setYear(2022);
    mst.setNewid(12345);
    cout << "\nMaster Student Information:" << endl;
    mst.print();

    return 0;
}
