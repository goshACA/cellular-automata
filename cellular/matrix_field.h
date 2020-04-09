#ifndef MATRIX_FIELD_H
#define MATRIX_FIELD_H

#include <vector>


/**
* This 'matrix_field' class stores states of all cells in a
* C-style matrix (array of arrays).
*/
template< typename CellType >
class matrix_field
{
public:
	// Type of multi_index, by which the addressing of cells is performed
	typedef multi_index< 2 > multi_index_type;

	// Type of value, stored in each cell
	typedef CellType cell_type;

	// Sets value 'new_value' at position 'mi'
	void set(const multi_index_type& mi, const cell_type& new_value) {
		_x[mi.get(0)][mi.get(1)] = new_value;
	}

	// Returns value at position 'mi'
	cell_type get(const multi_index_type& mi) const {
		return _x[mi.get(0)][mi.get(1)];
	}
	cell_type get(int x,int y) const  {
		return _x[x][y];
	}
	// Returns height and width of field
	void get_sizes(int* height, int* width) const {
		*height = _height;
		*width = _width;
	}
	


	/*matrix_field(const cell_type& _alive,const cell_type& _dead) {
		this->_dead = _dead;
		this->_alive = _alive;
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				_x[i][j] = _dead;
		
	}*/
	matrix_field(int width, int height, const cell_type& initial_cell = cell_type()) {
		_width = width;
		_height = height;
		_x.resize(_height, std::vector< cell_type >(_width, initial_cell));
	}
	

	/*cell_type ALIVE() const {
		return _alive;
	}
	cell_type DEAD() const{
		return _dead;
	}*/
	
protected:
	typedef std::vector< std::vector< cell_type > > data_type;

	int _width;

	int _height;

	data_type _x;
};


#endif