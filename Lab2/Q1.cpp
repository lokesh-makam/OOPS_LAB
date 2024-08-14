#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string *arr;
    int n;
    string name;
    Employee()
    { // default constructor
        cout << "Welcome to SVNIT" << endl;
    }
    ~Employee()
    {
        cout << "Distructor called" << endl;
    }
    Employee(int n)
    {
        this->n = n;
        arr = new string[n];
    }
    Employee(Employee *st)
    {
        this->name = st->name;
    }
    void getInput()
    {
        cout << "enter thr name:" << endl;
        cin >> this->name;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the string:" << endl;
            cin >> arr[i];
        }
    }
    void check(string str)
    {
        int count = 0;
        for (int i = 0; i < arr->size(); i++)
        {
            if (arr[i] == str)
            {
                count++;
            }
        }
        if (count == 0)
        {
            cout << "the string  " << str << " is not present in the array" << endl;
        }
        else
        {
            cout << "The string is present in the the array  -> " << count << " times" << endl;
        }
    }
};

int main()
{
    Employee a;
    cout << "Enter the length of the array:" << endl;
    int n;
    cin >> n;
    Employee b(n);
    b.getInput();
    Employee *c(&b); // copy constructor
    cout << "copy constructor  is called: " << c->name << endl;
    cout << "enter the string:" << endl;
    string str;
    cin >> str;
    b.check(str);
    return 0;
}