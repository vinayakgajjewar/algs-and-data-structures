// A stack is a common data structure that represents things that need to be maintained in a specific order
// When a function calls another function, which then calls a third function,
// it is important that the third function returns to the second function rather than the first
// You can think about it like the functions being stacked on top of each other
// The last one added to the stack is the first one taken off
// The "call stack" is the term for the list of functions either executing or waiting for other functions to finish
// Push: To add an element onto the stack
// Pop: To remove an element from the stack
// Peek: To look at elements in the stack without removing them
// LIFO: Last-in, first-out
// FILO: Equivalent to LIFO, first-in, last-out

#include <iostream>

class Stack {
public:
    Stack(int);
    Stack();
    void push(int);
    int pop();
    int peek(int);
    void delete_stack();
protected:
    int *data;
    int curr_num_elems;
    int max_num_elems;
};

Stack::Stack(int max) {
    max_num_elems = max;
    data = new int[max_num_elems];
    curr_num_elems = 0;
}

Stack::Stack() {
    max_num_elems = 500;
    data = new int[max_num_elems];
    curr_num_elems = 0;
}

void Stack::push(int push_num) {
    data[curr_num_elems] = push_num;
    curr_num_elems++;
}

int Stack::pop() {
    curr_num_elems--;
    return data[curr_num_elems];
}

int Stack::peek(int depth) {
    return data[curr_num_elems - (depth + 1)];
}

void Stack::delete_stack() {
    delete[] data;
}

int main() {
    Stack my_stack;
    my_stack.push(15);
    my_stack.push(10);
    std::cout << my_stack.pop() << "\n";
    std::cout << my_stack.pop() << "\n";
}