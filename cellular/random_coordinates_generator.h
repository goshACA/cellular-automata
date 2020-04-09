#ifndef RANDOM_COORDINATE_GENERATOR
#define RANDOM_COORDINATE_GENERATOR

#include <algorithm>

template< typename Field, typename multi_index>
class coord_geneartor {
	
public:

	static Field generate_coords(Field& _field, multi_index& _coord) {
		int H = 0, W = 0;
		_field.get_sizes(&H, &W);
		//int count = H * W * 0.05;
		int count = (std::min)(H, W);
		for (int i = 0; i < count; ++i) {
			_coord.set(0, std::rand() % H/4);
			_coord.set(1, std::rand() % W/4);
			_field.set(_coord, true);

			_coord.set(0, std::rand() % (H / 4) + 3 * H / 4);
			_coord.set(1, std::rand() % (W / 4) + 3 * W / 4);
			_field.set(_coord, true);

			_coord.set(0, std::rand() % (H / 4) + 3 * H / 4);
			_coord.set(1, std::rand() % (W / 4) );
			_field.set(_coord, true);

			_coord.set(0, std::rand() % (H / 4));
			_coord.set(1, std::rand() % (W / 4) + 3 * W / 4);
			_field.set(_coord, true);

		/*	_coord.set(0, std::rand() % (H / 4) +  H / 2);
			_coord.set(1, std::rand() % (W / 4) +  W / 2);
			_field.set(_coord, true);*/
			
		}
		return _field;
	}

	
	static Field generate_glider_gun(Field& _field, multi_index& _coord) {
		int H = 0, W = 0;

		_field.get_sizes(&H, &W);
		
		_coord.set(1, H / 4);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);


		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 10);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 10);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 11);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 12);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 13);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 14);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 15);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 16);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 16);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 17);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 16);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 15);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 13);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 12);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 11);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 10);
		_field.set(_coord, true);


		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 20);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 20);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 20);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 21);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 21);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 21);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 22);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 22);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 24);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 24);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 24);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 24);
		_field.set(_coord, true);


		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 34);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 34);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 35);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 35);
		_field.set(_coord, true);

		return _field;
	}

	static Field generate_oscillator_eight(Field& _field, multi_index& _coord) {
		int H = 0, W = 0;

		_field.get_sizes(&H, &W);

		_coord.set(1, H / 4);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 3);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);


		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		

		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 );
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);

		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 2);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 2);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4);
		_field.set(_coord, true);

		return _field;


	}

	static Field generate_oscillator_clock_four(Field& _field, multi_index& _coord) {
	
		int H = 0, W = 0;

		_field.get_sizes(&H, &W);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 1);
		_field.set(_coord, true);

		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 2);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 1);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 8);
		_field.set(_coord, true);

		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 3);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 3);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);

		_coord.set(1, H / 4 - 5);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 6);
		_coord.set(0, W / 4 + 4);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 5);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 6);
		_coord.set(0, W / 4 + 5);
		_field.set(_coord, true);

		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 10);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 10);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 1);
		_coord.set(0, W / 4 + 11);
		_field.set(_coord, true);
		_coord.set(1, H / 4 - 2);
		_coord.set(0, W / 4 + 11);
		_field.set(_coord, true);

		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 6);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 4);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);
		_coord.set(1, H / 4 + 5);
		_coord.set(0, W / 4 + 7);
		_field.set(_coord, true);


		return _field;
	}
	
};





#endif