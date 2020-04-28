#include <iostream>
#include <string.h>
#include <string>
#include "../glui_2.37_x86_msvc2015/include/GL/freeglut.h"
#include "../glui_2.37_x86_msvc2015/include/GL/glut.h"
#include "../Libreria_HighScore/Release/HSSHighscore.h"
using namespace std;
using namespace HS;
void DrawTextInWindows(const char *text, int length, int x, int y)
{
	
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void Display_cb() {
	string textTest;
	textTest = "HighScore";

	DrawTextInWindows(textTest.data(), textTest.size(), 50, 50);

	glutSwapBuffers();
}

int main(int argc, char** argv) 
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Test");


	glutDisplayFunc(Display_cb);
	glutMainLoop();
	return 0;
}