// ============================================================================
//  Lab: C++ Templates
//  Course: Object-Oriented Programming with C++
//  Single file only. No headers. C++17.
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Group 1
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// Group 2
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// Group 3
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;

public:
    Pair(A first, B second) : first_(first), second_(second) {}

    A getFirst() const {
        return first_;
    }

    B getSecond() const {
        return second_;
    }

    void setFirst(A value) {
        first_ = value;
    }

    void setSecond(B value) {
        second_ = value;
    }

    void swapValues() {
        A temp = first_;
        first_ = static_cast<A>(second_);
        second_ = static_cast<B>(temp);
    }
};

// Group 4
template <typename T>
class Box {
private:
    std::vector<T> items_;

public:
    void add(const T& item) {
        items_.push_back(item);
    }

    int size() const {
        return static_cast<int>(items_.size());
    }

    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Box index out of range");
        }
        return items_[index];
    }

    T total() const {
        T sum = T();
        for (const T& value : items_) {
            sum += value;
        }
        return sum;
    }
};

// Group 5
template <typename T>
int describe(const T& value) {
    return 1;
}

template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.length());
}

// Group 6
template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    FixedArray() {
        for (int i = 0; i < N; ++i) {
            data_[i] = T();
        }
    }

    int capacity() const {
        return N;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("FixedArray index out of range");
        }
        data_[index] = value;
    }

    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("FixedArray index out of range");
        }
        return data_[index];
    }
};

int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";
    std::cout << "addValues(5, 2.5) = " << addValues(5, 2.5) << "\n";

    Pair<int, int> p(10, 20);
    p.swapValues();
    std::cout << "Pair after swap: " << p.getFirst() << ", " << p.getSecond() << "\n";

    Box<int> box;
    box.add(5);
    box.add(10);
    box.add(15);
    std::cout << "Box total = " << box.total() << "\n";

    std::cout << "describe(10) = " << describe(10) << "\n";
    std::cout << "describe(string) = " << describe(std::string("Ali")) << "\n";

    FixedArray<int, 3> arr;
    arr.set(0, 100);
    arr.set(1, 200);
    std::cout << "FixedArray capacity = " << arr.capacity() << "\n";
    std::cout << "arr[0] = " << arr.at(0) << "\n";

    return 0;
}
