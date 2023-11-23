---
title: Birthday Paradox
date: 2023-10-29
tags:
  - fundamental
  - maths
  - basic
---
Birthday ? Kski birthday treat do bhai treat do !

The birthday paradox basically asks

>[!question]
>What is the number of people *n* in a room, given that the probability of two people having the same birthday is *p*

By Mathematical evaluation it can be said that 
$$
P(same) = 1 - P(different)
$$
Meaning that If we can find the probability of people having a different birthday in a room, We can find the probability of it being the same
Now we can find the probability of $P(different)$ by:

$$
P(different) = \frac{364}{365} * \frac{363}{365} ... \frac{n-1}{365}
$$
We also know about the Taylor series:
$$
e^x = 1 + x +\frac{x^2}{2!}...  1+x
$$
An Approximation:
$$
e^x = 1 - x
$$
Or to be precise (for this example)
$$
e^{-\frac{a}{365}} = 1 - \frac{a}{365}
$$
