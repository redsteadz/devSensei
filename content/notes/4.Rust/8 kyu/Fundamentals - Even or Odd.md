---
title: Fundamentals - Even or Odd
tags:
  - rust
  - codewars
  - programming
  - basics
date: 2023-11-13
---
## Description
Create a function that takes an integer as an argument and returns `"Even"` for even numbers or `"Odd"` for odd numbers.

## Code -- Written
```rust
fn even_or_odd(i: i32) -> &'static str {
    if i % 2 == 0 {
        return "Even";
    }
    else {return "Odd"}
}
```

## Code -- Recommended
```rust
fn even_or_odd(i: i32) -> &'static str {
  match i % 2 {
    0 => "Even",
    _ => "Odd",
  }
}
```

What the hell is the `match` ?
Basically the "case" of rust
### ChatGPT
In Rust, a "match" is a control flow construct that allows for pattern matching of a value against a series of patterns. It is similar to a switch statement in other programming languages.

By using a match expression, you can compare an expression with multiple patterns and execute different code blocks based on the matching pattern. It ensures that all possible cases are handled and provides exhaustive pattern checking at compile-time, which helps in writing safe and reliable code.

The syntax of a match expression in Rust looks like this:

```
match expression {
    pattern1 => {
        // code to execute if expression matches pattern1
    }
    pattern2 => {
        // code to execute if expression matches pattern2
    }
    // and so on...
}
```

Inside each pattern block, you can write the code that should be executed when the expression matches that particular pattern. The value of the matching pattern can be bound to a variable and used inside the block.

Match expressions are commonly used with enums or pattern structs, where different variants or properties of the data can be matched to perform specific actions. It provides a concise and powerful way to handle different cases and make decisions based on the value of an expression.


- [Link](https://www.codewars.com/kata/53da3dbb4a5168369a0000fe/train/rust)
