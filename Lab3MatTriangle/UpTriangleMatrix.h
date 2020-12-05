#pragma once

#include "Vector.h"


template<class T>
class UpTriangleMatrix : public Vector<Vector<T>>
{
public:
	UpTriangleMatrix(int m_size = 1);
	~UpTriangleMatrix();

	void resize(int m_size);

	Vector<T> getRow(int i) const;
	Vector<T> getColumn(int j) const;

	UpTriangleMatrix<T> operator+(UpTriangleMatrix<T>& op);
	UpTriangleMatrix<T> operator-(UpTriangleMatrix<T>& op);
	UpTriangleMatrix<T> operator-();
	UpTriangleMatrix<T> operator*(double value);
	UpTriangleMatrix<T> operator*(UpTriangleMatrix<T>& op);

	friend std::ostream& operator<<(std::ostream& out, const UpTriangleMatrix<T>& m)
	{
		for (int i = 0; i < m.size(); i++)
		{
			for (int j = 0; j < m.size(); j++)
				out << m[i][j] << ' ';
			out << std::endl;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, UpTriangleMatrix<T>& m)
	{
		for (int i = 0; i < m.size(); i++)
			for (int j = i; j < m.size(); j++)
			{
				in >> m[i][j];
			}
		return in;
	}

};

template<class T>
inline UpTriangleMatrix<T>::UpTriangleMatrix(int m_size) : Vector<Vector<T>>(m_size)
{
	for (int i = 0; i < m_size; i++)
		(*this)[i].resize(m_size);

}

template<class T>
inline UpTriangleMatrix<T>::~UpTriangleMatrix()
{
	
}

template<class T>
inline void UpTriangleMatrix<T>::resize(int m_size)
{
	*this = UpTriangleMatrix<T>(m_size);
}

template<class T>
inline Vector<T> UpTriangleMatrix<T>::getRow(int i) const
{
	return (*this)[i];
}

template<class T>
inline Vector<T> UpTriangleMatrix<T>::getColumn(int j) const
{
	Vector<T> result(this->size());
	for (int i = 0; i < result.size(); i++)
		result[i] = (*this)[i][j];
	return result;
}




template<class T>
inline UpTriangleMatrix<T> UpTriangleMatrix<T>::operator+(UpTriangleMatrix<T>& op)
{
	if (this->size() != op.size())
		throw exception("Size is not equal");
	else {
		UpTriangleMatrix<T> result = *this;
		for (int i = 0; i < op.size(); i++)
			result[i] = result[i] + op[i];
		return result;
	}
}

template<class T>
inline UpTriangleMatrix<T> UpTriangleMatrix<T>::operator-(UpTriangleMatrix<T>& op)
{
	if (this->size() != op.size())
		throw exception("Size is not equal");
	else {
		UpTriangleMatrix<T> result = *this;
		for (int i = 0; i < op.size(); i++)
			result[i] = result[i] - op[i];
		return result;
	}
}

template<class T>
inline UpTriangleMatrix<T> UpTriangleMatrix<T>::operator-()
{
	UpTriangleMatrix<T> result = *this;
	for (int i = 0; i < result.size(); i++)
		result[i] = -result[i];
	return result;
}

template<class T>
inline UpTriangleMatrix<T> UpTriangleMatrix<T>::operator*(double value)
{
	UpTriangleMatrix<T> result = *this;
	for (int i = 0; i < result.size(); i++)
		result[i] = result[i] * value;
	return result;
}

template<class T>
inline UpTriangleMatrix<T> UpTriangleMatrix<T>::operator*(UpTriangleMatrix<T>& op)
{
	UpTriangleMatrix<T> result = *this;
	for (int i = 0; i < result.size(); i++)
		for (int j = i; j < result.size(); j++)
			result[i][j] = getRow(i) * op.getColumn(j);
	return result;
}
