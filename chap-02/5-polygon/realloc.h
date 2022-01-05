#pragma once

#include <algorithm>
#include <utility>

template <typename T>
T* realloc(T* old_buffer, size_t old_size, size_t new_size)
{
    T* new_buffer = new T[new_size] {};

    const auto copy_size = std::min(old_size, new_size);
    for (size_t i = 0; i < copy_size; ++i)
    {
        new (&new_buffer[i])(T) { std::move(old_buffer[i]) };
    }

    delete[] old_buffer;
    return new_buffer;
}
