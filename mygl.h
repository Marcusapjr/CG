#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "primitives.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

//PutPixel desenha um pixel na tela, recebendo um ponto.
void PutPixel(Point p) {

	if(p.x<0 || p.y<0 || p.x> IMAGE_WIDTH || p.y>IMAGE_HEIGHT){
		return;
	}
    
    FBptr[4*p.x + 4*p.y*IMAGE_WIDTH + 0] = p.color.R;
	FBptr[4*p.x + 4*p.y*IMAGE_WIDTH + 1] = p.color.G;
	FBptr[4*p.x + 4*p.y*IMAGE_WIDTH + 2] = p.color.B;
	FBptr[4*p.x + 4*p.y*IMAGE_WIDTH + 3] = p.color.A;

};

//Função para desenhar uma linha generalizando o algoritimo de Bresenham

void DrawLine(Point v0, Point v1){
	
	int dx = v1.x - v0.x;
	int dy = v1.y - v0.y;
	int diry = 1;
	bool troca = false;

	if ((dy) > abs(dx)){
		troca = true;
		std::swap(v0.x, v0.y);
		std::swap(v1.x, v1.y);
		dx = v1.x - v0.x;
		dy = v1.y - v0.y;
	}

	if (dx<=0){
		DrawLine(v1, v0);
		return;
	}

	if(dy<0){
		dy = -dy;
		diry = -1;
	}
	
	int d = 2* dy - dx; //valor inicial do erro
	int incE = 2* dy;  	 	
	int incNE = 2* (dy-dx);
	int x = v0.x;
	int y = v0.y;

	if(troca){
		PutPixel(Point(y,x, Color(v1.color)));
	}
	else{
		PutPixel(Point(x,y, Color(v0.color))); //Desenha o pixel inicial		
	}

	while(x < v1.x){

		
		if (d <= 0){
			d += incE;
			x++;
		}
		else {
			d += incNE;
			x++;
			y = y + diry;
		}
		if(troca){
			PutPixel(Point(y,x, Color(v1.color)));
		}
		else{
			PutPixel(Point(x,y, Color(v0.color))); //Desenha o proximo pixel

		}
	}

}

void DrawTriangle(Point a, Point b, Point c){
	
	DrawLine(a,b);
	DrawLine(a,c);
	DrawLine(b,c);

}


#endif // _MYGL_H_

