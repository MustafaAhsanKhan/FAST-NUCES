#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
// Question 1
TEST(AddEmployee, T1) {
    EmployeeList company;

    // Add 3 employees
    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");
    Employee emp3("Charlie", "NIC789", "2021-06-20", "M", "Married", 60000, "Director", 19, "Finance");

    company.addEmployee(emp1);
    company.addEmployee(emp2);
    company.addEmployee(emp3);

    Node<Employee>* temp = company.head;
    EXPECT_EQ(temp->data.name, "Alice");
    temp = temp->next;
    EXPECT_EQ(temp->data.name, "Bob");
    temp = temp->next;
    EXPECT_EQ(temp->data.name, "Charlie");  
}
TEST(SearchEmployeeByNIC, T2) {
    EmployeeList company;

    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");

    company.addEmployee(emp1);
    company.addEmployee(emp2);

    // Search for Bob by NIC
    Employee* foundEmployee = company.searchEmployeeByNIC("NIC456");
    EXPECT_EQ(foundEmployee->name, "Bob");
    EXPECT_EQ(foundEmployee->salary, 40000);
    EXPECT_EQ(foundEmployee->department, "IT");

    // Check non-existent employee
    Employee* notFoundEmployee = company.searchEmployeeByNIC("NIC999");
    EXPECT_EQ(notFoundEmployee, nullptr);
}
TEST(SortEmployeesBySalary, T3) {
    EmployeeList company;

    // Add 3 employees with varying salaries
    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");
    Employee emp3("Charlie", "NIC789", "2021-06-20", "M", "Married", 60000, "Director", 19, "Finance");

    company.addEmployee(emp3);  // Charlie (60000)
    company.addEmployee(emp1);  // Alice (50000)
    company.addEmployee(emp2);  // Bob (40000)

    company.sortEmployeesBySalary();

    Node<Employee>* temp = company.head;
    EXPECT_EQ(temp->data.name, "Bob");
    temp = temp->next;
    EXPECT_EQ(temp->data.name, "Alice");
    temp = temp->next;
    EXPECT_EQ(temp->data.name, "Charlie");
}
TEST(ListEmployeesByDepartment, T4) {
    EmployeeList company;

    // Add employees to different departments
    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");
    Employee emp3("Charlie", "NIC789", "2021-06-20", "M", "Married", 60000, "Director", 19, "Finance");

    company.addEmployee(emp1);
    company.addEmployee(emp2);
    company.addEmployee(emp3);

    testing::internal::CaptureStdout();
    company.listEmployeesByDepartment("IT");  // Expect only Bob
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Bob"), std::string::npos);
    EXPECT_EQ(output.find("Alice"), std::string::npos);
    EXPECT_EQ(output.find("Charlie"), std::string::npos);
}
TEST(EditEmployeeRecord, T5) {
    EmployeeList company;

    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");

    company.addEmployee(emp1);
    company.addEmployee(emp2);

    // Edit Bob's record
    company.editEmployeeRecord("NIC456", "Married", 45000, "Senior Engineer", 15, "IT");

    Employee* editedEmp = company.searchEmployeeByNIC("NIC456");
    EXPECT_EQ(editedEmp->maritalStatus, "Married");
    EXPECT_EQ(editedEmp->salary, 45000);
    EXPECT_EQ(editedEmp->designation, "Senior Engineer");
    EXPECT_EQ(editedEmp->employeeScale, 15);
}
TEST(EmployeeListTest, EditEmployeeRecord) {
    EmployeeList company;

    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");

    company.addEmployee(emp1);
    company.addEmployee(emp2);

    // Edit Bob's record
    company.editEmployeeRecord("NIC456", "Married", 45000, "Senior Engineer", 15, "IT");

    Employee* editedEmp = company.searchEmployeeByNIC("NIC456");
    ASSERT_NE(editedEmp, nullptr);
    EXPECT_EQ(editedEmp->maritalStatus, "Married");
    EXPECT_EQ(editedEmp->salary, 45000);
    EXPECT_EQ(editedEmp->designation, "Senior Engineer");
    EXPECT_EQ(editedEmp->employeeScale, 15);
}
TEST(EmployeeListTest, ListEmployeesByJoiningDate) {
    EmployeeList company;

    Employee emp1("Alice", "NIC123", "2020-01-01", "F", "Married", 50000, "Manager", 17, "HR");
    Employee emp2("Bob", "NIC456", "2019-05-15", "M", "Single", 40000, "Engineer", 14, "IT");
    Employee emp3("Charlie", "NIC789", "2020-01-01", "M", "Married", 60000, "Director", 19, "Finance");

    company.addEmployee(emp1);
    company.addEmployee(emp2);
    company.addEmployee(emp3);

    testing::internal::CaptureStdout();  // Capture the output for testing

    company.listEmployeesByJoiningDate("2020-01-01");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Alice") != std::string::npos);
    EXPECT_TRUE(output.find("Charlie") != std::string::npos);
    EXPECT_FALSE(output.find("Bob") != std::string::npos);  // Bob has a different joining date
}



