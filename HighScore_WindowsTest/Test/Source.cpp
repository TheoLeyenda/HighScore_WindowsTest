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

	DrawTextInWindows(textTest.data(), textTest.size(), 320, 530);

	for(int i = 0; i < listSize; i++)
	{
		string text1 = returnRankEntry(i).name.c_str();
		string text2 = " ";
		
		string text3;
		text3 = to_string(returnRankEntry(i).score);
		textTest = text1 + text2 + text3;
		DrawTextInWindows(textTest.data(), textTest.size(), 120, 530 - ((i+1)*25));

	}

	glutSwapBuffers();
}

int main(int argc, char** argv) 
{
	initList();
	ScoreEntry score1;
	ScoreEntry score2;
	ScoreEntry score3;
	ScoreEntry score4;
	ScoreEntry score5;

	score1.name = "Sergio Baretto (Apruebame por favor)";
	score1.score = 99999999;

	score2.name = "Matias Karplus (Ta piola tu libreria :D)";
	score2.score = 90000000;

	score3.name = "Theo Leyenda";
	score3.score = 10000000;

	score4.name = "Ivan Castellano";
	score4.score = 9500000;

	score5.name = "Cristian Cuzumano";
	score5.score = 9000000;


	ScoreEntry scoreEnemy[]{score1,score2, score3, score4, score5};
	
	for(int i = 0; i < listSize; i++)
	{
		insertSort(scoreEnemy[i]);
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Test");

	
	glutDisplayFunc(Display_cb);
	glutMainLoop();
	return 0;
}