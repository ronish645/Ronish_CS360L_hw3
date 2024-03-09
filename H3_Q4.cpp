#include <iostream>
#include <cstring> // For strcpy

using namespace std;

class Test {
    char paper[20];
    int marks;

public:
    // Function 1: Default constructor
    Test() {
        strcpy(paper, "Computer");
        marks = 0;
    }

    // Function 2: Constructor with a char array parameter
    Test(char p[]) {
        strcpy(paper, p);
        marks = 0;
    }

    // Function 3: Constructor with an int parameter
    Test(int m) {
        strcpy(paper, "Computer");
        marks = m;
    }

    // Function 4: Constructor with a char array and int parameters
    Test(char p[], int m) {
        strcpy(paper, p);
        marks = m;
    }

    // Function to display the contents of an object
    void display() {
        cout << "Paper: " << paper << ", Marks: " << marks << endl;
    }
};

int main() {
    // Executes Function 1 (Default constructor)
    Test obj1;
    obj1.display();

    // Executes Function 2 (Constructor with char array parameter)
    char subject1[] = "Mathematics";
    Test obj2(subject1);
    obj2.display();

    // Executes Function 3 (Constructor with int parameter)
    Test obj3(89);
    obj3.display();

    // Executes Function 4 (Constructor with char array and int parameters)
    char subject2[] = "Physics";
    Test obj4(subject2, 88);
    obj4.display();

    return 0;
}
