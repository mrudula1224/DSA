#include <iostream>
#define MAX 1000

class Stack {
    int top;
    int arr[MAX]; 

public:
    Stack() { top = -1; }

    bool push(int x) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        return (top < 0) ? -1 : arr[top];
    }

    bool isEmpty() { return (top < 0); }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "Top element: " << s.peek() << std::endl;
    s.pop();
    std::cout << "After pop, top element: " << s.peek() << std::endl;

    return 0;
}
