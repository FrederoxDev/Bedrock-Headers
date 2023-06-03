#pragma once

template<class T>
struct NewType {
    typedef T Raw;

    T value;

    NewType(const T& t_) : value(t_) {}
    NewType() {}
    NewType(const NewType<T>& t_) : value(t_.value) {}
    NewType<T>& operator=(const NewType<T>& rhs) { value = rhs.value; return *this; }
    operator T const& () const { return value; }
    bool operator==(const NewType<T>& rhs) const { return value == rhs.value; }
    bool operator<(const NewType<T>& rhs) const { return value < rhs.value; }
};