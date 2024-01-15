---
id: Kadane's Algorithm
aliases:
  - The Program 
tags:
  - algorithm
date: "2024-01-16"
title: Kadane's Algorithm
---

The Kadane's algorithm, is to search for the largest sum of contiguous subarray in an array.
The idea behind it is, that the sum upto point i, is either larger than the element at i. Or less than the element at i.
We keep making a rightward sub array as long the sum is increasing. 
for example -2 3 2 -1; 
We keep incrementing our subarray until the subarray sum becomes < arr\[i]. 
-2 + 3 < 3. So that means a new subarray must start from the position of 3.
as 3+2 >= 2. We can keep incrementing our subarray until the subarray sum becomes >= arr\[i].


# The Program 
```cpp 
long long maxSubarraySum(int arr[], int n) {
    long long sum = 0, uptoSum = 0;
    long long maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        uptoSum += arr[i];

        // If the current element alone is greater than the sum, start a new subarray
        if (uptoSum < arr[i]) {
            uptoSum = arr[i];
        }

        maxSum = std::max(maxSum, uptoSum);
    }

    return maxSum;
}

```
