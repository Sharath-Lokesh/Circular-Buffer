/*
* Author: Sharath Lokesh
*/

#pragma once

#include <iostream>
#include <array>
#include <optional>

template <typename T, int N, typename Container = std::array<T, N>>
class CircularBuffer
{
    Container _c;
    int _read_ptr;
    int _write_ptr;
    int _last_ptr;
    int _capacity;

    public:

    CircularBuffer() : _read_ptr(0), _write_ptr(0), _last_ptr(-1), _capacity(N){}

    // Resets the buffer
  void clear() {
    _write_ptr = 0;
    _read_ptr = 0;
    _last_ptr = -1;
    std::cout << "Buffer cleared!" << std::endl;
  }

  // Check if the buffer is empty
  bool is_empty() const { return _last_ptr == -1; }

  // Check if the buffer is full
  bool is_full() const { return _last_ptr == (_capacity - 1); }

  // Get the size of the buffer (number of elements)
  int size() const { return _last_ptr + 1; }

  // Get the capacity of the buffer
  int capacity() const { return _capacity; }

  // write an element to the buffer
  void write_data(const T& element) {
    if (is_full()) {
      std::cout << ("OVERFLOW_WARNING: Buffer is full") << std::endl;
    }
    _c[_write_ptr] = element;
    _last_ptr = (_last_ptr != _capacity - 1)? _write_ptr : _last_ptr;
    _write_ptr = (_write_ptr + 1) % _capacity;
  }

  // read an element from the buffer
  std::optional<T> read_data() {
    if (is_empty()) {
      std::cout << ("UNDERFLOW_WARNING: Buffer is empty") << std::endl;
      return std::nullopt;
    }
    T element = _c[_read_ptr];
    _read_ptr = (_read_ptr == _last_ptr + 1)? _read_ptr: (_read_ptr + 1) % _capacity;
    return element;
  }

  // Display the content of the buffer
  void buffer_display() const {
    if (is_empty()) {
      std::cout << "Buffer contents: Buffer is empty!" << std::endl;
      return;
    }
    for (int i = 0; i <= _last_ptr; i ++)
      std::cout << _c[i] << " ";
    std::cout << std::endl;
  }

};