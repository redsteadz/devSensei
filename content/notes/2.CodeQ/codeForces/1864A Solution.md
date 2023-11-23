---
title: 1864 Increasing Decreasing
date: 2023-10-24
tags:
  - codewars
  - algorithm
  - greedy
---

So the idea for this solution is dependent upon the fact the best possible scenario would be for the resulting array `b` to be have the smallest possible difference of 1
Then iterate through the differences till the second last element 

```
A false statement would be
1 _ 3
Consisting of 3 elements
now the most idealistic difference would be _ to 3 as 1
so 1 2 3, But as the difference between 
2 - 1 == 3 - 2 -> This results in a false statement 

Input: 100 200 4
Output: 
100 _ _ 200
100 _ 199 200
100 197 199 200
And as 197 - 100 > 199 - 197 -> This solution is valid
```

You can  do this by `deque`

The questions are not difficult if understood, this rank  is  easy. As long as you are able to understand the question !

