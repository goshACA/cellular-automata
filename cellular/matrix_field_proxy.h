#ifndef MATRIX_FIELD_PROXY_H
#define MATRIX_FIELD_PROXY_H

#include <deque>
#include <cassert>


/**
* This 'matrix_field_proxy' class stores states of several adjacent rows
* of a matrix, mut presents them as if it stores the entire matrix.
*/
template< typename CellType >
class matrix_field_proxy
{
public:
	// Type of multi_index, by which the addressing of cells is performed
	typedef multi_index< 2 > multi_index_type;

	// Type of value, stored in each cell
	typedef CellType cell_type;

	/**
	* Constructor
	* Creates space for "2*radius+1" rows, with center at logical row 0.
	*/
	matrix_field_proxy(int width, int height, int radius,
		const cell_type& initial_value = cell_type())
		: _width(width), _height(height), _radius(radius)
	{
		// Allocate space
		for (int i = 0; i < 2 * _radius + 1; ++i)
			_data.push_back(new cell_type[_width]);
		// Fill with initial value
		for (int i = 0; i < 2 * _radius + 1; ++i)
			for (int j = 0; j < _width; ++j)
				_data[i][j] = initial_value;
		// Center on first row
		_central_row = 0;
	}


	/**
	* Destructor
	* Deallocates used space for rows.
	*/
	~matrix_field_proxy()
	{
		// Deallocate space
		for (int i = 0; i < (int)_data.size(); ++i)
			delete[] _data[i];
	}

	/**
	* Returns logical index of central row of the area, over which
	* this matrix_field_proxy currently operates.
	*/
	int get_central_row() const
	{
		return _central_row;
	}

	/**
	* Moves to next logical row, so this matrix_field_proxy will start
	* to operate on the area, shifted down by one row.
	*/
	void shift_down_rows()
	{
		// Perform cyclic shift of pointers of the rows
		row_type first_row = _data[0];
		for (int i = 1; i < (int)_data.size(); ++i)
			_data[i - 1] = _data[i];
		_data.back() = first_row;
		// Central row is changed
		++_central_row;
	}

	/**
	* Moves to previous logical row, so this matrix_field_proxy will start
	* to operate on the area, shifted up by one row.
	*/
	void shift_up_rows()
	{
		row_type last_row = _data[_data.size() - 1];
		for (int i = _data.size() - 1; i >= 1; --i)
			_data[i] = _data[i - 1];
		_data.front() = last_row;
		--_central_row;
	}

	/**
	* Sets value 'new_value' at logical position 'mi'
	*/
	void set(const multi_index_type& mi, const cell_type& new_value)
	{
		int r = mi.get(0);
		int c = mi.get(1);
		// Check range of column
		assert(c >= 0);
		assert(c < _width);
		// Bring logical row index to physical row index
		r -= _central_row;
		r += _radius;
		while (r < 0)
			r += _height;
		while (r >= _height)
			r -= _height;
		// Check range of row
		assert(r >= 0);
		assert(r < 2 * _radius + 1);
		// Set new value
		_data[r][c] = new_value;
	}

	/**
	* Returns value at logical position 'mi'.
	*/
	cell_type get(const multi_index_type& mi) const
	{
		int r = mi.get(0);
		int c = mi.get(1);
		// Check range of column
		assert(c >= 0);
		assert(c < _width);
		// Bring logical row index to physical row index
		r -= _central_row;
		r += _radius; 
		while (r < 0)
			r += _height;
		while (r >= _height)
			r -= _height;
		// Check range of row
		assert(r >= 0);
		assert(r < 2 * _radius + 1);
		// Set new value
		return _data[r][c];
	}

	/**
	* Returns logical height and width of the field.
	*/
	void get_sizes(int* height, int* width) const
	{
		*height = _height;
		*width = _width;
	}

	int get_radius() const
	{
		return _radius;
	}

protected:
	/**
	* Returns index of the row, which is down by 'offset'
	* from 'row', considered that edges of the area are glued.
	*/
	int get_next_cyclic_row(int row, int offset) const
	{
		row += offset;
		if (row >= _height)
			row -= _height;
		return row;
	}

	/**
	* Returns index of the row, which is up by 'offset'
	* from 'row', considered that edges of the area are glued.
	*/
	int get_prev_cyclic_row(int row, int offset) const
	{
		row -= offset;
		if (row < 0)
			row += _height;
		return row;
	}

protected:
	typedef cell_type* row_type;
	typedef std::deque< row_type > data_type;

	/// Width of the area
	const int _width;

	/// Height of the area
	const int _height;

	/// Radius of influence (we'll need to store "2*radius+1" rows)
	const int _radius;

	/// Logical index of the row, surrounding area of which is currently
	///   represented.
	int _central_row;

	/// Storage for the "2*radius+1" rows.
	data_type _data;
};

#endif
