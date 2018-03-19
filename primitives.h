#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

//Primitivas utilizadas

class Color{
     public:
     
        float R;
        float G;
        float B;
        int A;
    
        Color(float r, float g, float b, float a){
            R = r;
            G = g;
            B = b;
            A = a;
        }
        Color(){
            R = 255;
            G = 255;
            B = 255;
            A = 255;
        }
};

class Point{
    public:
        int x;
        int y;
        Color color;

        Point(){

        }

        Point(int x_, int y_, Color c){
        x = x_;
        y = y_;
        color = c;
        
        }
};

class Line{
    public:
        Point v1;
        Point v2;

        Line(){
            
        }

        Line(Point v1_, Point v2_){
            v1 = v1_;
            v2 = v2_;
        }
};

class Triangle{
    Point v1;
    Point v2;
    Point v3;
};

#endif // _PRIMITIVES_H_
