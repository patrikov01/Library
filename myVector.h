#pragma once
#include <iostream>
template <typename T>
class Vector
{
private:
	T* vector;
	size_t size;
	size_t capacity;
	
	void copy(const Vector<T>& other);
	void resize();
	void erase();
public:
	Vector();
	~Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);

	T& operator[](size_t index);
	T& operator[](size_t index) const;
	bool operator==(const Vector<T>& other);
	void insertAt(const T& element, size_t index);
	void pushBack(T element);
	void popBack();
	void eraseElement(size_t index);
	void remove(T element);
	void print() const;
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vector);
	friend std::istream& operator>>(std::istream& in, Vector<T>& vector);
	size_t getSize() const;
	void swap(T& a, T& b);
};
template<typename T>
void Vector<T>::copy(const Vector<T>& otherVector) {
	vector = new T[otherVector.capacity];
	size = otherVector.size;
	capacity = otherVector.capacity;
	for (size_t i = 0; i < size; i++)
	{
		vector[i] = otherVector.vector[i];
	}
}
template<typename T>
void Vector<T>::resize() {
	capacity *= 2;
	T* newVector = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newVector[i] = vector[i];
	}
	delete[] vector;
	vector = newVector;
}
template<typename T>
void Vector<T>::erase() {
	delete[] vector;
}
template<typename T>
Vector<T>::Vector() {
	size = 0;
	capacity = 7;
	vector = new T[capacity];
}
template<typename T>
Vector<T>::~Vector() {
	erase();
}
template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copy(other);
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
template<typename T>
T& Vector<T>::operator[](size_t index) {
	if (index >= 0 && index < size) {
		return vector[index];
	}
	throw std::out_of_range("Out of range\n");
}
template<typename T>
T& Vector<T>::operator[](size_t index) const{
	if (index >= 0 && index < size) {
		return vector[index];
	}
	throw std::out_of_range("Out of range\n");
}

template<typename T>
void Vector<T>::insertAt(const T& element, size_t index) {
	if (size >= capacity)
	{
		resize();
	}
	for (size_t i = size; i > index; i--)
	{
		vector[i] = vector[i - 1];
	}
	size++;
	vector[index] = element;
}

template<typename T>
void Vector<T>::pushBack(T element) {
	if (size >= capacity)
	{
		resize();
	}
	vector[size++] = element;
}

template<typename T>
void Vector<T>::print() const {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << vector[i]<<std::endl;
	}
}
template<typename T>
size_t Vector<T>::getSize() const {
	return size;
}
template<typename T>
bool Vector<T>::operator==(const Vector<T>& other) {
	if (size != other.size) {
		return false;
	}
	for (size_t i = 0; i < size; i++) {
		if (vector[i] != other.vector[i]) {
			return false;
		}
	}
	return true;
}
template<typename T>
void Vector<T>::remove(T element) {
	for (size_t i = 0; i < size; i++) {
		if (vector[i] == element) {
		for (size_t j = i; j < size - 1; j++) {
			vector[j] = vector[j + 1];
		}
		size--;
		 }
	}
}
template<typename T>
void Vector<T>::popBack() {
	if (size > 0) {
		size--;
	}
}
template<typename T>
void Vector<T>::eraseElement(size_t index) {
	if (index >= size || index<0) {
		return;
	}
	for (size_t i = index; i < size - 1; i++) {
		vector[i] = vector[i + 1];
	}
	size--;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& vector) {
	size_t size = vector.getSize();
	out << '[';
	for (size_t i = 0; i < size; i++) {
		out << vector[i];
		if (i < size - 1) {
			out << ',';
		}
	}
	out << ']';
	return out;
}
template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& vector) {
	size_t number;
	in >> number;
	T newElement;
	for (size_t i = 0; i < number; i++)
	{
		in >> newElement;
		vector.pushBack(newElement);
	}
	return in;
}
template <typename T>
void Vector<T>::swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}