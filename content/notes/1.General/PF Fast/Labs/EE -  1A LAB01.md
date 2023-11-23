---
title: "EE - 1A LAB01"
description: "This the first lab assignment for EE 1A Fast Karachi"
date: "2023-08-25"
tags: 
- fundamentals
- cpp
- pf
---

## Main func

In C++ the function

```cpp
int main(){}
```

Is the main function that is ran when executing a file, So for now. All our code will be contained within this function

As a function by definition returns something. Here we `return 0` to show that the function has supposedly ran successfully like

```cpp
int main(){
	
	return 0;
}
```

## Comments
This is an example of how you can write explainable code, by using comments.
Comments are a utility to basically write explanations, These lines are always ignored by the compiler/interpreter
For C++, The way to add a comment is by using 


```cpp
 //
```

## Input&Output
Now most programs has input or output. But C++ by itself doesn't have an easy way to do that. So we add some "libraries" These are basically a set of pre - built function that give us some convenience. For input and out, the library called is iostream (InputOutputStream)

```cpp
#include iostream
using namespace std;
```


```run-cpp
#include <iostream> 
using namespace std;
// This is a comment, it is always ignored by the compiler. This is usually used to explain the code
int main(){
	// Output this statement             // press enter
	cout << " This is run, as there is no // " << endl; 
	return 0; 
}
```

## Taking input
In order to take input cin 

```cpp
#include <iostream> 
using namespace std;
int main(){
	int x;
	cin >> x;
	cout << x << endl;
	return 0; 
}
```

> [!question]
> Write a program that takes in a number(`n`) and outputs `n*10`
> So if `10 -> 100, 3 -> 30, 14 -> 140`

#### Write a program which takes distance in kilometers and convert it into meter. (Use proper names of variables)

Let's break this problem down
- Takes distance (inputs distance)
- km -> m which means km * 1000 = m
- Output distance
The code would something like this
```cpp
#include <iostream> 
using namespace std;
int main(){
	// Just outputs this statement
	cout << "Input the distance in km" << endl;
	
	// Initializes the variable to store the value
	int dist_in_km;
	
	// Waits for input of the value of distance in km
	cin >> dist_in_km;
	
	// Makes a variable that is times 1000 of what was inputted
	int dist_in_m = dist_in_km * 1000;
	
	// Outputs that value
	cout << dist_in_m << end;
	
	// Shows the function ended properly
	return 0;
	
}
```

There are many ways you can write code, the more complex the task it. The more variety of solutions will be possible. for example you can write 

```cpp
#include <iostream> 
using namespace std;
int main(){
	// Just outputs this statement
	cout << "Input the distance in km" << endl;
	
	// Initializes the variable to store the value
	int dist_in_km;
	
	// Waits for input of the value of distance in km
	cin >> dist_in_km;
	
	// Outputs that value * 1000 directly
	cout << dist_in_km * 1000 << end;
	
	// Shows the function ended properly
	return 0;
	
}
```

This just removes the additional variable, But it is recommended to make variables with data in it. As those variables maybe used later on


#### Q. Write a program which finds the area and perimeter of a rectangle.
In a rectangle, we only need height and width to calculate both the area and perimeter. So we will just ask for input of those values

- Input height, width
- $Area = height * width$
- $Perimeter = 2*height + 2*width$
- Output Area, Perimeter

In terms of code it would look something like this

```cpp
#include <iostream> 
using namespace std;

int main(){
	cout << "Input the height" << endl;
	int height;
	cin >> height;
	
	cout << "Input the width" << endl;
	int width;
	cin >> width;
	
	int Area = width * height;
	int Perimeter = 2*width + 2*height;
	
	cout << "Area = " << Area << endl << "Perimeter = " << Perimeter << endl;
	return 0;
}
```