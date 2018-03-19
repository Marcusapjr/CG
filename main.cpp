#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
//inicializa cores
	Color red   (255, 0, 0, 255);
	Color green (0, 255, 0, 255);
	Color blue  (0, 0, 255, 255);

//inicializa pontos
	Point p0 (256, 256, red);
	Point p1 (  0,   0, red);
	Point p2 (256,   0, blue);
	Point p3 (511,   0, green);
	Point p4 (  0, 256, red);
	Point p5 (511, 256, green);
	Point p6 (  0, 511, blue);
	Point p7 (256, 511, blue);
	Point p8 (511, 511, green);

	Point pr(rand()%511, rand()%511, Color(rand()%255, rand()%255, rand()%255, 255));

	Point pt1(100, 100, green);
	Point pt2(150, 200, blue);
	Point pt3(400, 350, red);
	
	

	//Desenhando linhas
//	DrawLine(p0, p1); //ok
//	DrawLine(p0, p2); //problemas
//	DrawLine(p0, p3); //problmea
//	DrawLine(p0, p4); //ok
//	DrawLine(p0, p5); //ok
//	DrawLine(p0, p6); //ok
//	DrawLine(p0, p7); //ok
	//DrawLine(p0, p8); //ok

	//DrawLine(p0,pr);

	
	
	

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

