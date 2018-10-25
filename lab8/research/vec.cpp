#include <iostream>
#include <vector>

// * C-style array vs Vector
double mean(double *array, size_t n) {
    double m = 0;
    for (size_t i = 0; i < n; i++) {
        m += array[i];
    }
    return m / n;
};

int main() {
    std::vector<char> array;
    array.reserve(10);  // make room for 10 elements
    char c = 0;
    while (c != 'x') {
        std::cin >> c;
        array.push_back(c);
    }

    // * capacity() and size()
    int i = 999;
    std::vector<int> array;
    array.reserve(10);
    array.push_back(i);
    std::cout << array.capacity() << std::endl;  // 10
    std::cout << array.size() << std::endl;      // 1

    // * Enlarging with resize()
    std::vector<int> array;
    array.reserve(3);  // 3 capacity and 0 size

    array.push_back(999);  // Vector is now
    array.resize(5);       // 999 0 0 0 0

    array.push_back(333);  // 999 0 0 0 0 333

    array.reserve(1);  // do nothing, as capacity() > 1
    array.resize(3);   // shrink 999 0 0

    // This would fill as second parameter
    array.resize(6, 1);  // 999 0 0 1 1 1

    // * Enlarging with push_back()
    class X {
       public:
        X() : val_(0) {}
        X(int val) : val_(val) {}
        int get() { return val_; }
        void set(int val) { val_ = val; }

       private:
        int val_;
    };

    std::vector<X> ax;

    // ? version 1
    ax.resize(10);
    for (int i = 0; i < 10; i++) {
        ax[i].set(i);
    }

    // ? version 2
    ax.reserve(10);
    for (int i = 0; i < 10; i++) {
        ax.push_back(X(i));
    }

    // C-style array
    double arr[] = {1, 2, 3, 4, 5};
    std::cout << mean(arr, 5) << std::endl;  // will print 3

    // vector
    std::vector<double> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    std::cout << mean(&a[0], 5) << std::endl;

    // * Iterator
    // std::vector<double> arr;
    std::vector<double>::const_iterator it;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    for (it = a.begin(); it != a.end(); ++it) {
        std::cout << (*it) << std::endl;
    }

    const double *p;
    for (p = &a[0]; p != &a[5]; ++p) {
        std::cout << (*p) << std::endl;
    }

    // * Element access
    std::vector<int> v;
    v.push_back(999);

    // following statements are equivalent
    int i = v.front();
    int i = v[0];
    int i = v.at(0);
    int i = *(v.begin());

    // following statements are equivalent
    int i = v.back();
    int i = v[v.size() - 1];
    int i = v.at(v.size() - 1);
    int i = *(v.end() - 1);

    return 0;
}