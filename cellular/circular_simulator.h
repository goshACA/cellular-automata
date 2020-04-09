#ifndef CIRCULAR_SIMULATOR_H
#define CIRCULAR_SIMULATOR_H

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
class circular_simulator
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

	void simulate_circular_iteration() {
		int height = 0, width = 0, radius = _rules->get_influence_radius();
		_field->get_sizes(&height, &width);

		matrix_field_proxy circular_copy_field(width, height, radius);
		multi_index_type coords;
		copy_field_to_proxy(circular_copy_field, width);
		for (int i = radius; i < height + radius; ++i)
		{
			// Calculate next state of cells of central row
			if (i >= height)
				coords.set(0, i - height);
			else
				coords.set(0, i);
			for (int j = 0; j < width; ++j)
			{
				coords.set(1, j);
				_field->set(coords, _rules->get_next_state(circular_copy_field, coords));
			}
			// Move down rows
			circular_copy_field.shift_down_rows();
			// Copy next row from field to circular field
			if (i + radius + 1 >= height)
				coords.set(0, i + radius + 1 - height);
			else
				coords.set(0, i + radius + 1);
			copy_row_to_proxy(circular_copy_field, coords.get(0), width);
		}
	}

	circular_simulator(Field* _field, Rules* _rules) {
		this->_field = _field;
		this->_rules = _rules;
	}

protected:
	field_type * _field;

	rules_type* _rules;

private:
	void copy_field_to_proxy(matrix_field_proxy& proxy, int width) {
		multi_index_type field_coords;
		int radius = proxy.get_radius();
		int count = 0;
		while (count != radius)
		{
			proxy.shift_down_rows();
			++count;
		}
		for (int i = 0; i < 2 * radius + 1; ++i)
		{
			field_coords.set(0, i);
			for (int j = 0; j < width; ++j)
			{
				field_coords.set(1, j);
				proxy.set(field_coords, _field->get(field_coords));
			}
		}
	}

	void copy_row_to_proxy(matrix_field_proxy& proxy, int field_row_index, int width)
	{
		multi_index_type field_coords;
		field_coords.set(0, field_row_index);
		for (int j = 0; j < width; ++j)
		{
			field_coords.set(1, j);

			proxy.set(field_coords, _field->get(field_coords));
		}
	}
};

#endif 