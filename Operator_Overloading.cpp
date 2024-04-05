#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Cplus_mystring {
private:
    int size;
    char *array;
public:
    Cplus_mystring() {
        cout << "----------- THE C++ OPERATOR OVERLOADING PROGRAM -----------" << endl;
        cout<<endl;
    }
    
    Cplus_mystring(int main_size) {
        this->size = main_size;
        array = new char[size];
        cout<<endl;
        cout << "ARRAY SIZE SET TO: " << size << endl;
    }

    Cplus_mystring(char main_input[]) {
        // Assuming main_input is null-terminated
        this->size = strlen(main_input);
        array = new char[size];
        for (int i = 0; i < size; i++) {
            array[i] = main_input[i];
        }
    }

    int return_size() {
        return size;
    }

    void operator+(Cplus_mystring obj) {
  	    	int newsize = size+obj.size;

        char *concatenate = new char[size + obj.size];
        int i;
        for (i = 0; i < size; i++) {
            concatenate[i] = array[i];
        }
        for (int j = 0; j < obj.size; j++) {
            concatenate[i++] = obj.array[j];
        }
        cout << "THE CONCATENATED CHARACTER ARRAY/STRING IS:" << endl;
        for (int i=0; i<newsize; i++)
        {
		cout << concatenate[i];
	}
        delete[] concatenate;
    }

    void operator+=(Cplus_mystring obj) {
    	int newsize = size+obj.size;
        char *concatenate = new char[size + obj.size];
        int i;
        for (i = 0; i < size; i++) {
            concatenate[i] = array[i];
        }
        for (int j = 0; j < obj.size; j++) {
            concatenate[i++] = obj.array[j];
        }
        cout << "THE CONCATENATED CHARACTER ARRAY/STRING IS" << endl;
        for (int i=0; i<newsize; i++)
        {
		cout << concatenate[i];
	}
        delete[] concatenate;
    }

    void operator==(Cplus_mystring obj) {
        bool check = true;
        if (size != obj.size) {
            check = false;
        } else {
            for (int i = 0; i < size; i++) {
                if (array[i] != obj.array[i]) {
                    check = false;
                    break; // No need to continue checking once a mismatch is found
                }
            }
        }

        if (check) {
            cout << "THE CHAR ARRAYS ARE EQUAL" << endl;
        } else {
            cout << "THE CHAR ARRAYS ARE NOT EQUAL" << endl;
        }
    }

    void operator!=(Cplus_mystring obj) {
        bool check = false;
        if (size != obj.size) {
            check = true;
        } else {
            for (int i = 0; i < size; i++) {
                if (array[i] != obj.array[i]) {
                    check = true;
                    break; // No need to continue checking once a mismatch is found
                }
            }
        }

        if (check) {
            cout << "THE CHAR ARRAYS ARE NOT EQUAL" << endl;
        } else {
            cout << "THE CHAR ARRAYS ARE EQUAL" << endl;
        }
    }

    void operator>(Cplus_mystring obj) {
        if(size > obj.size) {
            cout << "THE FIRST CHAR ARRAY IS GREATER THAN THE SECOND ARRAY" << endl;
        } else {
            cout << "THE FIRST CHAR ARRAY IS NOT GREATER THAN THE SECOND ARRAY" << endl;
        }
    }

    void operator<(Cplus_mystring obj) {
        if(size < obj.size) {
            cout << "THE FIRST CHAR ARRAY IS LESS THAN THE SECOND ARRAY" << endl;
        } else {
            cout << "THE FIRST CHAR ARRAY IS NOT LESS THAN THE SECOND ARRAY" << endl;
        }
    }

    // Overload subscript operator for getting and setting individual characters
    char& operator[](int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of bounds" << endl;
            exit(1); // Exit the program if index is out of bounds
        }
        return array[index];
    }

    // Const version of subscript operator for use with const objects
    const char& operator[](int index) const {
        if (index < 0 || index >= size) {
            cerr << "Index out of bounds" << endl;
            exit(1); // Exit the program if index is out of bounds
        }
        return array[index];
    }

    // Assignment operator
    void operator=(const Cplus_mystring &obj) {
        delete[] array; // Delete old data
        size = obj.size;
        array = new char[size + 1]; // +1 for null terminator
        strcpy(array, obj.array);
        cout << "ASSIGNMENT COMPLETE" << endl;
    }
  // Shift left operator
    Cplus_mystring operator<<(int shift) {
        if (shift >= size || shift < 0) {
            // Handle invalid shift
            return Cplus_mystring(""); // Return an empty string
        }

        char* removedChars = new char[shift + 1]; // +1 for null terminator
        strncpy(removedChars, array, shift); // Copy the removed characters
        removedChars[shift] = '\0'; // Null-terminate the removed characters

        // Shift characters to the left by 'shift' positions
        for (int i = shift; i <= size; ++i) {
            array[i - shift] = array[i];
        }

        // Update the size of the array
        size -= shift;

        Cplus_mystring removedString(removedChars);
        delete[] removedChars;
        return removedString;
    }

    // Shift right operator
    Cplus_mystring operator>>(int shift) {
        if (shift >= size || shift < 0) {
            // Handle invalid shift
            return Cplus_mystring(""); // Return an empty string
        }

        char* removedChars = new char[shift + 1]; // +1 for null terminator
        strncpy(removedChars, array + size - shift, shift); // Copy the removed characters
        removedChars[shift] = '\0'; // Null-terminate the removed characters

        // Shift characters to the right by 'shift' positions
        for (int i = size - shift - 1; i >= 0; --i) {
            array[i + shift] = array[i];
        }

        // Copy the removed characters to the beginning of the array
        strncpy(array, removedChars, shift);

        Cplus_mystring removedString(removedChars);
        delete[] removedChars;
        return removedString;
    }
    void display() {
        for (int i = 0; i < size; i++) {
        	if(array[i]!='\0')
            cout << array[i];
        }
        cout << endl;
    }

Cplus_mystring operator()(int lower_index, int upper_index) const {
    if (lower_index < 0 || lower_index >= size || upper_index < 0 || upper_index >= size || lower_index > upper_index) {
        cerr << "Invalid lower or upper index" << endl;
        exit(1);
    }

    int sub_length = upper_index - lower_index + 1;
    char *subArray = new char[sub_length + 1]; // +1 for null terminator
    strncpy(subArray, array + lower_index, sub_length);
    subArray[sub_length] = '\0';

    Cplus_mystring subString(subArray);
    delete[] subArray;
    return subString;
}


    friend ostream &operator<<(ostream &output, const Cplus_mystring &obj); // Friend declaration for output operator
    friend istream &operator>>(istream &input, Cplus_mystring &obj); // Friend declaration for input operator

    ~Cplus_mystring() {
        delete[] array;
    }

};

// Definition of output operator
ostream &operator<<(ostream &output, const Cplus_mystring &obj) {
    for (int i = 0; i < obj.size; i++) {
        output<<obj.array[i];
    }
    return output;
}


// Definition of input operator
istream &operator>>(istream &input, Cplus_mystring &obj) {
    cout << "Enter characters for the array: "<<endl;
    cout << endl;
    for (int i = 0; i < obj.size; i++) {
    	cout<<"ENTER THE CHARACTER YOU WANT TO REPLACE AT POSTITION: "<< i+1 << " USING INSERTION OPERATOR"<<endl;
        input >> obj.array[i];
    }
    return input;
}


int main() {
    int choice;
    cout << "SELECT THE NUMBER OF ARRAYS FOR OPERATOR OVERLOADING" << endl;
    cout << "1. TWO ARRAYS OPERATOR OVERLOADING DEMONSTRATION." << endl;
    cout << "2. ONE ARRAY OPERATOR OVERLOADING DEMONSTRATION." << endl;
    cin >> choice;

    if (choice == 1) {
		int choice;
		int main_size;
		Cplus_mystring obj; 
	cout << "ENTER THE DETAILS FOR THE FIRST CHARACTER ARRAY/STRING" << endl;
    cout << "=======================================================" << endl;
    cout << "ENTER THE SIZE OF THE FIRST ARRAY" << endl;
    cin >> main_size;
    Cplus_mystring obj1(main_size);
    cout << "ENTER THE CHARACTERS/NUMBERS OF YOUR ARRAY:" << endl;
    char main_input[100]; // Assuming max size is 100
    for (int i = 0; i < main_size; i++) {
        cout << "ENTER THE INPUT FOR POSITION: " << i + 1 << endl;
        cin >> main_input[i];
    }
    main_input[main_size] = '\0'; // Null-terminate the input
    Cplus_mystring obj1_string(main_input);
    system("cls");
    Cplus_mystring obj3;
    cout << "ENTERING THE DETAILS OF THE SECOND CHARACTER ARRAY/STRING" << endl;
    cout << "=======================================================" << endl;
    cout << "ENTER THE SIZE OF THE SECOND ARRAY" << endl;
    int main_size2;
    cin >> main_size2;
    Cplus_mystring obj2(main_size2);
    cout << "ENTER THE CHARACTERS/NUMBERS OF YOUR ARRAY" << endl;
    char main_input2[100]; // Assuming max size is 100
    for (int i = 0; i < main_size2; i++) {
        cout << "ENTER THE INPUT FOR POSITION " << i + 1 << endl;
        cin >> main_input2[i];
    }
    main_input2[main_size2] = '\0'; // Null-terminate the input
    Cplus_mystring obj2_string(main_input2);
    cout << endl;
    system("cls");
    
    
	 cout << "SELECT THE OPTION OF MANIPULATION YOU WANT TO PERFORM WITH YOUR STRINGS" << endl;	
	 cout << endl;
	 cout << "1. STRING/ CHARACTER ARRAY CONCATENATION BY + OPERATOR" << endl;
     cout << "2. STRING/ CHARACTER ARRAY CONCATENATION BY += OPERATOR" << endl;
     cout << "3. TESTING EQUALITY OF TWO CHAR ARRAYS BY == OPERATOR" << endl;
     cout << "4. TESTING IN-EQUALITY OF TWO CHAR ARRAYS BY != OPERATOR" << endl;
     cout << "5. COMPARE TWO CHAR ARRAYS BY > OPERATOR" << endl;
     cout << "6. COMPARE TWO CHAR ARRAYS BY < OPERATOR" << endl;
	 cout << "7. ASSIGNING ONE ARRAY TO ANOTHER BY = OPERATOR" <<endl;	
	cin >> choice;
    
    switch (choice) {
        case 1:
            obj1_string + obj2_string;
            break;
        case 2:
            obj1_string += obj2_string;
            break;
        case 3:
            obj1_string == obj2_string;
            break;
        case 4:
            obj1_string != obj2_string;
            break;
        case 5:
            obj1_string > obj2_string;
            break;
        case 6:
            obj1_string < obj2_string;
            break;
        case 7:
        	cout<<"WHICH ARRAY DO YOU WANT TO ASSIGN THE OTHER"<<endl;
        	cout<<"1. 1ST ARRAY TO THE SECOND"<<endl;
        	cout<<"2. 2ND ARRAY TO THE FIRST "<<endl;
        	cin>>choice;
        	if(choice ==1)
        	{
        		obj1_string=obj2_string;
        		cout<<"THE 1ST ARRAY IS NOW:"<<endl;
        		cout<<endl;
				obj1_string.display();
			}
			else if(choice ==2)
			{
				obj2_string=obj1_string;
				cout<<"THE 2ND ARRAY IS NOW:"<<endl;
        		cout<<endl;
				obj2_string.display();
				
			}
			else
			{
				cout<<"INVALID INPUT"<<endl;
			}
			break;
		default:
            cout << "Invalid choice" << endl;
            break;
	}
} else if (choice == 2) {
        Cplus_mystring obj;
        int main_size;
        cout << "ENTER THE DETAILS FOR THE CHARACTER ARRAY/STRING" << endl;
        cout << "==================================================" << endl;
        cout << "ENTER THE SIZE OF THE ARRAY" << endl;
        cin >> main_size;

        // Validate input
        if (main_size <= 0) {
            cout << "Invalid size. Please enter a positive integer." << endl;
            return 1;
        }

        Cplus_mystring obj1(main_size);

        cout << "ENTER THE CHARACTERS/NUMBERS OF YOUR ARRAY:" << endl;
        char main_input[100]; // Assuming max size is 100
        for (int i = 0; i < main_size; i++) {
            cout << "ENTER THE INPUT FOR POSITION: " << i + 1 << endl;
            cin >> main_input[i];
        }
        main_input[main_size] = '\0'; // Null-terminate the input
        Cplus_mystring obj1_string(main_input);
system("cls");
        // Menu for options
        cout << "SELECT THE OPTION OF MANIPULATION YOU WANT TO PERFORM WITH YOUR STRING" << endl;
        cout << "1. GETTING A SUBSTRING BY () OPERATOR" << endl;
        cout << "2. GET OUTPUT OF YOUR ARRAY BY << OPERATOR" << endl;
        cout << "3. INPUT INTO THE ARRAY USING >> OPERATOR" << endl;
        cout << "4. GET/SET INDIVIDUAL CHARACTER USING [] OPERATOR" << endl;
        cout << "5. DEMONSTRATE LEFT SHIFT USING << OPERATOR" << endl;
        cout << "6. DEMONSTRATE RIGHT SHIFT USING >> OPERATOR" << endl;
        cin >> choice;

             	int lower_index, upper_index;
                int index;
                int shift;
        switch (choice) {
              case 1: {
                cout << "ENTER THE LOWER INDEX OF YOUR SUBSTRING: ";
                cin >> lower_index;
                cout << "ENTER THE UPPER INDEX OF YOUR SUBSTRING: ";
                cin >> upper_index;
                Cplus_mystring subString = obj1_string(lower_index, upper_index);
                cout << "SUBSTRING: " << subString << endl;
                break;
            } 
            case 2:
                cout << "ARRAY CONTENTS: ";
				cout << obj1_string;
                break;
            case 3:
                cout << "ENTER NEW ARRAY CONTENTS:" << endl;
                cin >> obj1_string;
                cout << "THE UPDATED ARRAY IS: " << obj1_string;
                break;
            case 4: {
                cout << "ENTER THE INDEX YOU WANT TO ACCESS: ";
                cin >> index;
                if (index >= 0 && index < obj1.return_size()) {
                    cout << "ARRAY[" << index << "]: " << obj1_string[index] << endl;
                } else {
                    cout << "Invalid index" << endl;
                }
                break;
            }
            case 5: {
                
                cout << "ENTER THE NUMBER OF POSITIONS TO SHIFT LEFT: ";
                cin >> shift;
                Cplus_mystring shifted = obj1_string << shift;
                cout << "SHIFTED ARRAY: " << shifted << endl;
				break;
				}
            case 6: {
                shift=0;
                cout << "ENTER THE NUMBER OF POSITIONS TO SHIFT RIGHT: ";
                cin >> shift;
                Cplus_mystring shifted = obj1_string >> shift;
                cout << "SHIFTED ARRAY: " << shifted << endl;
                break;
            }
            default:
                cout << "Invalid choice" << endl;
                break;  
        }
    } else {
        cout << "INVALID CHOICE" << endl;
    }

    return 0;
}