#include <iostream>
#include <exception>
using namespace std;

class OverflowError : public exception {};
class UnderflowError : public exception {};

template <typename T>
class RingQueue {
    T* data;
    int start, end, count, capacity;

public:
    RingQueue(int size) : capacity(size), start(0), end(0), count(0) {
        data = new T[capacity];
    }

    ~RingQueue() {
        delete[] data;
    }

    void insert(T val) {
        if (count == capacity) {
            throw OverflowError();
        }
        data[end] = val;
        end = (end + 1) % capacity;
        count++;
    }

    T extract() {
        if (count == 0) {
            throw UnderflowError();
        }
        T value = data[start];
        start = (start + 1) % capacity;
        count--;
        return value;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }
};

int main() {
    RingQueue<int> q(3);

    try {
        cout << "Pushing values...\n";
        q.insert(10);
        q.insert(20);
        q.insert(30);
        q.insert(40);
    } catch (OverflowError& e) {
        cout << "Queue is full.\n";
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "Popping values:\n";
        cout << q.extract() << endl;
        cout << q.extract() << endl;
        cout << q.extract() << endl;
        cout << "Attempting extra pop...\n";
        cout << q.extract() << endl;
    } catch (UnderflowError& e) {
        cout << "Queue is empty.\n";
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
