#ifndef PROBAB_RULES_H
#define PROBAB_RULES_H

#include "multi_index.h"
#include <vector>

/**
* This class describes the rules of Conway's Game of Life automata.
*/
template< typename Field, typename CellType >
class probabilistic_rules
{
public:
	// Type of multi-index, by which the addressing of cells is performed
	typedef multi_index< 2 > multi_index_type;

	typedef CellType cell_type;

	// Returns cells which are adjacent to given cell
	std::vector< multi_index_type > get_adjacent_indexes(const Field& field, const multi_index_type& mi) const {
		std::vector<multi_index_type> adjacent_indexes;
		int d_x[] = { -1,0,1,-1,0,1,-1,1 };
		int d_y[] = { 1,1,1,-1,-1,-1,0,0 };
		int mi_x = mi.get(0);
		int mi_y = mi.get(1);
		int height = 0, width = 0;
		field.get_sizes(&height, &width);
		multi_index_type sample;
		for (int i = 0; i < 8; ++i) {
			int coord_x = mi_x + d_x[i];
			int coord_y = mi_y + d_y[i];
			if (coord_x < 0 || coord_x >= height || coord_y < 0 || coord_y >= width)
				continue;
			sample.set(0, coord_x);
			sample.set(1, coord_y);
			adjacent_indexes.push_back(sample);
		}
		return adjacent_indexes;
	}

	// For Conway's automata, the radius is 1
	int get_influence_radius() const {
		return 1;
	}

	// Returns the next state for 'mi' position, depending on content of 'field'
	/*Any live cell with fewer than two live neighbors dies, as if by underpopulation.
	Any live cell with two or three live neighbors lives on to the next generation.
	Any live cell with more than three live neighbors dies, as if by overpopulation.
	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
	*/
	cell_type get_next_state(const Field& field, const multi_index_type& mi) const {
		int live_neighbors = 0;
		cell_type this_cell = field.get(mi);
		std::vector<multi_index_type> neighbors_indexes = get_adjacent_indexes(field, mi);

		for (int i = 0; i < (int)neighbors_indexes.size(); ++i)
		{
			if (field.get(neighbors_indexes[i]) == _alive)
				++live_neighbors;
		}
		if (live_neighbors == 3)
		{
			if (this_cell == _dead)
				this_cell = _alive;
		}
		else if (live_neighbors < 2 || live_neighbors > 3)
		{
			if (this_cell == _alive)
				this_cell = _dead;
		}

		//only in probabilistic_rule
		int n = 0;
		int random_num = 0;

		if (live_neighbors == 1 || live_neighbors == 4) {
		 n = get_random_range_length(_probability / 2);
		 random_num = std::rand() % (int)(std::pow(10, n)) + 1; //get random number in range 1 to 10^n
		 if (random_num <= _probability * std::pow(10, n))
			this_cell = _alive;
		}

		if (live_neighbors == 0) {
			n = get_random_range_length(_probability);
			random_num = std::rand() % (int)(std::pow(10, n)) + 1; //get random number in range 1 to 10^n
			if (random_num <= _probability * std::pow(10, n))
				this_cell = _alive;
		}

		
		return this_cell;

	}

	void set_alive(const cell_type& alive) {
		this->_alive = alive;
	}
	void set_dead(const cell_type& dead) {
		this->_dead = dead;
	}
	void set_probability(double probability) {
		this->_probability = probability;
	}
	

private:
	int get_random_range_length(double probability) const{
		int length = 0;
		int whole_part = probability;
		while (probability -  whole_part > 0) {
			probability *= 10;
			whole_part = probability;
			++length;
		}
		return length;
	}


protected:
	cell_type _alive;
	cell_type _dead;
	double _probability;

};


#endif
