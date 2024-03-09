#include <iostream>
using namespace std;

class Seminar{
    int time;
public:
    Seminar() //Function 1
    {
        time = 30;
        cout << "Seminar starts now" << endl;
    }
    void lecture() //Function 2
    {
        cout << "Lectures in the seminar on" << endl;
    }
    Seminar(int duration) //Function 3
    {
        time = duration;
        cout << "Seminar starts now" << endl;
    }
    ~Seminar() //Function 4
    {
        cout << "Thanks" << endl;
    }
};

int main() {
    Seminar seminar1; // Executes Function 1 (default constructor)
    Seminar seminar2(60); // Executes Function 3 (parameterized constructor with duration)
    return 0;
}
