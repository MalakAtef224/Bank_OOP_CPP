# Bank Management System - OOP (C++)

A console-based bank management system written in C++ that models a bank with object-oriented design.

## Features
- Customer role: deposit, withdraw, check balance, request a loan, check loan
- Employee role: choose a department (11 departments) and assist customers
- Manager role: add employees, remove employees, generate an employee report
- Input validation for IDs, ages, salaries and balances

## OOP Concepts Used
- Inheritance: `Person` -> `Customer`, `Person` -> `Employee` -> `Manager`
- Encapsulation: private data members with public methods
- Composition: `Bank` holds a list of customers and a manager

## Technologies
- C++, STL `vector`

## How to Run
1. Download `main.cpp`
2. Compile: `g++ main.cpp -o bank_oop`
3. Run: `bank_oop` (Windows) or `./bank_oop` (Linux/Mac)

## Limitations
- Data is stored in memory only and is lost when the program exits
- No authentication for customers, employees or the manager
- Non-numeric input in some prompts is not handled
- Customer IDs are not checked for uniqueness

## Future Improvements
- Add login with passwords
- Save data to files or a database
- Add polymorphism (e.g. a virtual `display()` for each role)
