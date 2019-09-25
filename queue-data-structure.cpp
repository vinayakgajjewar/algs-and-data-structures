// Queues, like stacks, have restrictions on where you can add and remove elements
// Queues are like a cafeteria line: the person in the front is served first and people are added to the back of the line
// FIFO: First-in, first-out
// Enqueue: The addition of an element to a queue
// Dequeue: Removing an element from a queue

#include <iostream>

class Queue {
    public:
        Queue();
        void enqueue(int); // Add an item to the queue
        int dequeue(); // Return an item from the queue
        int num_elems();
    protected:
        int *data; // The actual data
        int max_num; // ???
        int begin; // The index of the beginning of the queue
        int end; // The index of the end of the queue
        int elem_count; // The number of elements
};

Queue::Queue() {
    max_num = 500;
    data = new int[max_num + 1]; //TODO: Figure out what the extra element is for
    begin = 0;
    end = 0;
    elem_count = 0;
}

void Queue::enqueue(int item) {
    data[end] = item;
    end++;
    elem_count++;
    // TODO: Figure out wrap-around
}

int Queue::dequeue() {
    int return_item = data[begin];
    begin++;
    elem_count--;
    //TODO: Figure out wrap-around
    return return_item;
}

int Queue::num_elems() {
    return elem_count;
}

int main() {
    Queue my_queue;
    my_queue.enqueue(3);
    std::cout << my_queue.dequeue() << "\n";
    my_queue.enqueue(5);
    my_queue.enqueue(6);
    std::cout << my_queue.dequeue() << "\n";
    std::cout << my_queue.dequeue() << "\n";
}