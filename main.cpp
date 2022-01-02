#include<windows.h>
#include <GL/glut.h>
float angle = 0.10, x=-4;

void home()
{

    glPushMatrix(); //main building
    glColor3f(0.0f, 0.5f, 0.5f);
    glTranslated(0,0.4,0);
    glScaled(2,0.8,1);
    glutSolidCube(1);
    glColor3f(0.0f, 0.5f, 0.5f);
    glPopMatrix();

    glPushMatrix(); //door
    glColor3f(0,0,0);
    glTranslated(0,0.2,0);
    glScaled(0.3,0.4,1);
    glutSolidCube(1);
    glColor3f(0,0,0);
    glutWireCube(0);
    glPopMatrix();

    glPushMatrix(); //main building roof
    glColor3f(0,0,0);
    glTranslated(0,0.8,0);
    glScaled(2,0.02,1);
    glutSolidCube(1);
    glColor3f(0,0,0);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //room on floor
    glColor3f(0.0f, 0.5f, 0.5f);

    glTranslated(0.0,1.1,0.5);
    glScaled(1.4,0.6,1.0);
    glutSolidCube(1);
    glColor3f(0.0f, 0.5f, 0.5f);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //top room roof
    glColor3f(0,0,0);
    glTranslated(0,1.4,0);
    glScaled(2,0.05,1);
    glutSolidCube(1);
    glColor3f(0,0,0);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //top room window
    glColor3f(0,0,0);
    glTranslated(0,1.1,0);
    glScaled(0.4,0.3,1);
    glutSolidCube(1);
    glColor3f(0,0,0);
    glutWireCube(1);
    glPopMatrix();
}

void train()
{
    glPushMatrix(); //Right Wheel Far
    glColor3f(1,1,1);
    glTranslated(0.75,-0.5, -0.5);
    glRotated(angle,0,0,1);
    glutWireTorus (0.1,0.2,10,10);
    glPopMatrix();

    glPushMatrix(); //Left Wheel Far
    glColor3f(1,1,1);
    glTranslated(-0.75,-0.5, -0.5);
    glRotated(angle,0,0,1);
    glutWireTorus (0.1,0.2,10,10);
    glPopMatrix();

    glPushMatrix(); //Train BOX
    glColor3f(0,0,0);
    glScaled(2,1,1);
    glutSolidCube(1);
    glColor3f(0,0,0);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix(); //Train Connection Boxes
    glColor3f(0,0,0);
    glTranslated(1,-0.35,0);
    glScaled(1,0.09,0.09);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix(); //Right Wheel Far
    glColor3f(1,1,1);
    glTranslated(0.75,-0.5, 0.5);
    glRotated(angle,0,0,1);
    glutWireTorus (0.1,0.2,10,10);
    glPopMatrix();

    glPushMatrix(); //Left Wheel Far
    glColor3f(1,1,1);
    glTranslated(-0.75,-0.5, 0.5);
    glRotated(angle,0,0,1);
    glutWireTorus (0.1,0.2,10,10);
    glPopMatrix();

    angle-=0.2;
}

void tree()
{
    glPushMatrix();
    glColor3f(0.3f, 0.2f, 0.2f);
    glScaled(0.2,5.5,0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3b(48,124,66);

    glColor3f(0.0,0.7,0.5);

    glTranslated(0,2,0);
    glutSolidSphere(1,8,8);
    glColor3f(0.0,1.0,0.5);
    glutWireSphere(0,5,5);
    glPopMatrix();
}
void background()
{
    glColor3f(0.24,0.56,0.37);
    glRecti(-3,-2,3,0); //green grass

    glColor3f(0.20,0.60,0.99);
    glRecti(-3,0,3,2); //sky


//small trees
    glPushMatrix();
    glTranslated(1.7,0.6,0);
    glScaled(0.3,0.3,0.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.5,0.8,0);
    glScaled(0.3,0.3,0.1);
    tree();
    glPopMatrix();

    //big trees
    glPushMatrix();
    glTranslated(-1.6,0.4,0);
    glScaled(0.23,0.23,0.1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1.4,0.6,0);
    glScaled(0.23,0.23,0.1);
    tree();
    glPopMatrix();


    home();
}
void renderScene (void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-3,3,-2,2,-4,4);
    background ();
    glRotatef(10,1.0,1.0,0.0); //
    glPushMatrix ();

    glColor3f(0,0,0); //Rail
    glTranslated (0,-0.4,0);
    glScaled (9,0.1,0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(x,0,0); // to move train
    glScaled(0.5,0.5,0.5);

    glPushMatrix();
    glTranslated (-2.4,0,0);
    train();
    glPopMatrix();
    glPushMatrix();
    glTranslated (0,0,0);
    train();
    glPopMatrix();
    glPushMatrix();
    glTranslated (2.4,0,0);
    train();
    glPopMatrix();
    if (x<5)
        x+=0.002; //control train speed from here
    else
        x=-5;


    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition (10,10);
    glutInitWindowSize (1500,700);
    glutCreateWindow("Home");
    glutDisplayFunc(renderScene);
    glutIdleFunc (renderScene);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return 0;
}
