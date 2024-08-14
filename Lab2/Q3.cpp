#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
private:
    char *name;
    int code;
    char *designation;
    int yearsOfExperience;
    int age;

    // Function to initialize data
    void initialize(const char *empName, int empCode, const char *empDesignation, int empYearsOfExperience, int empAge)
    {
        name = new char[strlen(empName) + 1];
        strcpy(name, empName);

        code = empCode;

        designation = new char[strlen(empDesignation) + 1];
        strcpy(designation, empDesignation);

        yearsOfExperience = empYearsOfExperience;
        age = empAge;
    }

public:
    // Default constructor
    Employee() : name(nullptr), code(0), designation(nullptr), yearsOfExperience(0), age(0) {}

    // Parameterized constructor
    Employee(const char *empName, int empCode, const char *empDesignation, int empYearsOfExperience, int empAge)
    {
        initialize(empName, empCode, empDesignation, empYearsOfExperience, empAge);
    }

    // Copy constructor
    Employee(const Employee &other)
    {
        initialize(other.name, other.code, other.designation, other.yearsOfExperience, other.age);
    }

    // Destructor
    ~Employee()
    {
        delete[] name;
        delete[] designation;
    }

    static void displayMessage()
    {
        cout << "Welcome to the Employee Management System" << endl;
    }

    friend void displayEmployeeInfo(const Employee &emp);

    void input()
    {
        char tempName[100];
        char tempDesignation[100];

        cout << "Enter employee name: ";
        cin.ignore();
        cin.getline(tempName, 100);

        cout << "Enter employee code: ";
        cin >> code;

        cout << "Enter employee designation: ";
        cin.ignore();
        cin.getline(tempDesignation, 100);

        cout << "Enter years of experience: ";
        cin >> yearsOfExperience;

        cout << "Enter age: ";
        cin >> age;

        name = new char[strlen(tempName) + 1];
        strcpy(name, tempName);

        designation = new char[strlen(tempDesignation) + 1];
        strcpy(designation, tempDesignation);
    }

    void display() const
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Code: " << code << endl;
        cout << "Designation: " << designation << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
        cout << "Age: " << age << endl;
    }
};

void displayEmployeeInfo(const Employee &emp)
{
    cout << "Employee Information (via friend function):" << endl;
    emp.display();
}

int main()
{
    Employee::displayMessage();

    Employee emp1;
    emp1.input();
    emp1.display();

    Employee emp2 = emp1;      // Using copy constructor
    displayEmployeeInfo(emp2); // Using friend function

    return 0;
}