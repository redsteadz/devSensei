---
title: "Grasshopper - Personalized Message"
date: 2023-07-27 15:27
tags:
- rust
- fundamentals
- codewars
- basics
---
Create a function that gives a personalized greeting. This function takes two parameters: `name` and `owner`.

Use conditionals to return the proper message:

|case|return|
|---|---|
|name equals owner|'Hello boss'|
|otherwise|'Hello guest'|
## Code -- Written

A problem I am facing is `return` from a function, giving a string
So let's research about it !

The **`return`** keyword can be used to return a value inside a function’s body. When this keyword isn’t used, the last _expression_ is implicitly considered to be the return value. If a function returns a value, its **return type** is specified in the signature using `->` after the parentheses `()`.

**Statement vs. Expression**

- A statement does not return a value, so it cannot be used to assign a value to another variable. For example, in some languages, we may be allowed to write `x = y = 5`; but in Rust, `let x = (let y = 5)` is an invalid statement because the `let y = 5` statement does not return a value that can be assigned to `x`.
- Expressions can be a part of a statement.
- When a semi-colon is written at the end of an expression,​ it turns into a statement and does not return a value.
- `{}` blocks and function calls are expressions.
![](notes/4.Rust/8%20kyu/attachments/Pasted%20image%2020230727154358.png)

As my code is; 
```rust
fn greet(name: &str, owner: &str) -> String {
    if name == owner {
        "Hello boss"
    } 
    else {"Hello guest"}
}
```

## Code -- Using Match

```rust
fn greet(name: &str, owner: &str) -> String {
    match name == owner{
        true => "Hello boss".to_string(),
        false => "Hello guest".to_string(),
    }
}
```

The return value is not in String, it is in str ? 
- [x] 🔼 Learn the Difference between Str and String #task

[Link](https://www.codewars.com/kata/5772da22b89313a4d50012f7/rust)