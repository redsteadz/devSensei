---
title: Tournament Method
date: 2023-10-28
tags:
  - algorithm
  - array
  - dsa
---
This involves dividing the array in two pieces until there are only 2 elements remaining, Off of which the comparison returns the pair of minima and maxima to which the preceding call compares the returned minima and maxima and continues until it reaches the end of the array

Trying to implement this would look something like

```cpp
int minFind(int arr[], int l, int h){
	int min, minl, minr;
	// If only one element, That element is the local minimum
	if (h == l){return arr[l];}
	// if two elements, compare the two
	else if (h == 1+l){
		if (arr[h] > arr[l]){return arr[l];}
		else {return arr[h];}
	}
	// Otherwise divide the array and run this again
		int mid = (h + l)/2;
		minl = minFind(arr, l, mid-1);
		minr = minFind(arr, mid, h);
		if (minr > minl){
			return minl;
		} else {
			return minr;
		}
}

int main(){
	int arr[6] = {4,3,1,5,6,2};
	cout << minFind(arr, 0, 5);
}
```

No change in efficiency !


