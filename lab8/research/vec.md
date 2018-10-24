https://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm

to void allocation too often use `reserve()` member function. The parameter it given, vector reserve at least that amount of memory.

`reserve()` **will grow the allocated storage of the vector, if necessary but will never shrink it.**

## Default and Parameter initialization
```cpp {.line-numbers}
// snip 1
std::vector<int> v(10)

// snip 2
std::vector<int> v;
v.reserve(10);
```
Two snippets are different.
1. 1st snippet defines a vector containing 10 integers, and initializes them with their default value (0). If it was user build class it would call default constructor and allocates memory and initial value.
2. 2nd snippet defines an empty vector, and then tells it to make room for 10 integers. The vector will allocate enough memory for at least 10 element but does not initialize those memory.

## Find How many elements in vector
`capacity()` to check how many elements would fit in vector.
`size()` to check how many elements are in vector.
so, number of elements that can be added to a vector without triggering a reallocation always is capacity() - size()

**Note**: previews example 0 was only valid index. Yes, we made room for at least 10 elements with `reserve()` but the memory is not initialized. Because, int is build-in type so operator[] to assign value is possible. But we would make inconsistent state vector `size()` still return 1. Moreover, we try to access other than first element with `at()` it would produce **<span style="color: #0000FF">std::out_of_range</span>**. first glance it look inconvenient, but a closer look: if the vector contains user-defined class, `reserve()` wouldn't call ctor. Accessing a not-yet-constructed object has return undefined, and no-no in any case.

**Role of `reserve()`** is minimize the number of potential reallocations and that it will not influence the number of elements in the controlled sequence. 
A call to `reserve()` with a parameter smaller than the current `capacity()` is begin -- It simply does nothing.

###Correct Way to enlarge vector
`size()` member function to do that.
- If new size is larger than old => preserve old elements and rest will be initialized according to the second parameter.
- If old size is larger than new => preserve first elements and discard rest of elements.
- If the new size is larger than `capacity()`, it would reallocate storage so all new_size elements fit. `resize()` will never shrink `capacity()`

Another way to enlarge vector is use `push_back()`.

Line 51-61 code produce the same result.
1. 1st is first `resize(10)` and initialize with default constructor. After in valid objects we use `set()` to give value into `val_`.
2. 2nd version, we first `reserve(10)` element. The vector allocate its storage. Then, we create `X` with `X(val)` use it push into `array_push()` vector.

## Operation on Vector
We now know how to fill vector, so let's learn how to operate on them. First let's compare between C-style array, and possibility over them.

###Initialize vector with c-style array
There is another constructor 1st is first element of array, 2nd is one-past-last of array.
**[first, one-past-last]**
```cpp {.line-number}
double p[] = {1, 2, 3, 4, 5};
std::vector<double> a(p, p + 5);
```

###Care about memory reallocation
```cpp {.line-number}
std::vector<int> v(5);
int *pi = &v[3];
v.push_back(999);
*pi = 333;                  // <-- probably an error, pi isn't valid any more
``` 
Vector may reallocated after `push_back()`. So wise to use `reserve()`, and ensure does not reallocate.

##Iterator
Iterator , you can dereference it to obtain the element it "points" to.
Code line 84 - 94.
```c++ {.line-numbers}
std::vector<double>::const_iterator i;
```
This declares a const iterator i for `vector<double>`. We are using *const* iterator because we do not intend to modify the contents of the vector.
```c++ {.line-numbers}
i = a.begin();
```
The member function returns first an iterator that "points" to the **first-element** in the sequence.
```c++ {.line-numbers}
i != a.end();
```
The member function returns an iterator that "points" to the **one-past-last-element**.

We can do it by pointer the same way. Code line 96 - 99.
But we use iterator instead of pointer is because standard library has many build-in function like searching, sorting use iterator.

#Member function of Vector

##Constructor
```c++ {.line-numbers}
typedef std::vector<std::string> str_vec_t;
str_vec_t v1;                       // Create an empty vector
str_vec_t v2(10);                   // 10 copies of empty strings
str_vec_t v3(10, "Hello");          // 10 copies of the string "Hello"
str_vec_t v4(v3)                    // Copy ctor

    std::list<std::string> sl;      // Create list and populate it
    sl.push_back("cat");
    sl.push_back("dog");
    sl.push_back("mouse");

str_vec_t v5(sl.begin(), sl.end()); // A copy of the range in another container

v1 = v5                             // will copy all element from v5 to v1
``` 
##`Assign()` function
The `assign()` function reinitialize the vector. Old elements are discarded and make new

```c++ {.line-numbers}
v1.assign(sl.begin(), sl.end());
v1.assign(3, "Hello);
```

##Stack Operation
`push_back()` to add element in last
`pop_back()` to remove top element 
**Note:** 
- `pop_back()` does not return popped element value for safe exception free when popping empty vector. So peek before pop. And decrement `size()`.
- `pop.back()` does not shirk `capacity()`.

##Predefined Iterators
There is reverse iterator `reverse_iterator` or `const` version `const_reverse_iterator`.

## Element access
- `[]` get element without check
- `at()` check element in size, if not `std::out_of_range` error
- `front()` get first element of vector
- `back()` get last element of vector
Code line 101 - 115

## Comparison operation
Compare two vector's element size by `==`, `!=`, `>=`, `<=` and  `>` It only check `size()`, so `capacity()` does not matter in comparison.
**Note:** `<` is vector's lexicographically operator.

#Further reading
1. [C++ 11 ranged-based for](https://stackoverflow.com/questions/15927033/what-is-the-correct-way-of-using-c11s-range-based-for])
2. [gcc compiler to c++11 on ubuntu](https://stackoverflow.com/questions/17378969/how-to-change-gcc-compiler-to-c11-on-ubuntu)
3. [“dereferencing” a pointer](https://stackoverflow.com/questions/4955198/what-does-dereferencing-a-pointer-mean)




