#ifndef BST_FIELD_H
#define BST_FIELD_H

#include <set>
/**
* This 'bst_field' class stores states of all cells in a
* set
**/
template<typename CellType, int Dimension>
class bst_field{

public:
	// Type of multi_index, by which the addressing of cells is performed
	typedef multi_index< Dimension > multi_index_type;

	// Type of value, stored in each cell
	typedef CellType cell_type;
	
	void set(const multi_index_type& mi, const cell_type& new_value) {
		if (new_value == _alive && _x.find(mi) == _x.end())
			_x.insert(mi);
		if (new_value == _dead && _x.find(mi) != _x.end())
			_x.erase(mi);
	}

	cell_type get(const multi_index_type& mi) const {
		if (_x.find(mi)  == _x.end()) 
			return _dead;
		return _alive;
	}

	/*multi_index_type get_size() const
	{
		multi_index_type r;
		for (int i = 0; i < Dimension; ++i)
			r.set(i, INT_MAX);
		return r;
	}*/

	void get_sizes(int* height,int* width) const { 
		*height = _height;
		*width = _width;
	}

	/*bst_field(const cell_type& alive, const cell_type& dead) {
		_alive = alive;
		_dead = dead;
	}*/

	bst_field(int width, int height)
	{
		_width = width;
		_height = height;
	}

	 void set_alive(const cell_type& _alive) {
		 this->_alive = _alive;
	}
	 void set_dead(const cell_type& _dead) {
		 this->_dead = _dead;
	 }

protected:
	std::set<multi_index_type> _x;

	int _width;
	int _height;

	cell_type _alive;
	cell_type _dead;
};
#endif
