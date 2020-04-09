#ifndef MULTI_INDEX_H
#define MULTI_INDEX_H


/**
* This class represents multi-index as an array of individual indexes.
*/
template< int Dimension >
class multi_index
{
public:
	// Dimensionality of this multi-index
	static const int dimension = Dimension;

	void set(std::initializer_list< int > args)
	{
		std::initializer_list< int >::const_iterator it = args.begin();
		for (int i = 0; i < Dimension; ++i, ++it)
			_x[i] = *it;
	}

	// Sets individual index to 'value'
	void set(int index, int value) {
			_x[index] = value;
		}
	

	// Returns value of individual index
	int get(int index) const {
		return _x[index];
	}
	multi_index() {
		for (int i = 0; i < Dimension; ++i)
			_x[i] = 0;
	}
	multi_index(std::initializer_list< int > args)
	{
		std::copy(args.begin(), args.end(), _x);
	}

protected:
	int _x[Dimension];

	
};


template< int Dimension >
bool operator==(const multi_index< Dimension >& i1, const multi_index< Dimension >& i2) {
	for (int i = 0; i < Dimension; ++i)
		if (i1.get(i) != i2.get(i))
			return false;
	return true;
}

template< int Dimension >
bool operator!=(const multi_index< Dimension >& i1, const multi_index< Dimension >& i2) {
	return !(i1 == i2);
}

template< int Dimension >
bool operator<(const multi_index< Dimension >& i1, const multi_index< Dimension >& i2) {
	for (int i = 0; i < Dimension; ++i)
		if (i1.get(i) < i2.get(i))
			return true;
		else if (i1.get(i)> i2.get(i))
			return false;
	return false;
}


#endif
