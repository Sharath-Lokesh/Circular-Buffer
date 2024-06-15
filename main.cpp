/*
* Author: Sharath Lokesh
*/
#include <iostream>
#include "circular_buffer.h"

int main() {
    CircularBuffer<int, 5> buffer;

    // Test empty buffer
    std::cout << "Is buffer empty? " << std::boolalpha << buffer.is_empty() << std::endl;
    std::cout << "Is buffer full? " << std::boolalpha << buffer.is_full() << std::endl;
    std::cout << "Buffer size: " << buffer.size() << std::endl;
    std::cout << "Buffer capacity: " << buffer.capacity() << std::endl;
    buffer.buffer_display();

    // Test writing to buffer
    std::cout << "\nTesting writing to buffer:" << std::endl;
    buffer.write_data(1);
    buffer.write_data(2);
    buffer.write_data(3);
    buffer.write_data(4);
    buffer.write_data(5);
    buffer.write_data(6);
    buffer.write_data(7);
    buffer.buffer_display();

    // Test reading from buffer
    std::cout << "\nTesting reading from buffer:" << std::endl;
    std::optional<int> element = buffer.read_data();
    if (element.has_value()) {
        std::cout << "Read element: " << element.value() << std::endl;
    }
    element = buffer.read_data();
    if (element.has_value()) {
        std::cout << "Read element: " << element.value() << std::endl;
    }
    element = buffer.read_data();
    if (element.has_value()) {
        std::cout << "Read element: " << element.value() << std::endl;
    }
    buffer.buffer_display();
    std::cout<<"Buffer size: " << buffer.size()<<std::endl;

    // Test clearing buffer
    std::cout << "\nTesting clearing buffer:" << std::endl;
    buffer.clear();
    std::cout << "Is buffer empty? " << std::boolalpha << buffer.is_empty() << std::endl;
    buffer.buffer_display();

    return 0;
}