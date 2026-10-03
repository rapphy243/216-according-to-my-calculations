#include <list>

template <typename T>
class Queue {
private:
    std::list<T> elements;

public:
    Queue() {}

    bool isEmpty() {
        return elements.empty();
    }

    void enqueue(const T& value) {
        elements.push_back(value);
    }

    T dequeue() {
        if (!elements.empty()) {
            T value = elements.front();
            elements.pop_front();
            return value;
        }
        return T{};
    }

    T front() {
        if (!elements.empty()) {
            return elements.front();
        }
        return T{};
    }

    T peek() {
        if (!elements.empty()) {
            return elements.front();
        }
        return T{};
    }

};
