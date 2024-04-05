// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T data[size];
    int top_index;
public:
    TStack() : top_index(-1) {}

    void push(T value) {
        if (top_index == size - 1) {
            std::cerr << "Stack is full" << std::endl;
            return;
        }
        data[++top_index] = value;
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return T();
        }
        return data[top_index--];
    }

    T top() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return T();
        }
        return data[top_index];
    }

    bool isEmpty() {
        return top_index == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
