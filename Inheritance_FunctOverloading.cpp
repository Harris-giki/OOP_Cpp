#include <iostream>
#include <windows.h>
using namespace std;

void basic_display(); //forward declaration of the display function
class FoodItems { //making an abstarct base class
protected:
    char name[100];
    int ingredients;
    char ingredients_yes;
    float price;
    int num_of_ingredients;

public:
    FoodItems() : price(0), ingredients(0) {} //constructor to rightly intialize the float and int variable

    virtual void makePayments() = 0; // using virtual functions to demonstrate the use of polymorphsim
    virtual void placeOrder() = 0; // using virtual functions to demonstrate the use of polymorphsim
};

class Pizza : public FoodItems {
public:
   void placeOrder() override {
    cout << "-------------WELCOME TO THE ORDER PLACING DOMAIN-------------" << endl;
    cout << "ENTER YOUR NAME: ";
    cin >> name;
    cout << endl;
    cout << "DO you want to have extra ingredients in you pizza: (select 'y'||'Y' if yes) " << endl;
    cout << "Select any other character if you donot want extra ingredients in your pizza:" << endl;
    cin >> ingredients_yes;
    if(ingredients_yes == 'y'||ingredients_yes == 'Y')
    {
    cout << "ENTER THE NUMBER OF EXTRA INGREDIENTS YOU WANT (select integers): ";
    cin >> num_of_ingredients;
	}
	system("cls");
    basic_display();
    cout << endl;
    do {
        if (num_of_ingredients != 0) {
            cout << "CHOOSE FROM THE FOLLOWING INGREDIENTS" << endl;
            cout << "1. extra cheese ($11 per selection)" << endl;
            cout << "2. extra ketchup ($12 per selection)" << endl;
            cout << "3. extra chicken ($15 per selection)" << endl;
            cout << "SELECT 0 IF YOU WANT NO EXTRA INGREDIENTS" << endl;
            cin >> ingredients;
            if (ingredients != 0 && ingredients != 1 && ingredients != 2 && ingredients != 3) {
                cout << "Wrong selection, Please try again!" << endl;
            }
        }
    } while (num_of_ingredients != 0 && (ingredients != 0 && ingredients != 1 && ingredients != 2 && ingredients != 3));
    cout << endl << name << " " <<"YOUR ORDER IS PLACED SUCCESSFULLY" << endl;
}


    void makePayments() override { //making a function to show the bill generated
    if(ingredients==0)
    {
    	price=50;
    	cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
	else if(ingredients==1)
    {
        price = num_of_ingredients * 50;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
    }
    else if(ingredients==2)
    {
    	price = num_of_ingredients * 50 *12;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
	else if(ingredients==3)
    {
    	price = num_of_ingredients * 15*50;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
}
};

class Sushi : public FoodItems {
public:
     void placeOrder() override {
    cout << "-------------WELCOME TO THE ORDER PLACING DOMAIN-------------" << endl;
    cout << "ENTER YOUR NAME: ";
    cin >> name;
    cout << endl;
    cout << "DO you want to have extra ingredients in you sushi: (select 'y'||'Y' if yes) " << endl;
    cout << "Select any other character if you donot want extra ingredients in your Sushi:" << endl;
    cin >> ingredients_yes;
    if(ingredients_yes == 'y'||ingredients_yes == 'Y')
    {
    cout << "ENTER THE NUMBER OF EXTRA INGREDIENTS YOU WANT (select integers): ";
    cin >> num_of_ingredients;
	}
	system("cls");
    basic_display();
    cout << endl;
    do {
        if (num_of_ingredients != 0) {
            cout << "CHOOSE FROM THE FOLLOWING INGREDIENTS" << endl;
            cout << "1. extra soya sauce ($11 per selection)" << endl;
            cout << "2. extra spices and soup ($12 per selection)" << endl;
            cout << "3. extra chunks ($15 per selection)" << endl;
            cout << "SELECT 0 IF YOU WANT NO EXTRA INGREDIENTS" << endl;
            cin >> ingredients;
            if (ingredients != 0 && ingredients != 1 && ingredients != 2 && ingredients != 3) {
                cout << "Wrong selection, Please try again!" << endl;
            }
        }
    } while (num_of_ingredients != 0 && (ingredients != 0 && ingredients != 1 && ingredients != 2 && ingredients != 3));
    cout << endl << name << " " <<"YOUR ORDER IS PLACED SUCCESSFULLY" << endl;
}

    void makePayments() override { //making a function to show the bill generated
    if(ingredients==0)
    {
    	price=50;
    	cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
	else if(ingredients==1)
    {
        price = num_of_ingredients * 50;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
    }
    else if(ingredients==2)
    {
    	price = num_of_ingredients * 50 *12;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
	else if(ingredients==3)
    {
    	price = num_of_ingredients * 15*50;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
}
};

class Tacos : public FoodItems {
public:
    void placeOrder() override {
    cout << "-------------WELCOME TO THE ORDER PLACING DOMAIN-------------" << endl;
    cout << "ENTER YOUR NAME: ";
    cin >> name;
    cout << endl;
    cout << "DO you want to have extra ingredients in you Tacos: (select 'y'||'Y' if yes) " << endl;
    cout << "Select any other character if you donot want extra ingredients in your Tacos:" << endl;
    cin >> ingredients_yes;
    if(ingredients_yes == 'y'||ingredients_yes == 'Y')
    {
    cout << "ENTER THE NUMBER OF EXTRA INGREDIENTS YOU WANT (select integers): ";
    cin >> num_of_ingredients;
	}
	system("cls");
    basic_display();
    cout << endl;
    do {
        if (num_of_ingredients != 0) {
            cout << "CHOOSE FROM THE FOLLOWING INGREDIENTS" << endl;
            cout << "1. extra cheese ($11 per selection)" << endl;
            cout << "2. extra ketchup ($12 per selection)" << endl;
            cout << "3. extra chicken ($15 per selection)" << endl;
            cout << "SELECT 0 IF YOU WANT NO EXTRA INGREDIENTS" << endl;
            cin >> ingredients;
            if (ingredients != 0 && ingredients != 1 && ingredients != 2 && ingredients != 3) {
                cout << "Wrong selection, Please try again!" << endl;
            }
        }
    } while (num_of_ingredients != 0 && (ingredients != 0 && ingredients != 1 && ingredients != 2 && ingredients != 3));
    cout << endl << name << " " <<"YOUR ORDER IS PLACED SUCCESSFULLY" << endl;
}



    void makePayments() override { //making a function to show the bill generated
    if( ingredients == 0 )
    {
    	price=50;
    	cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
	else if( ingredients == 1) 
    {
        price = num_of_ingredients * 50*11;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
    }
    else if( ingredients == 2 )
    {
    	price = num_of_ingredients * 50 *12;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
	else if( ingredients == 3 )
    {
    	price = num_of_ingredients * 15*50;
        cout << "THE PAYMENT FOR YOUR ORDER IS $" << price << endl;
	}
}
};
void basic_display()
{
	
	cout << "---------------WELCOME TO THE SUPREME ECONOMICAL RESTAURANT PAKISTAN--------------" << endl;
}
int main() { //entering the portal of the restaurant and then asking the user that which menu item he wants
char choice2;
    do{
	system("cls");
	int choice;
  	basic_display();
    cout << endl;
    cout << "WHAT DO YOU WANT TO HAVE IN THE MEAL TODAY?" << endl;
    cout << endl;
	cout << "1. PIZZA (STANDARD PRICE - $50)" << endl;
    cout << "================================"<<endl;
    cout << "2. SUSHI (STANDARD PRICE - $50)" << endl;
    cout << "================================"<<endl;
    cout << "3. TACOS (STANDARD PRICE - $50)" << endl;
 	cout << "================================"<<endl;
    cin >> choice;

    switch (choice) {
        case 1: { //making object of the subclass and using functions to output input details;
            Pizza pizza;
            pizza.placeOrder();
            pizza.makePayments();
            break;
        }
        case 2: { //making object of the subclass and using functions to output input details;
            Sushi sushi;
            sushi.placeOrder();
            sushi.makePayments();
            break;
        }
        case 3: { //making object of the subclass and using functions to output input details;
            Tacos tacos;
            tacos.placeOrder();
            tacos.makePayments();
            break;
        }
        default: //giving default case in case of in valid choice;
            cout << "Invalid choice. Please select a valid option." << endl;
    }
    cout << endl;
    cout << endl;
    cout << "DO YOU WANT TO PLACE A NEW ORDER" << endl;
    cout << "SELECT 'y||Y' if YES or any other character if NO" << endl;
    cin >> choice2;
} while(choice2=='y' || choice2=='Y' );

    return 0;
}

