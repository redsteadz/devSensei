---
title: "Linked_List"
description: "The data-type of Linked List"
date: "2023-08-15"
tags:
- data_type
- OOP
- linked_list
- general
---

![](notes/1.General/Data_Types/attachments/Linked_List%202023-08-16%2018.25.25.excalidraw.svg)
%%[🖋 Edit in Excalidraw](notes/1.General/Data_Types/attachments/Linked_List%202023-08-16%2018.25.25.excalidraw.md), and the [dark exported image](notes/1.General/Data_Types/attachments/Linked_List%202023-08-16%2018.25.25.excalidraw.dark.svg)%%
# Overview
A linked list is a bunch of `nodes` that have a pointer value which point to the next value
Hence each node is connected to the next

## A simple Implementation of Linking two lists 

```js
const n1 = { data: 100}
const n2 = {data: 200}

// Linking the two together
n1.next = n2;

console.log(n1)
```

## Using Classes It can be implemented as well

```js {pre}
class Node{
	// This function is the main function which makes the node. 
	// If no value for next is give, it is assumed to be null
	constructor(data, next=null){
		this.data = data
		this.next = next;
	}
}
// Making a node
const node = new Node(100)
// Which points to null as no next value was specified
console.log(node)

```

Note that using classes you can make an object which possesses the same method as the other. Hence reducing the work to make a node and make it point to another
Furthermore it allows the object of node to have ability for methods which can run functions on the class of nodes all in one

Let's try this out

```js
// IMPORTED NODE


class LinkedList{
	// The head property is null because If the list is empty the head is null, later on it can be pushed to the next value making it the tail
	constructor(){
		this.head = null;
		this.size = 0;
	}
	// Insert First Node
	insertFirst(data){
		// Inserts a value making it the head and pushing whatever value was already there ahead
		this.head = new Node(data, this.head);
		this.size++;
	};

	// Insert Last Node
	insertLast(data){
		// Takes the data and makes a node from it, Remember that it points to null already
		let node = new Node(data);
		let current;
		// If empty, make head
		if(!this.head){
			this.head = node;
		} else {
			// Current head -> Iterates through the node, till it finds NEXT value to be null
			current = this.head;
			while(current.next){
				current = current.next;
			};
			// [DATA] -> now points to node -> which points to null already 
			current.next = node;
		}
		this.size++
	}

	// Print All the data
	printData(){
		let current = this.head;
		// Run this loop until the current becomes `null`
		while (current){
			console.log(current.data);
			current = current.next;
		}
	};

	// Insert at Index
	insertAt(data, i){
		// If index is valid
		if(i > 0 && i > this.size){return ;} 
		// if index is first 
		i == 0 ? insertFirst(data) : null
		
		
		const node = new Node(data);
		let current, previous;
		// Set current to first
		current = this.head;
		let count = 0;
		while(count < i){
			previous = current; // Node before index
			count++;
			current = current.next; // Node after index
		};
		node.next = current;
		previous.next = node; 
		this.size++
	};
	
	// Get At index
	atIndex(i){
		let current = this.head
		let count = 0
		while (count < i){
			// Iterate through the Nodes until the count == index
			current = current.next
			count++
		};
		return current;
	}
	// Remove at index
	removeAt(i){
		// Find the nigga at the index
		let current = this.head;
		let previous;
		let count = 0;
		while(count<i){
			previous = current;
			current = current.next;
			count++
		};
		// The previous nigga will now point to the current niggas next value
		previous.next = current.next;
		// Reduce the size
		this.size--;
	}
	
	// Clear the list
	clearList(){
		this.head = null;
		this.size = 0;
	// Data will be stored in memory needs to be removed !
	};
}

const ll = new LinkedList();

// INSERT THE DATA as first val
ll.insertFirst(100);
ll.insertFirst(200)
ll.insertFirst(300);

// Insert the data as the last val
ll.insertLast(400)

// Insert the node at a specific index
ll.insertAt(250, 2);

// Remove the node at 
ll.removeAt(1);


console.log("The node at index value 1 is ", ll.atIndex(1));

console.log("Print the data only")
ll.printData();

// console.log("The list as an entire object ")
// console.log(ll)
```

- [x] need to write about linked_list #task  [completion:: 2023-08-16]

