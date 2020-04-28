#include <iostream>
#include "../glui_2.37_x86_msvc2015/include/GL/freeglut.h"
#include "../glui_2.37_x86_msvc2015/include/GL/glut.h"
using namespace std;

void Display_cb() {
	glutSwapBuffers();
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(480, 360);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Test");

	glutDisplayFunc(Display_cb);
	glutMainLoop();
	return 0;
}