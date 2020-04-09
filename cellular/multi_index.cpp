#include "multi_index.h"

template <int Dimension>
void multi_index<Dimension>::set(int index, int value) {
	_x[index] = value;
}

template <int Dimension>
int multi_index<Dimension>::get(int index) const {
	return _x[index];
}
template<int Dimension>
bool operator == (const multi_index< Dimension >& i1, const multi_index< Dimension >& i2) {
	for (int i = 0; i < Dimension; ++i)
		if (i1._x[i] != i2._x[i])
			return false;
	return true;
}
template<int Dimension>
bool operator != (const multi_index< Dimension >& i1, const multi_index< Dimension >& i2) {
	return !(i1 == i2);
}

template class multi_index<>;


