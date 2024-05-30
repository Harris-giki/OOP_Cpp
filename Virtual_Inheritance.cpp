#include <iostream>
#include <string>

using namespace std;

// Base class representing an employee
class employee {
protected:
    string name;
    int employeeID;

public:
    // Constructor to initialize name and employeeID
    employee(string name, int employeeID) : name(name), employeeID(employeeID) {}

    // Function to display employee information
    void displayInfo() {
        cout << "EMPLOYEE NAME: " << name << endl;
        cout << "EMPLOYEE ID: " << employeeID << endl;
    }
};

// Derived class representing an engineer, inheriting virtually from employee
class engineer : virtual public employee {
protected:
    string specialization;

public:
    // Constructor to initialize name, employeeID, and specialization
    engineer(string name, int employeeID, string specialization)
        : employee(name, employeeID), specialization(specialization) {}

    // Function specific to engineers
    void developSoftware() {
        cout << "SPECIALIZATION: " << specialization << endl;
    }
};

// Derived class representing a manager, inheriting virtually from employee
class manager : virtual public employee {
protected:
    string department;

public:
    // Constructor to initialize name, employeeID, and department
    manager(string name, int employeeID, string department)
        : employee(name, employeeID), department(department) {}

    // Function specific to managers
    void manageTeam() {
        cout << "DEPARTMENT: " << department << endl;
    }
};

// Derived class representing a tech lead, inheriting from both manager and engineer
class techled : public manager, public engineer {
public:
    // Constructor to initialize name, employeeID, department, and specialization
    techled(string name, int employeeID, string department, string specialization)
        : employee(name, employeeID), manager(name, employeeID, department), engineer(name, employeeID, specialization) {}

    // Function specific to tech leads
    void leadTeam() {
        cout << "TECHLED NAME: " << name << endl;
        cout << "TECHLED ID: " << employeeID << endl;
        engineer::developSoftware(); // Call engineer's function
        manager::manageTeam(); // Call manager's function
    }
};

int main() {
    char choice;

    do {
        cout << "----------- WELCOME TO THE EMPLOYEE MANAGEMENT SYSTEM ----------" << endl;
        cout << endl;
        cout << "Select the type of employee:" << endl;
        cout << "1. Engineer" << endl;
        cout << "2. Manager" << endl;
        cout << "3. Tech Lead" << endl;
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        switch (option) {
            case 1: {
                string name, specialization;
                int employeeID;
                cout << "Enter engineer's name: ";
                cin >> name;
                cout << "Enter engineer's employee ID: ";
                cin >> employeeID;
                cout << "Enter engineer's specialization: ";
                cin >> specialization;

                engineer obj(name, employeeID, specialization);
                cout << "--------------DISPLAY FUNCTION BY PARENT CLASS--------------"<<endl;
                obj.displayInfo(); // Display employee info
                cout<<"--------------- DISPLAY FUNCTION BY DERIVED CLASS--------------"<<endl;
                obj.developSoftware(); // Develop software (engineer specific)
                break;
            }
            case 2: {
                string name, department;
                int employeeID;
                cout << "Enter manager's name: ";
                cin >> name;
                cout << "Enter manager's employee ID: ";
                cin >> employeeID;
                cout << "Enter manager's department: ";
                cin >> department;

                manager obj(name, employeeID, department);
                
                cout << "--------------DISPLAY FUNCTION BY PARENT CLASS--------------"<<endl;
                obj.displayInfo(); // Display employee info
                cout<<"--------------- DISPLAY FUNCTION BY DERIVED CLASS--------------"<<endl;
                obj.manageTeam(); // Manage team (manager specific)
                break;
            }
            case 3: {
                string name, department, specialization;
                int employeeID;
                cout << "Enter tech lead's name: ";
                cin >> name;
                cout << "Enter tech lead's employee ID: ";
                cin >> employeeID;
                cout << "Enter tech lead's department: ";
                cin >> department;
                cout << "Enter tech lead's specialization: ";
                cin >> specialization;

                techled obj(name, employeeID, department, specialization);
                
                cout << "--------------DISPLAY FUNCTION BY PARENT CLASS--------------"<<endl;
                obj.displayInfo(); // Display employee info
                obj.manageTeam(); // Manage team (manager specific)
                obj.developSoftware(); // Develop software (engineer specific)
                cout<<"--------------- DISPLAY FUNCTION BY DERIVED CLASS--------------"<<endl;
                obj.leadTeam(); // Lead team (tech lead specific)
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
