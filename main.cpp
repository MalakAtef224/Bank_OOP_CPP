#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ========== Colors ==========
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

// ================== Person ==================
class Person {
private:
    int personId;
    string personName;
    int personAge;
    string personAddress;

public:
    Person();
    Person(int id, string name, int age, string address);
    void display();
    int getId();
    string getName();
    void setInfo();
};

Person::Person() : personId(0), personName(""), personAge(0), personAddress("") {}
Person::Person(int id, string name, int age, string address)
    : personId(id), personName(name), personAge(age), personAddress(address) {
}

void Person::display() {
    cout << "ID: " << personId << endl;
    cout << "Name: " << personName << endl;
    cout << "Age: " << personAge << endl;
    cout << "Address: " << personAddress << endl;
}

int Person::getId() { return personId; }
string Person::getName() { return personName; }

void Person::setInfo() {
    do {
        cout << "Enter ID (positive number): ";
        cin >> personId;
        if (personId <= 0) cout << RED << "ID must be positive!\n" << RESET;
    } while (personId <= 0);

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, personName);

    do {
        cout << "Enter Age (positive number): ";
        cin >> personAge;
        if (personAge <= 0) cout << RED << "Age must be positive!\n" << RESET;
    } while (personAge <= 0);

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, personAddress);
}

// ================== Customer ==================
class Customer : public Person {
private:
    double accountBalance;
    double loanBalance;

public:
    Customer();
    Customer(int id, string name, int age, string address, double balance);
    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();
    void requestLoan(double amount);
    void checkLoan();
};

Customer::Customer() : accountBalance(0.0), loanBalance(0.0) {}
Customer::Customer(int id, string name, int age, string address, double balance)
    : Person(id, name, age, address), accountBalance(balance), loanBalance(0.0) {
}

void Customer::deposit(double amount) {
    if (amount > 0) {
        accountBalance += amount;
        cout << GREEN << "Deposited: " << amount << " successfully.\n" << RESET;
    }
    else cout << RED << "Deposit must be positive!\n" << RESET;
}

void Customer::withdraw(double amount) {
    if (amount <= 0) cout << RED << "Withdraw amount must be positive!\n" << RESET;
    else if (amount > accountBalance) cout << RED << "Insufficient balance.\n" << RESET;
    else {
        accountBalance -= amount;
        cout << GREEN << "Withdrew: " << amount << " successfully.\n" << RESET;
    }
}

void Customer::checkBalance() { cout << BLUE << "Current Balance: " << accountBalance << RESET << endl; }
void Customer::requestLoan(double amount) {
    if (amount > 0) {
        loanBalance += amount;
        cout << GREEN << "Loan of " << amount << " approved.\n" << RESET;
    }
    else cout << RED << "Loan amount must be positive!\n" << RESET;
}
void Customer::checkLoan() { cout << BLUE << "Total Loan: " << loanBalance << RESET << endl; }

// ================== Employee ==================
class Employee : public Person {
private:
    double employeeSalary;
    string employeeDepartment;

public:
    Employee();
    Employee(int id, string name, int age, string address, double salary, string department);
    void assistCustomer();
    void setEmployeeInfo();
};

Employee::Employee() : employeeSalary(0), employeeDepartment("") {}
Employee::Employee(int id, string name, int age, string address, double salary, string department)
    : Person(id, name, age, address), employeeSalary(salary), employeeDepartment(department) {
}

void Employee::assistCustomer() { cout << GREEN << getName() << " is assisting a customer now.\n" << RESET; }

void Employee::setEmployeeInfo() {
    setInfo();
    do {
        cout << "Enter Salary (>=0): ";
        cin >> employeeSalary;
        if (employeeSalary < 0) cout << RED << "Salary cannot be negative!\n" << RESET;
    } while (employeeSalary < 0);
    //--------Choice department--------
    int Choice;
    do {
        cout << "\nChoose Department:\n";
        cout << "1. Customer Service\n";
        cout << "2. Credit Department\n";
        cout << "3. Operations Department\n";
        cout << "4. Risk Management\n";
        cout << "5. Treasury Department\n";
        cout << "6. Finance & Accounting\n";
        cout << "7. Marketing & Sales\n";
        cout << "8. HR Department\n";
        cout << "9. IT Department\n";
        cout << "10. Compliance & Legal\n";
        cout << "11. Internal Audit\n";
        cout << "Enter choice: ";
        cin >> Choice;

        switch (Choice) {
        case 1: employeeDepartment = "Customer Service"; break;
        case 2: employeeDepartment = "Credit Department"; break;
        case 3: employeeDepartment = "Operations Department"; break;
        case 4: employeeDepartment = "Risk Management"; break;
        case 5: employeeDepartment = "Treasury Department"; break;
        case 6: employeeDepartment = "Finance & Accounting"; break;
        case 7: employeeDepartment = "Marketing & Sales"; break;
        case 8: employeeDepartment = "HR Department"; break;
        case 9: employeeDepartment = "IT Department"; break;
        case 10: employeeDepartment = "Compliance & Legal"; break;
        case 11: employeeDepartment = "Internal Audit"; break;
        default:
            cout << RED << "Invalid choice! Please try again.\n" << RESET;
            Choice = -1;
        }
    } while (Choice == -1);
}

// ================== Manager ==================
class Manager : public Employee {
private:
    vector<Employee> employeeList;

public:
    Manager();
    Manager(int id, string name, int age, string address, double salary, string department);
    void addEmployee(Employee newEmployee);
    void removeEmployee(int employeeId);
    void generateReport();
};

Manager::Manager() : Employee() {}
Manager::Manager(int id, string name, int age, string address, double salary, string department)
    : Employee(id, name, age, address, salary, department) {
}

void Manager::addEmployee(Employee newEmployee) {
    employeeList.push_back(newEmployee);
    cout << GREEN << newEmployee.getName() << " added successfully.\n" << RESET;
}

void Manager::removeEmployee(int employeeId) {
    for (int i = 0; i < employeeList.size(); i++) {
        if (employeeList[i].getId() == employeeId) {
            cout << RED << employeeList[i].getName() << " removed successfully.\n" << RESET;
            swap(employeeList[i], employeeList.back());
            employeeList.pop_back();
            return;
        }
    }
    cout << RED << "Employee with ID " << employeeId << " not found.\n" << RESET;
}

void Manager::generateReport() {
    cout << "\n===== Manager Report =====\n";
    cout << "Manager: " << getName() << endl;
    if (employeeList.empty()) cout << BLUE << "No employees available you must add Employee.\nPlease try again\n" << RESET;
    else {
        for (int i = 0; i < employeeList.size(); i++) {
            employeeList[i].display();
            cout << "-----------------\n";
        }
    }
}

// ================== Bank ==================
class Bank {
private:
    vector<Customer> customerList;
    Manager bankManager;

public:
    Bank();
    void addCustomer();
    void customerMenu();
    void employeeMenu(Employee& employee);
    void managerMenu();
    void mainMenu();
};

Bank::Bank() {
    bankManager = Manager(1, "Main Manager", 45, "Bank HQ", 10000, "Management");
}

void Bank::addCustomer() {
    int id, age;
    string name, address;
    double balance;

    do {
        cout << "Enter Customer ID (positive number): ";
        cin >> id;
        if (id <= 0) cout << RED << "ID must be positive!\n" << RESET;
    } while (id <= 0);

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    do {
        cout << "Enter Age (positive number): ";
        cin >> age;
        if (age <= 0) cout << RED << "Age must be positive!\n" << RESET;
    } while (age <= 0);

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);

    do {
        cout << "Enter Initial Balance (>=0): ";
        cin >> balance;
        if (balance < 0) cout << RED << "Balance cannot be negative!\n" << RESET;
    } while (balance < 0);

    customerList.push_back(Customer(id, name, age, address, balance));
    cout << GREEN << "Customer added successfully!\n" << RESET;
}

void Bank::customerMenu() {
    if (customerList.empty()) {
        cout << RED << "No customers found you must add Customer.\nPlease try again \n" << RESET;
        return;
    }

    int customerId;
    cout << "Enter your Customer ID: ";
    cin >> customerId;

    bool found = false;
    for (int i = 0; i < customerList.size(); i++) {
        if (customerList[i].getId() == customerId) {
            found = true;
            int choice;
            do {
                cout << "\n--- Customer Menu ---\n";
                cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Request Loan\n5. Check Loan\n0. Back\n";
                cin >> choice;

                switch (choice) {
                case 1: {
                    double amount;
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    customerList[i].deposit(amount);
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter withdraw amount: ";
                    cin >> amount;
                    customerList[i].withdraw(amount);
                    break;
                }
                case 3:
                    customerList[i].checkBalance();
                    break;
                case 4: {
                    double amount;
                    cout << "Enter loan amount: ";
                    cin >> amount;
                    customerList[i].requestLoan(amount);
                    break;
                }
                case 5:
                    customerList[i].checkLoan();
                    break;
                case 0:
                    break;
                default:
                    cout << RED << "Invalid choice!\n" << RESET;
                }
            } while (choice != 0);
            break;
        }
    }
    if (!found) cout << RED << "Customer not found.\n" << RESET;
}

void Bank::employeeMenu(Employee& employee) {
    int choice;
    do {
        cout << "\n--- Employee Menu ---\n";
        cout << "1. Assist Customer\n0. Back\n";
        cin >> choice;

        switch (choice) {
        case 1:
            employee.assistCustomer();
            break;
        case 0:
            break;
        default:
            cout << RED << "Invalid choice!\n" << RESET;
        }
    } while (choice != 0);
}

void Bank::managerMenu() {
    int choice;
    do {
        cout << "\n--- Manager Menu ---\n";
        cout << "1. Add Employee\n2. Remove Employee\n3. Generate Report\n0. Back\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            Employee newEmployee;
            newEmployee.setEmployeeInfo();
            bankManager.addEmployee(newEmployee);
            break;
        }
        case 2: {
            int employeeId;
            cout << "Enter Employee ID to remove: ";
            cin >> employeeId;
            bankManager.removeEmployee(employeeId);
            break;
        }
        case 3:
            bankManager.generateReport();
            break;
        case 0:
            break;
        default:
            cout << RED << "Invalid choice!\n" << RESET;
        }
    } while (choice != 0);
}

void Bank::mainMenu() {
    int choice;
    do {
        cout << "\n=======================================\n";
        cout << GREEN << "   Welcome To Honest Thieves Bank   " << RESET << endl;
        cout << "=======================================\n";
        cout << BLUE << "Please choose your role:\n" << RESET;
        cout << "1. Customer\n2. Employee\n3. Manager\n4. Add Customer\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            customerMenu();
            break;
        case 2: {
            Employee tempEmployee;
            tempEmployee.setEmployeeInfo();
            employeeMenu(tempEmployee);
            break;
        }
        case 3:
            managerMenu();
            break;
        case 4:
            addCustomer();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << RED << "Invalid choice!\n" << RESET;
        }
    } while (choice != 0);
}

// ================== Main ==================
int main() {
    Bank bankSystem;
    bankSystem.mainMenu();
    return 0;
}
