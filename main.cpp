#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;
    int size;

public:
    Stack() {
        topNode = nullptr;
        size = 0;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty!" << std::endl;
            return 0;
        }

        Node* temp = topNode;
        int value = temp->data;
        topNode = topNode->next;
        delete temp;
        size--;

        return value;
    }

    int top() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty!" << std::endl;
            return 0;
        }

        return topNode->data;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        Node* current = topNode;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

void removeFirstNegative(Stack& stack) {
    Stack tempStack;

    while (!stack.isEmpty()) {
        int element = stack.pop();

        if (element < 0) {
            std::cout << "Remove element:" << element << std::endl;
            std::cout << std::endl;
            break;
        }

        tempStack.push(element);
    }

    while (!tempStack.isEmpty()) {
        stack.push(tempStack.pop());
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Stack stack;
    const int numElements = 100;

    for (int i = 0; i < numElements; i++) {
        int randomNum = std::rand() % 201 - 100;
        stack.push(randomNum);
    }

    std::cout << "Init stack:" << std::endl;
    stack.display();
    std::cout << std::endl;

    removeFirstNegative(stack);

    std::cout << "Result stack:" << std::endl;
    stack.display();
    std::cout << std::endl;


    return 0;
}
