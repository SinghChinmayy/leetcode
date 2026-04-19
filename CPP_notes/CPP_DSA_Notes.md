# Basic Maths

## 32 bit range

![](../../Explain/_assets/Pasted%20image%2020260416215804.png)

![](../../Explain/_assets/Pasted%20image%2020260416215940.png)

# STD Library

## STD::VECTOR

### Insert element

```cpp
.insert()
```

It is used to insert element based on index in `std::vector`.

```cpp
v.insert(iterator, value);
```

```cpp
vector.insert(position_iterator, value);
```

### Remove/pop element

Pop last element → `v.pop_back();`

#### Erase specific element

> Remember `erase()` expects an iterator

```cpp
v.erase(v.begin() + index);
```

### Reverse element

- When you use `reverse(arr.begin(), arr.end());`

### End of the vector

#### Access last element

```cpp
nums.end();
```

#### Insert element at end

```cpp
v.push_back(4);
```

or

```cpp
v.insert(v.end(), {6, 7, 8});
```

## Pointers

### Point to first element of vector

- Point to first element in vector:

```cpp
int *ptr = &nums[0]
```

#### .data() in std::vector::data

- A pointer to the first element in the array used internally by the vector.

## Swap elements

```cpp
std::swap(v[left], v[right]);
```

# Sliding Window


# Dynamic Programming

## Longest Increasing Subsequence

[Code](300.%20longest%20increasing%20subsequence.cpp)

![](../../_assets/Pasted%20image%2020260213153810.jpg)

![](../../_assets/Pasted%20image%2020260213153810%201.jpg)

![](../../_assets/Pasted%20image%2020260213153811.jpg)

![](../../_assets/Pasted%20image%2020260213153813.jpg)

![](../../_assets/Pasted%20image%2020260213153814.jpg)