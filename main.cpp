#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define GL_PI 3.1416f

void init(void);
void display(void);
void reshape(int,int);

void f_polar(void);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(1.0,1.0,0.0,0.0);  //parametros: rojo, amarillo, azul, el cuarto es el parametro alpha
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    f_polar();
    glPopMatrix();
    glFlush();
}
void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void f_polar(void)
{
    float ang, tope=4*GL_PI, delta=200,radio=2.0, x,y;
    glBegin(GL_LINE_STRIP);
    for (ang = 0.0f; ang < tope; ang += tope/delta)
    {
        //radio=2.0+4.0*sin(ang); = 2 + 4 sen θ
     //   int n = -5;
    //    while(n < 6){
            radio=2+4*sin(ang);//n*cos(ang) + cos(5*ang); //sin(ang)+pow(sin(2.5*ang),3);//3-3*sin(ang);//2+4*sin(ang);
            x = radio * cos(ang);
            y = radio * sin(ang);
            glVertex2f(x,y);
      //      n++;
      //  }
    }
    glEnd();
}
