# QueueUsingTwoStacks

## Description

A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

- Enqueue: Add a new element to the end of the queue.
- Dequeue: Remove the element from the front of the queue and return it.

In this challenge, you must first implement a queue using two stacks. Then process queries, where each query is one of the following _3_ 
types:

1. Enqueue element _x_ into the end of the queue.
2. Dequeue the element at the front of the queue.
3. Print the element at the front of the queue.

## Output

- For each query of type _3_, print the value of the element at the front of the queue on a new line. 

## Input

- The first line contains a single integer, _q_, denoting the number of queries.
- Each line _i_ of the _q_ subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query _type_, but only query _1_ is followed by an additional space-separated value, _x_, denoting the value to be enqueued.
