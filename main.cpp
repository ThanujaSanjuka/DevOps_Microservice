#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class EngineeringStudent {
private:
    string name;
    string indexNumber;
    string department; 

public:
    
    EngineeringStudent(string n, string i, string d) : name(n), indexNumber(i), department(d) {}

    
    string getIndex() const { 
        return indexNumber; 
    }

    
    friend ostream& operator<<(ostream& os, const EngineeringStudent& student);


    void saveToDatabase(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << name << " | " << indexNumber << " | " << department << "\n";
            file.close();
            cout << "[SYSTEM LOG] Record successfully saved to " << filename << endl;
        } else {
            cerr << "[ERROR] Could not open database file!" << endl;
        }
    }
};


ostream& operator<<(ostream& os, const EngineeringStudent& student) {
    os << "======================================\n";
    os << "     Engineering Student Database     \n";
    os << "======================================\n";
    os << "Name         : " << student.name << "\n";
    os << "Index Number : " << student.indexNumber << "\n";
    os << "Department   : " << student.department << "\n"; 
    os << "Environment  : Production (CI/CD)\n";
    os << "======================================\n";
    return os;
}

int main() {
    cout << "[SYSTEM LOG] Initializing Microservice...\n\n";

    
    EngineeringStudent student("Thanuja Sanjuka Silva", "24/ENG/146", "Software Engineering & DevOps based");

    
    cout << student;

    
    student.saveToDatabase("student_database.txt");

    cout << "\n[SYSTEM LOG] Execution Completed Successfully.\n";
    return 0;
}
