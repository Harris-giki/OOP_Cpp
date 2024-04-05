#include <iostream>
#include <cstdlib>  // For system("cls") 
using namespace std;

// Class definition for the engine
class Engine {
public:
    int cylinders;    // the number of cylinders in the engine
    int horsepower;   // the number of horsepower in the engine

    // Default constructor to initialize values
    Engine() : cylinders(0), horsepower(0) {}
};

// Class definition for the car
class Car {
private:
    string make;      // manufacturer of the car
    string model;
    Engine engine;     // Composition: Car has an Engine

public:
    // Default constructor to initialize values
    Car() : make(""), model(""), engine() {}

    // Function to get input from the user
    void getInput() {
        cout << "------------------------------------ WELCOME TO THE CAR CLUB ------------------------------------" << endl;
        cout << "ENTER THE FOLLOWING DETAILS OF YOUR CAR." << endl;
        cout << "==============================" << endl;
        cout << "ENTER THE MAKER'S NAME: ";
        cin >> make;
        cout << "==============================" << endl;
        cout << "ENTER THE MODEL'S NAME: ";
        cin >> model;
        cout << "==============================" << endl;
        cout << "ENTER THE NUMBER('S) OF CYLINDERS IN YOUR CAR: ";
        cin >> engine.cylinders;
        cout << "==============================" << endl;
        cout << "ENTER THE HORSEPOWER NAME: ";
        cin >> engine.horsepower;
        cout << "==============================" << endl;
    }

    // Function to print information about the car
    void printInformation() {
        cout << "------------------------------------ THE DETAILS OF THE CAR ARE: ------------------------------------" << endl;
        cout << "THE MAKER'S NAME: " << make << endl;
        cout << "THE MODEL'S NAME: " << model << endl;
        cout << "THE NUMBER('S) OF CYLINDERS IN YOUR CAR: " << engine.cylinders << endl;
        cout << "THE HORSEPOWER NAME: " << engine.horsepower << endl;
    }
};

// Function to print ASCII art
void printAsciiArt() {
    cout << "\033[31m";
    cout << "      _____        _____       _____               _____   ____        ____   ____      _____   \n";
    cout << "  ___|\\    \\   ___|\\    \\  ___|\\    \\          ___|\\    \\ |    |      |    | |    |___|\\     \\  \n";
    cout << " /    /\\    \\ /    /\\    \\|    |\\    \\        /    /\\    \\|    |      |    | |    |    |\\     \\ \n";
    cout << "|    |  |    |    |  |    |    | |    |      |    |  |    |    |      |    | |    |    | |     |\n";
    cout << "|    |  |____|    |__|    |    |/____/       |    |  |____|    |  ____|    | |    |    | /_ _ / \n";
    cout << "|    |   ____|    .--.    |    |\\    \\       |    |   ____|    | |    |    | |    |    |\\    \\  \n";
    cout << "|    |  |    |    |  |    |    | |    |      |    |  |    |    | |    |    | |    |    | |    | \n";
    cout << "|\\ ___\\/    /|____|  |____|____| |____|      |\\ ___\\/    /|____|/____/|\\___\\_|____|____|/____/| \n";
    cout << "| |   /____/ |    |  |    |    | |    |      | |   /____/ |    |     || |    |    |    /     || \n";
    cout << "\\|___|    | |____|  |____|____| |____|       \\|___|    | |____|_____|/\\|____|____|____|_____|/ \n";
    cout << "   \\( |____|/  \\(      )/   \\(     )/           \\( |____|/  \\(    )/      \\(   )/   \\(    )/    \n";
    cout << "    '   )/      '      '     '     '             '   )/      '    '        '   '     '    '     \n";
    cout << "\033[0m";  // Reset color to default
}

int main() {
    char choice;
    do {
    	system("cls");
        printAsciiArt();
        Car obj;
        obj.getInput();
        system("cls");  
        printAsciiArt();
        obj.printInformation();
        cout << "\n\nPRESS 'Y' TO STORE DATA AGAIN: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}