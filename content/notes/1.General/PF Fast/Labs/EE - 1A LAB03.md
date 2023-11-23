---
title: EE - 1A LAB03
description: This the 3rd lab assignment for EE 1A Fast Karachi
date: 2023-09-07
tags:
  - pf
  - uni
  - fundamental
  - cpp
---

## Task 1
Generate the following output
![](notes/1.General/PF%20Fast/Labs/attachments/Pasted%20image%2020230907143228.png)
For help: Unit price of T-shirt is Rs.500, Formal Shirt is Rs.1000 and Wrist Watch is Rs.500

```cpp
#include <iomanip>
using namespace std;

int main(){
	cout << setw(80) << "SHOP OVER RS. 3000 AND ENJOY 10% DISCOUNT" << endl;
	cout << endl;

	int purchased, tShirts, shirts, wristWatch, provided;
	
	cout << "Enter the total number of items purchased by customer: ";
	cin>> purchased;
	
	cout << "Number of T-Shirts bought: ";
	cin >> tShirts;
	
	cout << "Number of Shirts bought: ";
	cin >> shirts;
	
	cout << "Number of Wrist Watches bought: ";
	cin >> wristWatch;
	
	int total = tShirts * 500 + shirts * 1000 + wristWatch * 500;
	cout << "Total amount: " << total << endl;

	cout << "Customer provided: Rs.";
	cin >> provided;
	
	if (total >= 3000){
		cout << endl <<  "Congratulations! You have purchased items of over RS. 3000, Enjoy the 10% discount on total." << endl;
		total = total - total*0.1;
	};
	
	cout << endl;
	
	
	cout << "Amount returned customer: Rs." << (provided - total);
	return 0;
}
```

## Task 2
Based on user input, check whether the given character is an alphabet, digit or special character.

```cpp
int main(){
	char x;
	cout << "Input your shit: "; 
	cin >> x;
	int code = x;
	cout << code << endl;
	
	// 48 to 57 is a integer 
	if (48 <= x  && x <= 57){
		cout << "Integer" << endl;
	// 65 to 90 OR 97 to 122 is an Alphabet
	} else if(65 <= x && x <= 90 || 97 <= x && x <= 122){
		cout << "Alphabet" << endl;
	} else {cout << "Symbol";}
	// 32–47 / 58–64 / 91–96 / 123–126 123 to 255 symbols
	return 0;
}
```

## Task 3
Using Control statements, write a program that displays the following menu for the food items available to take order from the customer:
• Burger (Rs. 150)
• French Fries (Rs. 100)
• Pizza (Rs. 350)
• Sandwiches (Rs. 200)
The program first asks the user to enter their choice i.e., “1” for Burger and then for quantity. The program should finally display the total charges for the order.

```cpp
#include <iomanip>

int main(){
	
	int s, q, price;
	
	cout << setw(25) << "****** MENU ******" << endl;
	cout << "Enter your choice" << endl;
	cout <<"1.Burger"       << setw(24) << "Rs.150" << endl;
	cout <<"2.French Fries" << setw(18) << "Rs.100" << endl;
	cout <<"3.Pizza"        << setw(25) << "Rs.350" << endl;
	cout <<"4.Sandwiches"   << setw(20) << "Rs.200" << endl;
	cout << "Please select your choice from 1,2,3,4"<< endl;
	cin  >> s;
	switch(s){
		case 1:
			cout << "You selected Burger." << endl;
			price = 150;
			break;
		case 2:
			cout << "You selected French Fries." << endl;
			price = 100;
			break;
		case 3:
			cout << "You selected Pizza." << endl;
			price = 350;
			break;
		case 4:
			cout << "You selected Sandwiches." << endl;
			price = 200;
			break;
	};
	cout << "Please select quantity: ";
	cin >> q;
	cout << "Your bill is Rs." << q*price << endl;
	
	return 0;
}
```

## Task 4
Using Switch Operator, Create the equivalent of a four-function calculator. The program should request the user to make decision for arithmetic function to execute & ask two numbers from it. (Use floating point.) It should then carry out the specified arithmetical operation: adding, subtracting, multiplying, or dividing the two numbers. Use a switch statement to select the operation. Finally, Display the result.
Enter Arithmetic Calculation:
1. Addition 2. Subtraction 3. Multiplication 4. *Division*

```cpp
#include <iomanip>

int main(){
	
	float n1, n2, result;
	int s;
	
		cout << "Enter your choice" << endl;
	cout <<"1.Addition"        << setw(21) << "Rs.150" << endl;
	cout <<"2.Subtraction"     << setw(18) << "Rs.100" << endl;
	cout <<"3.Multiplication"  << setw(15) << "Rs.350" << endl;
	cout <<"4.Division"        << setw(21) << "Rs.200" << endl;
	
	cout << "Please select your operation"<< endl;
	cin  >> s;
	cout << "Enter num1: ";
	cin >> n1;
	cout << "Enter num2: ";
	cin >> n2;
	cout << endl;
	
	switch(s){
		case 1:
			cout << "Addition" << endl;
			result = n1+n2;
			break;
		case 2:
			cout << "Subtraction" << endl;
			result = n1-n2;
			break;
		case 3:
			cout << "Multiplication" << endl;
			result = n1*n2;
			break;
		case 4:
			cout << "Division" << endl;
			result = n1/n2;
			break;
	};
	
	cout << result;
	
	return 0;
}
```