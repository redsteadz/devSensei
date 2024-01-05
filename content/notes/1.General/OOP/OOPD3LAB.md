---
title: OOPD3LAB
date: 2024-01-05
tags:
  - karachi
  - OOP
---
## QUESTION#1
Create a class Rectangle with attributes length and width, each of which defaults to 1. Provide member functions that
calculate the perimeter and the area of the rectangle. Also, provide set and get functions for the length and width
attributes. The set functions should verify that length and width are each floating-point numbers larger than 0.0 and less
than 20.0.

```cpp
class Rectangle {
  float length = 1.0;
  float width = 1.0;
  float area = 1.0;
  float perimeter = 1.0;
  
  void updateArea(){
    area = length * width;
  }

  void updatePerimeter(){
    perimeter = 2 * (length + width);
  }

  void setLength(){
    cin >> length;
    while (length > 0.0 && length < 20 ){
      cout << "Invalid input. Please enter a number between 0 and 20." << endl;
      cin >> length;
    }

    updateArea();
    updatePerimeter();
  }
  void setWidth(){
    cin >> width;
    while (width > 0.0 && width < 20 ){
      cout << "Invalid input. Please enter a number between 0 and 20." << endl;
      cin >> width;
    }
    updateArea();
    updatePerimeter();
  }
  void getLength(){
    cout << length;
  }
  void getWidth(){
    cout << width;
  }
};

```


## QUESTION#2
Create a class called Employee that includes three pieces of information as data members—a first name (type char*), a
last name (type string) and a monthly salary (type int). Your class should have a setter function that initializes the three
data members. Provide a getter function for each data member. If the monthly salary is not positive, set it to 0.Write a
test program that demonstrates class Employee’s capabilities. Create two Employee objects and display each object’s
yearly salary. Then give each Employee a 10 percent raise and display each Employee’s yearly salary again. Identify and
add any other related functions to achieve the said goal.

Extend the Employee class by incorporating the following features:

- Implement a static data member to keep track of the total number of employees created.
- Create a member function to calculate and return the yearly salary for each employee based on the monthly salary.
- Introduce an array or vector to store additional information about each employee, such as their department or job title.
- Implement a function to display all the information about each employee, including the newly added details.
- Include error handling mechanisms for the setter function to validate and handle invalid input for the monthly salary, ensuring it remains non-negative.
- Add a feature to compare two employees based on their yearly salary and display the employee with the higher salary.

```cpp
class Employee{
  private:
    int static memberCount;
  public:
  float monthlySalary;
  char* fname;
  string lname;
  string details[2];

  Employee(){
    memberCount++;
  }

  void setData(){
    cout<<"Enter First Name: ";
    cin>>fname;
    cout<<"Enter Last Name: ";
    cin>>lname;
    cout<<"Enter Monthly Salary: ";
    cin>>monthlySalary;
    if (monthlySalary < 0){
      monthlySalary = 0;
    }
    
    cout<<"Enter Department and Job Title: ";
    cin>>details[0]>>details[1];
  }
  
  void getData(){
    cout<<"Name: "<<fname<<" "<<lname<<endl;
    cout<<"Monthly Salary: "<<monthlySalary<<endl;
    std::cout << "Total Members " << memberCount << std::endl;
  }
  
  void salaryInYear(){
    cout<<"Yearly Salary: "<<monthlySalary*12<<endl;
  }
  
  void compareSalary(Employee e){
    if (monthlySalary > e.monthlySalary){
      cout<<fname<<" "<<lname<<" has higher salary than "<<e.fname<<" "<<e.lname<<endl;
    } else if (monthlySalary < e.monthlySalary){
      cout<<e.fname<<" "<<e.lname<<" has higher salary than "<<fname<<" "<<lname<<endl;
    } else {
      cout<<"Both have same salary"<<endl;
    }
  }

};

int Employee::memberCount = 0;

```

## QUESTION#3
Create a class called Invoice that a hardware store might use to represent an invoice for an item sold at the store. An
Invoice should include four data members—a part number (type string), a part description (type string), a quantity of the
item being purchased (type int) and a price per item (type float). Your class should have a functions that initializes the four
data members. Provide a get function for each data member. In addition, provide a member function named
getInvoiceAmount that calculates the invoice amount (i.e., multiplies the quantity by the price per item), then returns the
amount as a float value. If the quantity is not positive, it should be set to 0. If the price per item is not positive, it should
be set to 0. Write a test program that demonstrates class Invoice’s capabilities.


BRUH 

## QUESTION#4
Write C++ code to represent a hitting game. The details are as follows:
This game is being played between two teams (i.e. your team and the enemy team).
The total number of players in your team is randomly generated and stored accordingly.
The function generates a pair of numbers and matches each pair. If the numbers get matched, the following message is
displayed:
“Enemy got hit by your team!”
Otherwise, the following message is displayed:
“You got hit by the enemy team!”
The number of hits should be equal to the number of players in your team.
The program should tell the final result of your team by counting the hits of both the teams.
Consider the following sample output:
BRUH 2

## QUESTION#5
![[notes/1.General/OOP/attachments/Pasted image 20240105202426.png]]

```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Cart{
  public:
  int quantity;
  float priceOfBag = 5.5;
  void setQuantity(int q){
    quantity = q;
  }
};

class Bill{
  private:
    int lBoxCap = 20;
    float lBoxCost = 1.8;
    int mBoxCap = 10;
    float mBoxCost = 1.0;
    int sBoxCap = 5;
    float sBoxCost = 0.6;
    float totalCost = 0;
  public:
    void calculateBill(Cart c){
      int quantity = c.quantity;
      if (quantity >= lBoxCap){
       std::cout << quantity/lBoxCap << "Large Boxes: " << (int)(quantity/lBoxCap)*lBoxCost << std::endl;
       totalCost += (int)(quantity/lBoxCap)*lBoxCost;
       quantity = quantity % lBoxCap;
      }
      if (quantity >= mBoxCap){
       std::cout << quantity/mBoxCap << "Medium Boxes: " << (int)(quantity/mBoxCap)*mBoxCost << std::endl;
       totalCost += (int)(quantity/mBoxCap)*mBoxCost;
       quantity = quantity % mBoxCap;
       // cout << quantity << endl;
      }
      if (quantity >= 0){
        int sBox = ceil((float) quantity/sBoxCap);
       std::cout << sBox << "Small Boxes: " << sBox*sBoxCost << std::endl;
       totalCost += sBox*sBoxCost;
      }

      cout << "Total Cost: " << totalCost + c.quantity*c.priceOfBag << endl;

    }
};

int main (int argc, char *argv[]) {
  Bill b;
  Cart c;
    c.quantity = 52;
  std::cout << "The Cost of Order: " << c.quantity * c.priceOfBag << std::endl;
  b.calculateBill(c);

  return 0;
}

```