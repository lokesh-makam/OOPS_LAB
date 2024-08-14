#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    string name;
    char sex;
    int age;
    int wardNumber;
    int bedNumber;
    string illness;
    string admissionDate;

public:
    // Constructor with parameters
    Patient(string n, char s, int a, int w, int b, string ill, string date) {
        name = n;
        sex = s;
        age = a;
        wardNumber = w;
        bedNumber = b;
        illness = ill;
        admissionDate = date;
    }

    // Default constructor
    Patient() {
        name = "";
        sex = 'M';
        age = 0;
        wardNumber = 0;
        bedNumber = 0;
        illness = "";
        admissionDate = "";
    }

    // Copy constructor
    Patient(const Patient& p) {
        name = p.name;
        sex = p.sex;
        age = p.age;
        wardNumber = p.wardNumber;
        bedNumber = p.bedNumber;
        illness = p.illness;
        admissionDate = p.admissionDate;
    }

    // Destructor
    ~Patient() {
        // Clean up resources if needed
    }

    // Function to display patient details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
        cout << "Ward Number: " << wardNumber << endl;
        cout << "Bed Number: " << bedNumber << endl;
        cout << "Nature of Illness: " << illness << endl;
        cout << "Date of Admission: " << admissionDate << endl;
    }
};

int main() {
    // Creating a patient object using parameterized constructor
    Patient p1("John Doe", 'M', 45, 12, 5, "Flu", "2024-08-14");

    // Displaying patient details
    p1.display();

    return 0;
}
