## OOP_Cpp
This repository documents my journey and practice with Object-Oriented Programming (OOP) concepts during my university semester. It contains C++ code examples illustrating various OOP principles such as classes, inheritance, polymorphism, encapsulation, and more. Explore to see my progress and understanding of OOP in action!
Details of the code files present in this repository are given below:
<br>
<br>

# 1. Basic Concepts:
This C++ code showcase basic concepts of opp programming in cpp, demonstrating the use of various data-types, types of constructors, private and public data members/member functions. Furthermore, elaborating the method of using such data members/ member functions in main while preserving the concept of data encapsulation.

# 2. Aggregation of Classes:
This C++ code exemplifies Object-Oriented Programming (OOP) principles such as encapsulation and aggregation. The `book` class encapsulates data members (title, name, author, genre) and member functions (add_book_details(), display_book_details()) to manage book details efficiently. In contrast, the `library` class aggregates instances of the `book` class to represent a collection of books. Dynamic memory allocation is employed in the `library` class to allocate memory for the array of books using the `new` keyword in the constructor and deallocate it using `delete[]` in the destructor, ensuring effective memory management. The main() function utilizes a do-while loop to repeatedly prompt the user to add more books to the library, enhancing user interaction and allowing for the dynamic expansion of the library collection.

# 3. Operator Overloading:
This C++ code demonstrates the implementation of operator overloading in the `Cplus_mystring` class. The class encapsulates a character array along with its size and provides overloaded operators for concatenation (`+` and `+=`), comparison (`==`, `!=`, `>`, `<`), subscript access (`[]`), insertion (`>>`), extraction (`<<`), substring extraction (`()`), assignment (`=`), and shifting (`<<`, `>>`). It offers flexibility in manipulating character arrays or strings, allowing concatenation, comparison, extraction, insertion, and shifting operations. The main function provides a menu-driven interface to interact with the overloaded operators and demonstrates their functionalities based on user choices.
