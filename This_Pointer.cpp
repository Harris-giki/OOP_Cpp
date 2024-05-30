#include <iostream>
#include <string>
#include <cstdlib> // For system("cls")
using namespace std;

class product {
protected:
    string name;
    string description;
    int price;
    int inventory;

public:
    product() {}

    // Function to set the details of the product
    void setDetails(string name, string description, int price, int inventory) {
        this->name = name;
        this->description = description;
        this->price = price;
        this->inventory = inventory;
    }
};

class Grocery : public product {
public:
    // Function to input details of a grocery product
    void inputDetails() {
        cout << "Enter grocery name: ";
        cin >> name;
        cout << "Enter grocery description: ";
        cin.ignore(); // Ignore newline character
        getline(cin, description);
        cout << "Enter grocery price: ";
        cin >> price;
        cout << "Enter grocery inventory size: ";
        cin >> inventory;
    }

    // Function to display details of a grocery product
    void display() {
        cout << "-------------- YOU ENTERED THE FOLLOWING PRODUCT DETAILS --------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << endl;
        cout << "Inventory: " << inventory << endl;
    }
};

class Perishable {
protected:
    string expirationDate;

public:
    // Function to input expiration date of a perishable product
    void inputExpirationDate() {
        cout << "Enter expiration date: ";
        cin >> expirationDate;
    }

    // Function to display expiration date of a perishable product
    void displayExpiration() {
        cout << "Expiration Date: " << expirationDate << endl;
    }
};

class PerishableGrocery : public Grocery, public Perishable {
public:
    // Function to input all details of a perishable grocery product
    void inputAllDetails() {
        Grocery::inputDetails();
        Perishable::inputExpirationDate();
    }

    // Function to display all details of a perishable grocery product
    void displayAllDetails() {
        cout << "Perishable Grocery Details:" << endl;
        Grocery::display();
        Perishable::displayExpiration();
    }
};

class Clothing : public product {
private:
    int size;
    string brand;
    string color;

public:
    // Function to input details of a clothing product
    void inputDetails() {
        cout << "Enter cloth name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        cout << "Enter cloth description: ";
        getline(cin, description);
        cout << "Enter cloth price: ";
        cin >> price;
        cout << "Enter cloth inventory size: ";
        cin >> inventory;
        cout << "Enter cloth brand: ";
        cin >> brand;
        cout << "Enter cloth color: ";
        cin >> color;
        cout << "Enter cloth size (integer): ";
        cin >> size;
    }

    // Function to display details of a clothing product
    void display() {
        cout << "-------------- YOU ENTERED THE FOLLOWING PRODUCT DETAILS --------------" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << endl;
        cout << "Inventory: " << inventory << endl;
        cout << "Color: " << color << endl;
        cout << "Cloth size: " << size << endl;
    }
};

class Electronics : public product {
private:
    string brand;
    string use;

public:
    // Function to input details of an electronic product
    void inputDetails() {
        cout << "Enter electronic device name: ";
        cin >> name;
        cout << "Enter electronic device description: ";
        cin.ignore(); // Ignore newline character
        getline(cin, description);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter inventory: ";
        cin >> inventory;
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter use of the electronic device: ";
        cin >> use;
    }

    // Function to display details of an electronic product
    void display() {
        cout << "-------------- YOU ENTERED THE FOLLOWING PRODUCT DETAILS --------------" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << endl;
        cout << "Inventory: " << inventory << endl;
        cout << "Use: " << use << endl;
    }
};

class Furniture : public product {
private:
    string woodType;
    string color;

public:
    // Function to input details of a furniture product
    void inputDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter description: ";
        cin.ignore(); // Ignore newline character
        getline(cin, description);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter inventory: ";
        cin >> inventory;
        cout << "Enter wood type: ";
        cin >> woodType;
        cout << "Enter color: ";
        cin >> color;
    }

    // Function to display details of a furniture product
    void display() {
        cout << "-------------- YOU ENTERED THE FOLLOWING PRODUCT DETAILS --------------" << endl;
        cout << "Wood Type: " << woodType << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << endl;
        cout << "Inventory: " << inventory << endl;
        cout << "Color: " << color << endl;
    }
};

int main() {
    char choice;
    do {
        system("cls"); // Clear the screen
        int option;
        cout << "-------------- WELCOME TO THE PRODUCT MANAGEMENT SYSTEM --------------" << endl;
        cout << endl;
        cout << "SELECT THE PRODUCT WHOSE DETAILS YOU WANT TO ENTER" << endl;
        cout << "1. Grocery" << endl;
        cout << "2. Electronic Device" << endl;
        cout << "3. Furniture" << endl;
        cout << "4. Clothing" << endl;
        cout << "5. Perishable Grocery" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                Grocery obj;
                obj.inputDetails();
                obj.display();
                break;
            }
            case 2: {
                Electronics obj;
                obj.inputDetails();
                obj.display();
                break;
            }
            case 3: {
                Furniture obj;
                obj.inputDetails();
                obj.display();
                break;
            }
            case 4: {
                Clothing obj;
                obj.inputDetails();
                obj.display();
                break;
            }
            case 5:
            {
                PerishableGrocery perishable;
                cout << "Enter Perishable Grocery Details:" << endl;
                perishable.inputAllDetails();
                perishable.displayAllDetails();
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to enter details for another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the product management system!" << endl;

    return 0;
}
