//Thanks McMrARM :)

#pragma once

#include <atomic>
#include <utility>
#include <algorithm>
#include <memory>

template <typename T, typename Y>
using UniquePtr = std::unique_ptr<T, Y>;

template<typename T>
struct SharedCounter {
    T* ptr;
    std::atomic<int> share_count = 0, weak_count = 0;

    SharedCounter(T* p) : ptr(p) {}

    void addSharedRef() { share_count++; }
    void addWeakRef() { weak_count++; }

    bool releaseSharedRef() {
        if (--share_count == 0) {
            if (ptr) {
                T* tmp = ptr;
                ptr = nullptr;
                delete tmp;
            }
            return (weak_count == 0);
        }
        return false;
    }

    bool releaseWeakRef() {
        return (--weak_count == 0 && !ptr);
    }
};

template<typename T>
class SharedPtr {
public:
    SharedCounter<T>* pc = nullptr;

    SharedPtr() {}

    SharedPtr(std::nullptr_t) {}

    SharedPtr(T* rawPtr) {
        if (rawPtr) {
            pc = new SharedCounter<T>(rawPtr);
            pc->addSharedRef();
        }
    }

    SharedPtr(const SharedPtr& sp) : pc(sp.pc) {
        if (pc)
            pc->addSharedRef();
    }

    template<typename T2>
    SharedPtr(SharedPtr<T2> const& sp) {
        pc = reinterpret_cast<SharedCounter<T>*>(sp.pc);
        if (pc)
            pc->addSharedRef();
    }

    ~SharedPtr() {
        reset();
    }

    T* get() const {
        if (!pc)
            return nullptr;
        return pc->ptr;
    }

    T& operator*() const {
        return *pc->ptr;
    }

    T* operator->() const {
        return pc->ptr;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        SharedPtr<T> tmp = other;
        std::swap(pc, tmp.pc);
        return *this;
    }

    void reset() {
        if (pc && pc->releaseSharedRef())
            delete pc;
        pc = nullptr;
    }

    template <typename... Args>
    static SharedPtr<T> make(Args&&... args) {
        return SharedPtr<T>(new T(std::forward<Args>(args)...));
    }
};

template<typename T>
class WeakPtr {
public:
    SharedCounter<T>* pc = nullptr;

    WeakPtr() {}

    WeakPtr(std::nullptr_t) {}

    WeakPtr(const SharedPtr<T>& sp) : pc(sp.pc) {
        if (pc)
            pc->addWeakRef();
    }

    WeakPtr(const WeakPtr& wp) : pc(wp.pc) {
        if (pc)
            pc->addWeakRef();
    }

    template<typename T2>
    WeakPtr(const WeakPtr<T2>& sp) {
        pc = reinterpret_cast<SharedCounter<T>*>(sp.pc);
        if (pc)
            pc->addWeakRef();
    }

    ~WeakPtr() {
        reset();
    };

    WeakPtr& operator=(const WeakPtr& other) {
        WeakPtr<T> tmp(other);
        std::swap(pc, tmp.pc);
        return *this;
    }

    WeakPtr& operator=(const SharedPtr<T>& other) {
        SharedPtr<T> tmp(other);
        std::swap(pc, tmp.pc);
        return *this;
    }

    bool operator==(T* p) {
        if (pc) {
            return (pc->ptr == p);
        }

        return (p == nullptr);
    }

    void reset() {
        if (pc && pc->releaseWeakRef())
            delete pc;
        pc = nullptr;
    }

    T* get() const {
        return (pc) ? pc->ptr : nullptr;
    }

    operator T* () const {
        return get();
    }

    T& operator*() const {
        return *pc->ptr;
    }

    T* operator->() const {
        return pc->ptr;
    }

    const WeakPtr<T>& null() {
        static WeakPtr<T> wnull;
        return wnull;
    }
};