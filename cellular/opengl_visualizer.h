#ifndef OPENGL_VISUALIZER_H
#define OPENGL_VISUALIZER_H
#include <map>

#include "Windows.h"
#include <GL/GL.h>
#include <GL/GLU.h>
#include <Gl/glut.h>
#include "color.h"
#define PI 3.14159265      
/**
* This visualizer paints each cell of specified field individually,
* as simple polygons.
*/
template< typename Field >
class opengl_visualizer
{
public:
	// Type of field, used by the visualizer
	typedef Field field_type;

	typedef typename Field::multi_index_type multi_index_type;
	typedef typename Field::cell_type cell_type;

	void set_colors(const std::map< cell_type, color >& colors_map)
	{
		_colors_map = colors_map;
	}

	// Paints current state of the field
	void visualize()  {
		
		int height = 0, width = 0;
		_field->get_sizes(&height,&width);

		multi_index_type m;
		color draw_color = color(0, 0, 0);
		double w = 0.8, h = 0.8, w_mashtab = 2/(double)width, h_mashtab = 2/(double)height;
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);
		for (int i = 0; i < height; ++i) {
			m.set(0, i);
			for (int j = 0; j < width; ++j) {
				m.set(1, j);
				draw_color = _colors_map[_field->get(m)];
				glColor3b(draw_color.get_red(), draw_color.get_green(), draw_color.get_blue());
				glVertex2d(i*h_mashtab - 1, j*w_mashtab - 1);
				glVertex2d((i + h)*h_mashtab - 1, j*w_mashtab - 1);
				glVertex2d((i + h)*h_mashtab - 1, (j + w)*w_mashtab - 1);
				glVertex2d(i*h_mashtab - 1, (j + w)*w_mashtab - 1);
			};
		}

		glEnd();
		glFlush();
	}




	void draw_hexagon_grid() {

		int height = 0, width = 0;
		_field->get_sizes(&height, &width);
		multi_index_type m;
		color draw_color = color(0, 0, 0);
		double  w = 0.9, h = 0.9, w_mashtab = 2 / (double)width, h_mashtab = 3 / (double)height;
		//glBegin(GL_QUADS);
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < width; ++i) {
			m.set(0, i);
			for (int j = 0; j < height; ++j) {
				m.set(1, j);
				double x = i - w / 2;
				if (j % 2 == 1)
					x = i;
				double  y = j * (3 * h / 4);
				draw_color = _colors_map[_field->get(m)];
				glBegin(GL_POLYGON);
				glColor3b(draw_color.get_red(), draw_color.get_green(), draw_color.get_blue());
				glVertex2d((x - w / 2)*w_mashtab - 1, (y + h / 4)*h_mashtab - 1);
				glVertex2d((x - w / 2)*w_mashtab - 1, (y - h / 4)*h_mashtab - 1);
				glVertex2d(x * w_mashtab - 1, (y - h / 2)*h_mashtab - 1);
				glVertex2d((x + w / 2)*w_mashtab - 1, (y - h / 4)*h_mashtab  - 1);
				glVertex2d((x + w / 2)*w_mashtab - 1, (y + h / 4)*h_mashtab - 1);
				glVertex2d(x * w_mashtab - 1, (y + h / 2)*h_mashtab - 1);
				glEnd();

			}
		}

		
		glFlush();

	}



	void draw_3d() {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-2, 2, -2, 2, -10, 10);

		glMatrixMode(GL_MODELVIEW);

		//  Clear screen and Z-buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		// Reset transformations
		glLoadIdentity();
		//glScaled(1, 1, -1);
		glRotatef(-210, 1, 1, 0);


		double rotate_y = 0;
		double rotate_x = 0; 
		// Other Transformations
		// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
		// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

		// Rotate when user changes rotate_x and rotate_y
		glRotatef(rotate_x, 1.0, 0.0, 0.0);
		glRotatef(rotate_y, 0.0, 1.0, 0.0);

		// Other Transformations
		// glScalef( 2.0, 2.0, 0.0 );          // Not included

		//Multi-colored side - FRONT
		glBegin(GL_POLYGON);

		glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.5, -0.5, 0.5);      // P1 is red
		glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.5, 0.5, 0.5);      // P2 is green
		glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5, 0.5, 0.5);      // P3 is blue
		glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5, -0.5, 0.5);      // P4 is purple

		glEnd();

		// White side - BACK
		glBegin(GL_POLYGON);
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		// Purple side - RIGHT
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glEnd();

		// Green side - LEFT
		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		// Blue side - TOP
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glEnd();

		// Red side - BOTTOM
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		glFlush();
		glutSwapBuffers();
		//glutSwapBuffers();
	}



	void set_field(field_type* field)  {
		_field = field;
	}
private:
		 field_type* _field;

	 std::map<cell_type, color > _colors_map;
};
#endif // OPENGL_VISUALIZER_H
