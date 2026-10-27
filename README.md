# 🏦 Bank Management System (C++ OOP)

A console-based Bank Management System built in **C++** demonstrating core **Object-Oriented Programming (OOP)** principles. The system provides an interactive role-based menu for Customers, Employees, and the Bank Manager.

---

## ✨ Features

### 👤 Customer Portal
* **Create Account:** Register new customers with ID, Name, Age, Address, and Initial Balance.
* **Deposit & Withdraw:** Perform secure transactions with balance and positive-amount validation.
* **Balance Inquiry:** Check current account balance at any time.
* **Loan System:** Request new loans and track total loan balance.

### 💼 Employee Portal
* **Department Assignment:** Assign employees across 11 specialized bank departments (Customer Service, Credit, Risk Management, IT, HR, etc.).
* **Customer Assistance:** Simulate active customer support operations.

### 📊 Manager Portal
* **Add Employees:** Register new staff members with salary and department details.
* **Remove Employees:** Delete existing employees from the system using their ID.
* **Generate Reports:** Display a complete report of all registered bank employees.

---

## 🛠️ OOP & C++ Concepts Applied

* **Inheritance (Hierarchical & Multilevel):**
  * `Customer` and `Employee` inherit from the base class `Person`.
  * `Manager` inherits from `Employee` (`Person` ➔ `Employee` ➔ `Manager`).
* **Encapsulation & Data Hiding:** All class attributes are kept `private` and accessed via `public` getters, setters, and methods.
* **Composition (Has-A Relationship):** The `Bank` class manages a `Manager` object and a dynamic list of `Customer` objects.
* **STL Vectors (`std::vector`):** Used for dynamic storage and management of customers and employees.
* **Input Validation:** Implemented using `do-while` loops to prevent negative IDs, ages, salaries, or invalid transactions.
