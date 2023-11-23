---
title: "Greedy Algorithm"
description: "The idea, concept and understanding of the greedy algorithm"
date: "2023-08-12"
tags:
- general
- algorithms
- fundamentals
- greedy
---

This is a technique that basically picks out the "best" option it can and hopes that it ends up a globally correct option
The scenarios can vary for what choice would be the most optimal to satisfy the condition and for globally understanding

> [!question] 
> You are given an array *A* of  integers, where each element indicates the time a thing takes for completion. You want to calculate the maximum number of things that you can do in the limited time that you have.
> 	1. Sort the array A in ascending order
> 	2. Select each to-do item one by one.
> 	3. Add the time that it will take to complete that to-do into currentTime
> 	4. Add one to **numberOfThings**

Repeat this as long as the **currentTime** is less than or equal to **T**.

Let **A = {5, 3, 4, 2, 1}** and **T = 6**
After sorting, **A = {1, 2, 3, 4, 5}**

After the 1st iteration:
- **currentTime** = 1
- **numberOfThings** = 1

After the 2nd iteration:
- **currentTime** is 1 + 2 = 3
- **numberOfThings** = 2

After the 3rd iteration:
- **currentTime** is 3 + 3 = 6
- **numberOfThings** = 3

After the 4th iteration, **currentTime** is 6 + 4 = 10, which is greater than T. Therefore, the answer is 3.