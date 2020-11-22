#pragma once

#include <iostream>
#include <exception>
using std::exception;

template <class T>
class Vector
{
public:
	Vector(int size = 1);
	Vector(const Vector& v);
	~Vector();

	virtual void resize(int new_size);
	int size() const;

	T& operator[](const int index);
	T& operator[](const int index) const;
	
	Vector<T> operator+(Vector<T> op);
	Vector<T> operator-(Vector<T> op);
	Vector<T> operator-();
	Vector<T> operator*(double value);
	double operator*(Vector<T> op);

	Vector<T>& operator=(Vector<T> op);

	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
	{
		for (int i = 0; i < v.size(); i++)
			out << v[i] << ' ';
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Vector<T>& v)
	{
		for (int i = 0; i < v.size(); i++)
			in >> v[i];
		return in;
	}

private:
	T* data;
	int len;
};






template<class T>
Vector<T>::Vector(int size)
{
	data = new T[size];
	len = size;
	for (int i = 0; i < len; i++)
		data[i] = 0;
}

template<class T>
inline Vector<T>::Vector(const Vector& v)
{
	len = v.size();
	data = new T[len];
	for (int i = 0; i < len; i++)
		data[i] = v[i];
}

template<class T>
Vector<T>::~Vector()
{
	delete[] data;
}

template<class T>
void Vector<T>::resize(int new_size)
{
	*this = Vector<T>(new_size);
}

template<class T>
inline int Vector<T>::size() const
{
	return len;
}




template<class T>
T& Vector<T>::operator[](const int index)
{
	return data[index];
}

template<class T>
inline T& Vector<T>::operator[](const int index) const
{
	return data[index];
}

template<class T>
inline Vector<T> Vector<T>::operator+(Vector<T> op)
{
	if (this->size() != op.size())
		throw exception("Size is not equal");
	else {
		Vector<T> result = *this;
		for (int i = 0; i < op.size(); i++)
			result[i] += op[i];
		return result;
	}
}

template<class T>
inline Vector<T> Vector<T>::operator-(Vector<T> op)
{
	return *this + (-op);
}

template<class T>
inline Vector<T> Vector<T>::operator-()
{
	Vector<T> result = *this;
	for (int i = 0; i < result.size(); i++)
		result[i] = -result[i];
	return result;
}

template<class T>
inline Vector<T> Vector<T>::operator*(double value)
{
	Vector<T> result = *this;
	for (int i = 0; i < result.size(); i++)
		result[i] *= value;
	return result;
}

template<class T>
inline double Vector<T>::operator*(Vector<T> op)
{
	if (len != op.size())
		throw exception("Size is not equal");
	else {
		double result = 0;
		for (int i = 0; i < len; i++)
			result += data[i] * op[i];
		return result;
	}
}

template<class T>
inline Vector<T>& Vector<T>::operator=(Vector<T> op)
{
	len = op.size();
	data = new T[len];
	for (int i = 0; i < len; i++)
		data[i] = op[i];
	return *this;
}
