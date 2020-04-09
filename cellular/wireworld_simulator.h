#ifndef WIREWORLD_SIMULATOR_H
#define WIREWORLD_SIMULATOR_H

#define empty 0
#define electron_head 1
#define electron_tale 2
#define conductor 3

template< typename Field, typename CellType >
class wireworld_simulator {

public:
	typedef multi_index< 2 > multi_index_type;
	typedef CellType cell_type;

	void construct_h_wire(Field& field, int r, int c1, int c2) {
		multi_index_type coords;
		coords.set(1, r);
		for (int j = c1; j <= c2; ++j) {
			coords.set(0, j);
			field.set(coords, conductor);
		}
	}

	void construct_v_wire(Field& field, int c, int r1, int r2) {
		multi_index_type coords;
		coords.set(0, c);
		for (int i = r1; i <= r2; ++i) {
			coords.set(1, i);
			field.set(coords, conductor);
		}
	}

	void construct_xor(Field& field, int r, int c) {
		multi_index_type coords;
		coords.set(1, r);
		coords.set(0, c);
		field.set(coords, empty);

		coords.set(1, r + 1);
		coords.set(0, c);
		field.set(coords, empty);

		coords.set(1, r - 1);
		for (int j = c - 1; j < c + 3; ++j) {
			coords.set(0, j);
			field.set(coords, conductor);
		}
		for (int i = r - 1; i < r + 2; ++i) {
			coords.set(1, i);
			field.set(coords, conductor);
		}
		for (int j = c + 2; j > c - 2; --j) {
			coords.set(0, j);
			field.set(coords, conductor);
		}
		for (int i = r + 1; i > r - 2; --i) {
			coords.set(1, i);
			field.set(coords, conductor);
		}

		coords.set(1, r + 2);
		coords.set(0, c);
		field.set(coords, conductor);


		coords.set(1, r - 2);
		coords.set(0, c);
		field.set(coords, conductor);


		for (int j = c - 2; j < c; ++j) {
			coords.set(1, r + 3);
			coords.set(0, j);
			field.set(coords, conductor);


			coords.set(1, r - 3);
			coords.set(0, j);
			field.set(coords, conductor);
		}
		coords.set(1, r);
		coords.set(0, c + 3);
		field.set(coords, conductor);

		coords.set(1, r);
		coords.set(0, c + 4);
		field.set(coords, conductor);

	}

	void construct_or(Field& field, int r, int c) {
		multi_index_type coords;
		coords.set(1, r);
		coords.set(0, c);
		field.set(coords, conductor);

		coords.set(0, c + 1);
		for (int i = r - 1; i < r + 2; ++i) {
			coords.set(1, i);
			field.set(coords, conductor);
		}

		for (int j = c - 1; j < c + 1; ++j) {
			coords.set(1, r - 2);
			coords.set(0, c - 1);
			field.set(coords, conductor);

			coords.set(1, r + 2);
			coords.set(0, c - 1);
			field.set(coords, conductor);

		}

		coords.set(1, r + 2);
		coords.set(0, c);
		field.set(coords, conductor);

		coords.set(1, r - 2);
		coords.set(0, c);
		field.set(coords, conductor);


		coords.set(1, r);
		coords.set(0, c + 2);
		field.set(coords, conductor);

		coords.set(1, r);
		coords.set(0, c + 3);
		field.set(coords, conductor);


	}

	void construct_and(Field& field, int r, int c) {
		construct_h_wire(field, r, c, c + 8);
		construct_h_wire(field, r - 3, c, c + 1);

		construct_h_wire(field, r - 1, c + 9, c + 11);

		construct_v_wire(field, c + 12, r - 4, r - 2);

		construct_h_wire(field, r - 3, c + 5, c + 7);

		construct_h_wire(field, r - 4, c + 8, c + 10);

		multi_index_type coords;

		coords.set(1, r - 4);
		coords.set(0, c + 9);
		field.set(coords, empty);


		construct_h_wire(field, r - 6, c + 12, c + 13);

		construct_v_wire(field, c + 2, r - 6, r - 4);

		construct_v_wire(field, c + 4, r - 6, r - 4);

		construct_v_wire(field, c + 6, r - 4, r - 2);

		construct_v_wire(field, c + 10, r - 6, r - 4);

		coords.set(1, r - 7);
		coords.set(0, c + 3);
		field.set(coords, conductor);


		coords.set(1, r - 2);
		coords.set(0, c + 8);
		field.set(coords, conductor);


		construct_h_wire(field, r - 5, c + 9, c + 11);

	}

};



#endif