## OOP_Cpp
This repository documents my journey and practice with Object-Oriented Programming (OOP) concepts during my university semester. It contains C++ code examples illustrating various OOP principles such as classes, inheritance, polymorphism, encapsulation, and more. Explore to see my progress and understanding of OOP in action!
Details of the code files present in this repository are given below:
<br>
<br>

# 1. Basic Concepts:
This C++ code showcase basic concepts of Object-Oriented Programming (OOP) programming in cpp, demonstrating the use of various data-types, types of constructors, private and public data members/member functions. Furthermore, elaborating the method of using such data members/ member functions in main while preserving the concept of data encapsulation.

# 2. Aggregation of Classes:
This C++ code exemplifies Object-Oriented Programming (OOP) principles such as encapsulation and aggregation. The `book` class encapsulates data members (title, name, author, genre) and member functions (add_book_details(), display_book_details()) to manage book details efficiently. In contrast, the `library` class aggregates instances of the `book` class to represent a collection of books. Dynamic memory allocation is employed in the `library` class to allocate memory for the array of books using the `new` keyword in the constructor and deallocate it using `delete[]` in the destructor, ensuring effective memory management. The main() function utilizes a do-while loop to repeatedly prompt the user to add more books to the library, enhancing user interaction and allowing for the dynamic expansion of the library collection.

# 3. Operator Overloading:
This C++ code demonstrates the implementation of operator overloading in the `Cplus_mystring` class. The class encapsulates a character array along with its size and provides overloaded operators for concatenation (`+` and `+=`), comparison (`==`, `!=`, `>`, `<`), subscript access (`[]`), insertion (`>>`), extraction (`<<`), substring extraction (`()`), assignment (`=`), and shifting (`<<`, `>>`). It offers flexibility in manipulating character arrays or strings, allowing concatenation, comparison, extraction, insertion, and shifting operations. The main function provides a menu-driven interface to interact with the overloaded operators and demonstrates their functionalities based on user choices.

# 4. This Pointer:
This C++ code implements a product management system using object-oriented programming concepts like inheritance and polymorphism. It defines base and derived classes for different product types, each with attributes and methods for input and display. The `this` pointer is used in the `setDetails` method of the base `product` class to refer to the calling object, allowing the method to set the object's attributes directly. The `system("cls")` function is used to clear the console screen, and `cin` and `getline` are used for user input. The main function features a loop with a switch statement to handle user choices and repeatedly gather product details until the user chooses to exit.

# 5. Inheritance and Function Overloading:
This C++ code demonstrates an order management system for a restaurant using object-oriented programming concepts such as abstraction, inheritance, and polymorphism. The `FoodItems` class serves as an abstract base class with pure virtual functions `makePayments()` and `placeOrder()`, ensuring that derived classes like `Pizza`, `Sushi`, and `Tacos` implement these methods. The `this` pointer is used in the `FoodItems` constructor to correctly initialize member variables. The `system("cls")` function is used to clear the console screen. The main function provides a user interface for placing orders, invoking the respective methods for each food item, and allows repeated order placement until the user decides to exit.

# 6. Virtual Inheritance:
This C++ code is an employee management system that uses object-oriented programming concepts such as inheritance and polymorphism. It defines a base class `employee` and derived classes `engineer`, `manager`, and `techled` to represent different types of employees with specific roles. Virtual inheritance is employed to avoid the diamond problem when `techled` inherits from both `engineer` and `manager`, which both inherit from `employee`. The `main` function provides a user interface to create instances of these classes, allowing the user to input employee details and display them, demonstrating the use of both base and derived class methods.
