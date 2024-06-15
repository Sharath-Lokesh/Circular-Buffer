# Circular-Buffer
A data structure that hold the data. The following pointers are used to monitor the buffer:
- `write_ptr`: points to the next free address in the buffer
- `read_ptr`: marks the next position to be read.
- `last_ptr`: points to the last valid element in the buffer.

Circular buffer supports the following methods:
- `clear`: resets the `write_ptr` and `read_ptr` to 0 and `last_ptr` to -1.
- `is_empty`: to check if the buffer is empty.
- `is_full`: to check if the buffer is full.
- `size`: returns the size of the buffer.
- `write_data`: wrties the data into the buffer.
- `read_data`: reads one element from the buffer (pointed by read data).
- `buffer_display`: dispalys the content of buffer (last element denoted by `last_ptr`).
