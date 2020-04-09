#include <iostream>
#include "multi_index.h"
#include "matrix_field.h"
#include "bst_field.h"
#include "wireworld_rule.h"
#include "conway_rules.h"
#include "hexagon_rules.h"
#include "rule_34_2.h"
#include "probabilistic_rules.h"
#include "opengl_visualizer.h"
#include "trivial_simulator.h"
#include "circular_simulator.h"
#include "wireworld_simulator.h"
#include "matrix_field_proxy.h"
#include "random_coordinates_generator.h"
#include <vector>
#include <functional>
#include <map>

template <class multi_index_type>
void print(std::vector<multi_index_type> vec) {

	for (int i = 0; i < vec.size(); ++i) {
		std::cout << " x = " << vec[i].get(0) << " y = " << vec[i].get(1);
	}
}


opengl_visualizer<matrix_field<bool>> *_visualizer;
circular_simulator<matrix_field<bool>, conway_rules<matrix_field_proxy<bool>, bool>> *_simulator;
circular_simulator<matrix_field<bool>, hexagon_rules<matrix_field_proxy<bool>, bool>> *hexagon_simulator;
circular_simulator<matrix_field<bool>, probabilistic_rules<matrix_field_proxy<bool>, bool>> *probab_simulator;
circular_simulator<matrix_field<bool>, rule_34_2<matrix_field_proxy<bool>, bool>> *_rule_34_2_simulator;
trivial_simulator<matrix_field<int>, wireworld_rule<matrix_field<int>, int>> *_wireworld_simulator;
opengl_visualizer<matrix_field<int>> *_wireworld_visualizer;

void displayFunction()
{
	_visualizer->visualize();
}

void displayHexagonFunction() {

	_visualizer->draw_hexagon_grid();
}
void displayWireworld() {

	_wireworld_visualizer->visualize();
}


void timerFunction(int value)
{
	_simulator->simulate_circular_iteration();
	glutPostRedisplay();
	glutTimerFunc(100, &timerFunction, value);
}
void timerProbabFunction(int value)
{
	probab_simulator->simulate_circular_iteration();
	glutPostRedisplay();
	glutTimerFunc(100, &timerProbabFunction, value);
}

void timer34_2Function(int value)
{
	_rule_34_2_simulator->simulate_circular_iteration();
	glutPostRedisplay();
	glutTimerFunc(100, &timer34_2Function, value);
}

void timerHexagonFunction(int value)
{
	hexagon_simulator->simulate_circular_iteration();
	glutPostRedisplay();
	glutTimerFunc(100, &timerHexagonFunction, value);
}
void timerWireworldFunction(int value)
{
	_wireworld_simulator->simulate_simple_iteration();
	glutPostRedisplay();
	glutTimerFunc(100, &timerWireworldFunction, value);
}


int main(int argc, char** argv) {

	const int W = 100, H = 100;


	int number;
	std::cin >> number;
	matrix_field<bool> m_field(W, H, false);
	std::map<bool, color> color_map;
	color_map[true] = color(0, 0, 0);
	color_map[false] = color(100, 100, 100);
	multi_index<2> coords;
	coord_geneartor<matrix_field<bool>, multi_index<2>>::generate_coords(m_field, coords);
	//HEXAGON RULES
	if (number == 4) {
		hexagon_rules<matrix_field_proxy<bool>, bool> hex_rules;

		hex_rules.set_alive(true);
		hex_rules.set_dead(false);

		circular_simulator<matrix_field<bool>, hexagon_rules<matrix_field_proxy<bool>, bool>> hex_simulator(&m_field, &hex_rules);
		hexagon_simulator = &hex_simulator;
		matrix_field<bool>* hex_field_copy = hex_simulator.get_field();

		int height = 0;
		int width = 0;
		m_field.get_sizes(&height, &width);

		opengl_visualizer<matrix_field<bool>> visualizer;
		_visualizer = &visualizer;
		visualizer.set_field(hex_field_copy);
		visualizer.set_colors(color_map);

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Drawing Game of Life");
		glutDisplayFunc(displayHexagonFunction);
		glutTimerFunc(500, &timerHexagonFunction, 123);
		glClearColor(1, 1, 1, 1);
		glClearDepth(1.0f);
		//glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glutMainLoop();
	}

	if (number == 1) {
		conway_rules<matrix_field_proxy<bool>, bool> con_rules;

		con_rules.set_alive(true);
		con_rules.set_dead(false);

		circular_simulator<matrix_field<bool>, conway_rules<matrix_field_proxy<bool>, bool>> conway_simulator(&m_field, &con_rules);
		_simulator = &conway_simulator;
		matrix_field<bool>* con_field_copy = conway_simulator.get_field();


		opengl_visualizer<matrix_field<bool>> visualizer;
		_visualizer = &visualizer;
		visualizer.set_field(con_field_copy);
		visualizer.set_colors(color_map);

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Drawing Game of Life");
		glutDisplayFunc(displayFunction);
		glutTimerFunc(500, &timerFunction, 123);
		glClearColor(1, 1, 1, 1);
		glClearDepth(1.0f);
		//glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glutMainLoop();
	}

	//RULE 34_2
	if (number == 2) {
		rule_34_2<matrix_field_proxy<bool>, bool> rule_34;

		rule_34.set_alive(true);
		rule_34.set_dead(false);

		circular_simulator<matrix_field<bool>, rule_34_2<matrix_field_proxy<bool>, bool>> rule_34_simulator(&m_field, &rule_34);
		_rule_34_2_simulator = &rule_34_simulator;
		matrix_field<bool>* rule_34_field_copy = rule_34_simulator.get_field();


		opengl_visualizer<matrix_field<bool>> visualizer;
		_visualizer = &visualizer;
		visualizer.set_field(rule_34_field_copy);
		visualizer.set_colors(color_map);

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Drawing Game of Life");
		glutDisplayFunc(displayFunction);
		glutTimerFunc(500, &timer34_2Function, 123);
		glClearColor(1, 1, 1, 1);
		glClearDepth(1.0f);
		//glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glutMainLoop();
	}
	//PROBABILISTIC RULE
	if (number == 3) {
		probabilistic_rules <matrix_field_proxy<bool>, bool> prob_rules;

		prob_rules.set_alive(true);
		prob_rules.set_dead(false);
		prob_rules.set_probability(0.006);

		circular_simulator<matrix_field<bool>, probabilistic_rules<matrix_field_proxy<bool>, bool>> prob_simulator(&m_field, &prob_rules);
		probab_simulator = &prob_simulator;
		matrix_field<bool>* prob_field_copy = prob_simulator.get_field();

		opengl_visualizer<matrix_field<bool>> visualizer;
		_visualizer = &visualizer;
		visualizer.set_field(prob_field_copy);
		visualizer.set_colors(color_map);
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Drawing Game of Life");
		glutDisplayFunc(displayFunction);
		glutTimerFunc(500, &timerProbabFunction, 123);
		glClearColor(1, 1, 1, 1);
		glClearDepth(1.0f);
		//glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glutMainLoop();
	}


	if (number > 4) {
		matrix_field<int> m_field(W, H, 0);
		multi_index<2> coords;
		std::map<int, color>  color_map;
		color_map[0] = color(120, 120, 120);
		color_map[1] = color(0, 0, 127);
		color_map[2] = color(127, 0, 0);
		color_map[3] = color(110, 110, 0);

		wireworld_simulator<matrix_field<int>, int> wireworld_generalize_coords;


		//OR 1 0
		if (number == 5) {
			wireworld_generalize_coords.construct_or(m_field, 50, 50);
			wireworld_generalize_coords.construct_h_wire(m_field, 48, 30, 48);
			wireworld_generalize_coords.construct_h_wire(m_field, 52, 30, 48);
			wireworld_generalize_coords.construct_h_wire(m_field, 50, 54, 60);

			coords.set(1, 48);
			coords.set(0, 30);
			m_field.set(coords, 1);
		}

		//XOR 1 0
		if (number == 6) {
			wireworld_generalize_coords.construct_xor(m_field, 23, 20);
			wireworld_generalize_coords.construct_h_wire(m_field, 26, 15, 19);
			wireworld_generalize_coords.construct_h_wire(m_field, 20, 15, 19);
			wireworld_generalize_coords.construct_h_wire(m_field, 23, 25, 30);

			coords.set(1, 26);
			coords.set(0, 15);
			m_field.set(coords, 1);
		}
		//XOR 1 1
		if (number == 7) {
			wireworld_generalize_coords.construct_xor(m_field, 23, 20);
			wireworld_generalize_coords.construct_h_wire(m_field, 26, 15, 19);
			wireworld_generalize_coords.construct_h_wire(m_field, 20, 15, 19);
			wireworld_generalize_coords.construct_h_wire(m_field, 23, 25, 30);

			coords.set(1, 26);
			coords.set(0, 15);
			m_field.set(coords, 1);

			coords.set(1, 20);
			coords.set(0, 15);
			m_field.set(coords, 1);
		}

		//AND  1 1
		if (number == 8) {
			wireworld_generalize_coords.construct_and(m_field, 55, 40);
			wireworld_generalize_coords.construct_h_wire(m_field, 55, 30, 39);
			wireworld_generalize_coords.construct_h_wire(m_field, 52, 30, 39);
			wireworld_generalize_coords.construct_h_wire(m_field, 49, 54, 60);

			coords.set(1, 55);
			coords.set(0, 30);
			m_field.set(coords, 1);

			coords.set(1, 52);
			coords.set(0, 30);
			m_field.set(coords, 1);

		}
		//AND 1 0
		if (number == 9) {
			wireworld_generalize_coords.construct_and(m_field, 55, 40);
			wireworld_generalize_coords.construct_h_wire(m_field, 55, 30, 39);
			wireworld_generalize_coords.construct_h_wire(m_field, 52, 30, 39);
			wireworld_generalize_coords.construct_h_wire(m_field, 49, 54, 60);

			coords.set(1, 55);
			coords.set(0, 30);
			m_field.set(coords, 1);
		}



		wireworld_rule<matrix_field<int>, int> wireworld_r;
		trivial_simulator<matrix_field<int>, wireworld_rule<matrix_field<int>, int>> wireworld_sim((&m_field), &wireworld_r);
		_wireworld_simulator = &wireworld_sim;

		matrix_field<int>* wireworld_board = wireworld_sim.get_field();

		opengl_visualizer<matrix_field<int>> visualizer;
		_wireworld_visualizer = &visualizer;
		visualizer.set_field(wireworld_board);
		visualizer.set_colors(color_map);
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Drawing Game of Life");
		glutDisplayFunc(displayWireworld);
		glutTimerFunc(500, &timerWireworldFunction, 123);
		glClearColor(1, 1, 1, 1);
		glClearDepth(1.0f);
		//glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glutMainLoop();
	}

	system("pause");
}