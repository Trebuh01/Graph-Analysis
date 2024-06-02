#pragma once
using namespace std;
template <typename T> class Vector {

    T* arr;
    int capacity;
    int current;

public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    Vector(int size) {
        arr = new T[size];
        capacity = size;
        current = size;
    }
    Vector(int size, T default_value) {
        arr = new T[size];
        capacity = size;
        current = size;
        for (int i = 0; i < size; i++) {
            arr[i] = default_value;
        }
    }
    Vector(const Vector& other)
    {
        arr = new T[other.capacity];
        capacity = other.capacity;
        current = other.current;
        for (int i = 0; i < current; ++i)
        {
            arr[i] = other.arr[i];
        }

    }

    ~Vector() {
        delete[] arr;
    }

    void reverse() {
        std::reverse(arr, arr + current);
    }

    T* begin() {
        return &arr[0];
    }

    T* end() {
        return &arr[current];
    }

    void push(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[current] = data;
        current++;
    }

    T& operator[](int index) {
        if (index < 0 || index >= current) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= current) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    Vector& operator=(const Vector& other) {
        if (this != &other) {//sprawdzam czy wskasuja na ten sam obiekt w pamieci
            arr = new T[other.capacity];
            capacity = other.capacity;
            current = other.current;
            for (int i = 0; i < current; ++i)
            {
                arr[i] = other[i];
            }
        }
        return *this;
    }
    void push(T data, int index) {
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }

    T get(int index) const {
        if (index < 0 || index >= current) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }


    void pop() {
        if (current == 0) {
            throw std::out_of_range("Pop from empty vector");
        }
        current--;
    }

    int size() {
        return current;
    }
    int size() const {
        return current;
    }


    int getcapacity() {
        return capacity;
    }

    void print() {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};