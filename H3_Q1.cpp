#include <iostream>
using namespace std;

class A {
public:
    A(); // Default constructor
    A(int); // Parameterized constructor
    A(const A&); // Copy constructor
    ~A(); // Destructor

public:
    void operator=(const A& rhs); // Assignment operator
    void Print(); // Prints the current value of x
    void PrintC() const; // Prints the current value of x, can be called on const objects

    int x; // Public data member

public:
    int& X(); // Returns a reference to x, allowing for direct modification
};

// Definitions of A's members
A::A() : x(0) {
    cout << "Hello from A::A() Default constructor" << endl;
}

A::A(int i) : x(i) {
    cout << "Hello from A::A(int) constructor" << endl;
}

A::A(const A& a) : x(a.x) {
    cout << "Hello from A::A(const A&) constructor" << endl;
}

A::~A() {
    cout << "Hello from A::A destructor" << endl;
}

void A::operator=(const A& rhs) {
    x = rhs.x;
    cout << "Hello from A::operator=" << endl;
}

void A::Print() {
    cout << "A::Print(), x " << x << endl;
}

void A::PrintC() const {
    cout << "A::PrintC(), x " << x << endl;
}

int& A::X() { 
    return x; 
}

// Function to pass an object of A by value
void PassAByValue(A a) {
    cout << "PassAByValue, a.x " << a.x << endl;
    a.x++; // Modifies the copy, not the original object
    a.Print();
    a.PrintC();
}

// Function to pass an object of A by reference
void PassAByReference(A& a) {
    cout << "PassAByReference, a.x " << a.x << endl;
    a.x++; // Modifies the original object
    a.Print();
    a.PrintC();
}

// Function to pass an object of A by const reference
void PassAByConstReference(const A& a) {
    cout << "PassAByConstReference, a.x " << a.x << endl;
    a.PrintC(); // Can only call const functions
    // a.Print(); // Uncommenting this line would cause a compiler error because a is a const reference
}

// Function to pass an object of A by pointer
void PassAByPointer(A* a) {
    cout << "PassAByPointer, a->x " << a->x << endl;
    a->x++; // Modifies the original object
    a->Print();
    a->PrintC();
}

int main() {
    cout << "Creating a0"; getchar();
    A a0; // Calls default constructor

    cout << "Creating a1"; getchar();
    A a1(1); // Calls parameterized constructor

    cout << "Creating a2"; getchar();
    A a2(a0); // Calls copy constructor

    cout << "Creating a3"; getchar();
    A a3 = a0; // Calls copy constructor

    cout << "Assigning a3 = a1"; getchar();
    a3 = a1; // Calls assignment operator

    // Demonstrating function calls with various passing mechanisms
    cout << "PassAByValue(a1)"; getchar();
    PassAByValue(a1);
    cout << "After PassAByValue(a1)" << endl;
    a1.Print();

    cout << "PassAByReference(a1)"; getchar();
    PassAByReference(a1);
    cout << "After PassAByReference(a1)" << endl;
    a1.Print();

    cout << "PassAByConstReference(a1)"; getchar();
    PassAByConstReference(a1);
    cout << "After PassAByConstReference(a1)" << endl;
    a1.Print();

    cout << "PassAByPointer(&a1)"; getchar();
    PassAByPointer(&a1);
    cout << "After PassAByPointer(&a1)" << endl;
    a1.Print();

    cout << "a1.X() = 10"; getchar();
    a1.X() = 10; // Directly modifies x of a1 through reference
    a1.Print();

    // The problematic call PassAByConstReference(20) is omitted as it doesn't conform to the program's design
    // and would result in a compilation error without an implicit conversion constructor

    return 0;
}
