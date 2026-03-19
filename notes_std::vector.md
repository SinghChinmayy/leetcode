# insert element
```
.insert()
```
 it is used to insert element based on index in std::vector
```
  v.insert(iterator, value);
```

```
  vector.insert(position_iterator, value);
```

  # remove/pop element

  pop last element-> v.pop_back();
 ## erase specific element ->
 
> Remember erase() expects an itterator
 
  ```
  v.erase(v.begin() + index);
```

  # reverse element

  - when you use reverse(arr.begin(), arr.end());

# Pointers

## Point to first element of vector

- point to first element in vector
```
int * ptr = &nums[0]
```
### .data() in std::vector::data
- A pointer to the first element in the array used internally by the vector.

# swap elements 
```
    std::swap(v[left], v[right]);
```

# End of the vector

## Access last element
```
nums.end();
```

## Insert element at end
  ```
  v.push_back(4);

 or

  v.insert(v.end(), {6, 7, 8});
  ```
      
      
      
      
      
      
      
      - it reverse the element till one element before last element
