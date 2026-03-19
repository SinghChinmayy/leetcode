.insert()
  it is used to insert element based on index in std::vector

  v.insert(iterator, value);

# insert element
- ```
  vector.insert(position_iterator, value);
  ```
- Insert element at end
- ```
  v.push_back(4);
  ```
- ```
  v.insert(v.end(), {6, 7, 8});
  ```
  # pop element

  pop last element-> v.pop_back();
  erase specific element -> v.erase(v.begin() + index);

  # reverse element

  - when you use reverse(arr.begin(), arr.end());
      - it reverse the element till one element before last element
