#ifndef TRIVIAL_SIMULATOR_H
#define TRIVIAL_SIMULATOR_H

#include "conway_rules.h"
#include "matrix_field_proxy.h"
#include <vector>
#include <list>
typedef std::vector<int> row;
typedef std::vector<row> matrix;
/**
* This 'trivial_simulator' simulates iterations by simply
* calculating next state of each cell individually.
* For that it uses corresponding methods of provided 'Rules' concept.
*/
template< typename Field, typename Rules >
class trivial_simulator
{
public:
	// Type of field, used by the simulator
	typedef Field field_type;

	// Type of rules, used by the simulator
	typedef Rules rules_type;

	typedef typename Field::multi_index_type multi_index_type;

	typedef typename Field::cell_type cell_type;

	typedef matrix_field_proxy<cell_type> matrix_field_proxy;

	// Returns pointer to the used 'field' object
	field_type* get_field() {
		return _field;
	}

	// Returns pointer to the used 'rules' object
	rules_type* get_rules() {
		return _rules;
	}

	// Performs one step of simulation for entire field.
	void simulate_simple_iteration() {
		Field copy_field = Field(*_field);
		//for field dimension = 2
		int height = 0, width = 0;
		multi_index_type field_coords;
		_field->get_sizes(&height, &width);
		for (int i = 0; i < height; ++i) {
			field_coords.set(1, i);
			for (int j = 0; j < width; ++j) {
				field_coords.set(0, j);
				_field->set(field_coords, _rules->get_next_state(copy_field, field_coords));
			//	if(j >= 14 && j <= 20 && i >= 24 && i<= 26)
				//std::cout << i << " == i " << j << " = j " << _field->get(field_coords) << std::endl;
			}
		}
	}
	
	trivial_simulator(Field* _field, Rules* _rules) {
		this->_field = _field;
		this->_rules = _rules;
	}

protected:
	field_type * _field;

	rules_type* _rules;

};

#endif 