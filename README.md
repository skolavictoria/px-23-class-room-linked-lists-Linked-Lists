# Linked List Implementation in C++

This repository contains a starter codebase for implementing and practicing fundamental operations on a **Linked List** data structure in C++. The goal is to help you master the concepts of dynamic memory management, pointers, and algorithm design while working with a foundational data structure.

## Table of Contents
1. [Overview](#overview)
2. [Tasks to Implement](#tasks-to-implement)
3. [Starter Code](#starter-code)
4. [Evaluation Criteria](#evaluation-criteria)
5. [Additional Notes](#additional-notes)

---

## Overview

A **Linked List** is a linear data structure where elements (called nodes) are stored in non-contiguous memory locations. Each node contains:
- A **value** (data).
- A pointer to the **next node** in the list.

The provided code defines two classes:
1. `Node`: Represents a single node in the linked list.
2. `LinkedList`: Manages the entire linked list and provides methods to manipulate it.

Your task is to complete the implementation of various algorithms for the linked list. These algorithms will test your understanding of traversal, insertion, deletion, and other key operations.

---

## Tasks to Implement

Below is the list of methods you need to implement in the `LinkedList` class. These methods cover the basic functionality of a linked list:

### 1. **Insertion**
- `void push(int value)`
  - Add a new node with the given value at the **beginning** of the list.
- `void append(int value)`
  - Add a new node with the given value at the **end** of the list.
- `void insert(int position, int value)`
  - Insert a new node with the given value at the specified **position** (0-based index). If the position is invalid, handle it gracefully (e.g., print an error message).

### 2. **Deletion**
- `int pop()`
  - Remove and return the value of the **first node** in the list. If the list is empty, handle it gracefully.
- `void del(int position)`
  - Delete the node at the specified **position** (0-based index). If the position is invalid, handle it gracefully.

### 3. **Traversal**
- `Node* get_elem_by_index(int index)`
  - Return the node at the specified **index**. If the index is out of bounds, return `nullptr`.
- `int get_len()`
  - Return the number of nodes in the list. (Already implemented as a reference.)

### 4. **Manipulation**
- `void reverse()`
  - Reverse the order of the nodes in the list. (A helper function `reverseLinkedList` is provided as a starting point.)
- `void sort()`
  - Sort the nodes in ascending order based on their values. (A helper function `sortLinkedList` is provided as a starting point.)
- `void shuffle()`
  - Randomly shuffle the nodes in the list. (You can use the `rand()` function or a similar approach.)

### 5. **Search**
- `bool search(int value)`
  - Check if a node with the given value exists in the list. Return `true` if found, otherwise `false`.

---

## Starter Code

The following starter code is provided to help you get started:

```c++
#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
private:
    int value;
    Node* next_member = nullptr;
public:
    Node(int value) : value(value) {}
    void add_next_member(Node* ptr) { next_member = ptr; }
    int get_value() { return value; }
    Node* get_next_member() { return next_member; }
};

class LinkedList {
public:
    Node* head = nullptr;
    LinkedList(Node* head) : head(head) {}

    void display() {
        Node* mmbr = head;
        while (mmbr) {
            cout << mmbr->get_value() << endl;
            mmbr = mmbr->get_next_member();
        }
    }

    // Methods to implement
    void insert(int position, int value) {}
    void append(int value) {}
    void push(int value) {}
    int pop() {}
    void del(int position) {}
    Node* get_elem_by_index(int index) {}
    void reverse() {}
    void sort() {}
    void shuffle() {}
    bool search(int value) {}
};
```

### Helper Functions
Two helper functions are provided as examples:
- `reverseLinkedList(LinkedList* lst)`: Reverses the linked list.
- `sortLinkedList(LinkedList* lst)`: Sorts the linked list using a bubble sort-like approach.

You can use these functions as references to implement the corresponding methods in the `LinkedList` class.


