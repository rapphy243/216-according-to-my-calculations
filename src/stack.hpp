#include <list>

template <typename T>
class Stack {
private:
    std::list<T> elements;

public:
    Stack() {}

     bool isEmpty() {
        return elements.empty();
    }

    void push(const T& value) {
        elements.push_back(value);
    }

    T pop() {
        if (!elements.empty()) {
            T value = elements.back();
            elements.pop_back();
            return value;
        }
        return T{};
    }

    T top() {
        if (!elements.empty()) {
            return elements.back();
        }
        return T{};
    }
};
