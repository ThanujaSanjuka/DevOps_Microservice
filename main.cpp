#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    string indexNumber;

public:
    // Constructor to initialize details
    Student(string studentName, string studentIndex) {
        name = studentName;
        indexNumber = studentIndex;
    }

    // Const member function to display the record
    void displayDetails() const {
        cout << "=====================================" << endl;
        cout << "       Student Record System         " << endl;
        cout << "=====================================" << endl;
        cout << "Name         : " << name << endl;
        cout << "Index Number : " << indexNumber << endl;
        cout << "System Status: CI/CD Pipeline Active!" << endl;
        cout << "=====================================" << endl;
    }
};

int main() {
    // Creating an object of the Student class
    Student currentStudent("Thanuja Sanjuka", "24/ENG/146");
    
    currentStudent.displayDetails();
    
    return 0;
}
