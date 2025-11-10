
#include <iostream>
#include <string>
using namespace std;

class Employee 
{
private:
    string name;
    int id;
    double salary;
    static const string company_name;  // static constant string
    static int employee_count;

public:
    // Constructor with constructor initializer list
    Employee(string n, int i, double s) : name(n), id(i), salary(s) 
    {
        employee_count++;
    }

    // Copy constructor
    Employee(const Employee & emp) : name(emp.name), id(emp.id), salary(emp.salary) 
    {
        employee_count++;
    }

    // Const function to display data
    void display() const 
    {
        cout << "Company : " << company_name << endl;
        cout << "Name is : " << name << endl;
        cout << "ID is   : " << id << endl;
        cout << "Salary is : " << salary << endl;
    }

    // Using this pointer
    void set_salary(double salary) 
    {
        this->salary = salary;
    }

    void set_name(string emp_name) 
    {
        this->name = emp_name;
    }

    // Static function
    static void showTotal_employees() 
    {
        cout << "Company Name is  " << company_name << endl;
        cout << "Total employees in " << company_name << " are : " << employee_count << endl;
    }
};

// Static members initialization
const string Employee::company_name = "TechSolutions";
int Employee::employee_count = 0;

// Function passing object by value
void display_employee(Employee emp) 
{
    emp.display();
}

// Function returning object
Employee create_employee(string name, int id, double salary) 
{
    return Employee(name, id, salary);
}

int main() 
{
    // Creating employees
    Employee emp1("maryam", 50, 5000);
    Employee emp2("fatima", 80, 6000);

    Employee::showTotal_employees();
    cout << endl;

    // Dynamic object creation
    Employee* emp3 = new Employee("noor", 43, 7000);
    emp3->display();
    cout << endl;

    // Pass object to function
    cout << "Pass by value:" << endl;
    display_employee(emp1);
    cout << endl;

    // Return object from function
    Employee emp4 = create_employee("fajar", 49, 6500);
    emp4.display();
    cout << endl;

    // Deep copy 
    cout << "Deep Copy ";
    Employee original("musfirah", 48, 7000);
    cout << endl;

    cout << "Before Modification:" << endl;
    original.display();
    cout << endl;

    // Creating copy and modifying original
    Employee deep_copy = original;
    original.set_name("musfirah");
    original.set_salary(7500);

    cout << "After Modification:" << endl;
    original.display();
    cout << endl;

    //Deep Copy-Copying object
    cout << "Copy Object:" << endl;
    deep_copy.display();
    cout << endl;
    
    //Shallow Copy 
    cout << "Shallow copy" << endl;
    Employee* shallow = &original;
    original.display();
   

    delete emp3;
    return 0;
}
