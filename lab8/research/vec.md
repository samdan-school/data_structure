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





