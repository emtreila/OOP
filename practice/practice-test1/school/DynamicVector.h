#ifndef DYNAMICVECTOR_H
#define DYNAMICVECTOR_H

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

#include <exception>
#include <iostream>

template<typename T>
class DynamicVector {
private:
    unsigned int capacity;
    unsigned int numElements;

    // T* -> T1, T2, T3, ...
    // T** -> T1*, T2*, T3*, ...
    // no copy on T objects when using them
    // T resolves to *T
    T **elements;

public:
    DynamicVector(); // default constructor

    explicit DynamicVector(unsigned int capacity); // constructor with capacity

    ~DynamicVector(); // destructor

    void resize(); // resize the vector

    void add(const T &elem); // add an element to the vector

    bool remove(const T &elem); // remove an element from the vector

    bool update(const T &elem); // update an element from the vector

    T find(const T &elem) const; // find an element in the vector

    unsigned int sizeOfVector() const; // get the size of the vector

    T getElement(int index) const; // get an element from the vector

    void setElement(int index, const T &elem); // set an element in the vector
};

template<typename T>
DynamicVector<T>::DynamicVector() {
    /**
     * Implicit constructor
     */
    this->capacity = INITIAL_CAPACITY;
    this->numElements = 0;
    this->elements = new T *[this->capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(unsigned int capacity) {
    /**
     * Explicit constructor
     * @param capacity: the capacity of the vector
     */
    this->capacity = capacity;
    this->numElements = 0;
    this->elements = new T *[this->capacity];
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
    /**
     * Destructor
     */
    for (int i = 0; i < this->numElements; i++) {
        delete this->elements[i];
    }
    delete[] this->elements;
}

template<typename T>
void DynamicVector<T>::resize() {
    /**
     * Resize the vector
     */
    this->capacity *= GROWTH_FACTOR;
    T **newElements = new T *[this->capacity];
    for (int i = 0; i < this->numElements; i++) {
        newElements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = newElements;
}

template<typename T>
void DynamicVector<T>::add(const T &elem) {
    /**
     * Add an element to the vector
     * @param elem: the element to be added
     */
    if (this->capacity <= this->numElements) {
        this->resize();
    }
    this->elements[this->numElements++] = new T(elem);
}

template<typename T>
bool DynamicVector<T>::remove(const T &elem) {
    /**
     * Remove an element from the vector
     * @param elem: the element to be removed
     * @return true if the element was removed, false otherwise
     */
    for (int i = 0; i < this->numElements; i++) {
        if (*this->elements[i] == elem) {
            for (int j = i; j < this->numElements - 1; j++) {
                this->elements[j] = this->elements[j + 1];
            }
            --this->numElements;
            return true;
        }
    }
    return false;
}

template<typename T>
bool DynamicVector<T>::update(const T &elem) {
    /**
     * Update an element from the vector
     * @param elem: the element to be updated
     * @return true if the element was updated, false otherwise
     */
    for (int i = 0; i < this->numElements; i++) {
        if (*this->elements[i] == elem) {
            delete this->elements[i];
            this->elements[i] = new T(elem);
            return true;
        }
    }
    return false;
}

template<typename T>
T DynamicVector<T>::find(const T &elem) const {
    /**
     * Find an element in the vector
     * @param elem: the element to be found
     * @return the element if it was found, an exception otherwise
     */
    if (this->elements == nullptr) {
        throw std::exception();
    }
    for (int i = 0; i < this->numElements; i++) {
        if (*this->elements[i] == elem) {
            return *this->elements[i];
        }
    }
    throw std::exception();
}

template<typename T>
unsigned int DynamicVector<T>::sizeOfVector() const{
    /**
     * Get the size of the vector
     * @return the size of the vector
     */
    return this->numElements;
}

template<typename T>
T DynamicVector<T>::getElement(int index) const{
    /**
     * Get an element from the vector
     * @param index: the index of the element
     * @return the element if it was found, an exception otherwise
     */
    if (index < 0 || index >= this->numElements) {
        throw std::exception();
    }
    return *this->elements[index];
}

template<typename T>
void DynamicVector<T>::setElement(int index, const T &elem) {
    /**
     * Set an element in the vector
     * @param index: the index of the element
     * @param elem: the element to be set
     */
    if (index < 0 || index >= this->numElements) {
        throw std::exception();
    }
    delete this->elements[index];
    this->elements[index] = new T(elem);
}

#endif //DYNAMICVECTOR_H
