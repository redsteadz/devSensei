## Task 1:
Take 10 integer inputs from user store them in an array and print them on screen

```cpp
int arr[10];
int main(){
	for(int i = 0; i < 10; i++){
		cout << "Input the " << i << "element";
		cin >> arr[i];
	};
	
	for(int i = 0; i < 10; i++){
		cout << arr[i] << endl;
	};
}
```

## Task 2:
Write a C program that takes a user input array with N elements and prints the sum of its elements.

```cpp

int main(){
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++){
		cout << "Input the " << i << "element";
		cin >> arr[i];
	};
	
	for(int i = 0; i < N; i++){
		cout << arr[i] << endl;
	};
}
```

## Task 3:
Write a C program to find the minimum and maximum number in an array with N elements
```cpp
int main(){
	int N, max = -100000, min=1000000;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++){
		cout << "Input the " << i << " element ";
		cin >> arr[i];
	};
	
	for(int i = 0; i < N; i++){
		if (max > arr[i]){max = arr[i];}
		if (min < arr[i]){min = arr[i];}
	}
	cout << "MAX " << max << endl;
	cout << "MIN " << min;
}
```

## Task 4:
Take 20 integer inputs from user and print the following
```cpp
int main(){
	int num;
	int pos=0, odd=0, even=0, neg=0, zero=0;
	for (int i=0; i<5; i++){
		cin >> num;
		if(num > 0){pos++;}else if(num<0){neg++;} else{zero++;}
		if(num%2){even++;} else {odd++;}
	}
	cout << "Even " << even << endl;
	cout << "Odd " << odd << endl;
	cout << "pos " << pos << endl; 
	cout << "Neg " << neg << endl;
	cout << "Zero " << zero << endl;
	
}
```

## Task 5:
Take 10 integers inputs from user and store them in an array, Now, copy all the elements in another array but in reverse order.

```cpp
int main(){
	int a[10];
	int r[10];
	for (int i = 0; i<10; i++){
	    cout << "Enter the Element " << i << " ";
		cin >> a[i];
		r[10-i-1] = a[i];
	}
		
	for (int i = 0; i<10; i++){
		cout << r[i] << endl;
	}
}
```