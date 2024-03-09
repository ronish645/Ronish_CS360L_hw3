#include <iostream>
using namespace std;

class Sample {
private:
    int x;
    double y;
public:
    // Constructor 1
    Sample() : x(0), y(0.0) {
        // Member initializer list sets both x and y to 0
    }

    // Constructor 2
    Sample(int xValue) : x(xValue), y(0.0) {
        // Member initializer list sets x to the argument xValue and y to 0
    }

    // Constructor 3
    Sample(int xValue, int yValue) : x(xValue), y(yValue) {
        // Member initializer list sets x to xValue and y to yValue (int converted to double)
    }

    // Constructor 4
    Sample(int xValue, double yValue) : x(xValue), y(yValue) {
        // Member initializer list sets x to xValue and y to yValue
    }

    // A member function to print x and y
    void print() {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    // Creating objects using different constructors
    Sample s1; // Uses Constructor 1
    Sample s2(10); // Uses Constructor 2
    Sample s3(20, 30); // Uses Constructor 3
    Sample s4(40, 50.5); // Uses Constructor 4

    // Printing values to check the constructors
    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    cout << "s3: ";
    s3.print();

    cout << "s4: ";
    s4.print();

    return 0;
}
