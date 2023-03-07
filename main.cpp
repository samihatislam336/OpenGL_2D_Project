#include<windows.h>
#include <GL/glut.h>
#include<MMSystem.h>
#include<math.h>

# define PI           3.1416

float p = -1.0;
float x=0.0;
float y=.5;
float rainx=0.0;
float rainy=0.0;
float shipx=0.0;

static float	tx	=  0.0;
static float	ty	=  0.0;


void Initialize( )
{
glClearColor(0.0, 0.0, 0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, -1.0);
}



    void sun ()
    {
        //sun
        glColor3ub(255, 165, 0);

        int k;
        GLfloat x1=-1.5; GLfloat y1=1.5;GLfloat radius = 0.15;
        int triangleAmount = 50; //# of triangles used to draw circle


        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x1 + (radius * cos(k *  twicePi / triangleAmount)),
			    y1 + (radius * sin(k * twicePi / triangleAmount))
			);
		}
            glEnd();

    }

    void clouds ()
    {
        int k;
        int triangleAmount = 50;
        GLfloat twicePi = 2.0f * PI;


        glColor3ub(245, 245, 245);
        GLfloat radius = 0.3;
        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x-1.85, y+0.45); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x-1.85 + (radius * cos(k *  twicePi / triangleAmount)),
			    y+0.45 + (radius * sin(k * twicePi / triangleAmount))
			);
		}
            glEnd();



        glColor3ub(245, 245, 245);
        //x=-.6;  y=.9;

        ///GLfloat x=-.5; GLfloat y=.5;
        radius = 0.3;


        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x-1.75, y+0.2); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            (x - 1.75) + (radius * cos(k *  twicePi / triangleAmount)),
			    (y + 0.2) + (radius * sin(k * twicePi / triangleAmount))
			);
		}
            glEnd();

         glColor3ub(245, 245, 245);
        //x=-.45;  y=.75;
        radius = 0.3;


        glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x-1.45, y+0.4); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x-1.45 + (radius * cos(k *  twicePi / triangleAmount)),
			    y+0.4 + (radius * sin(k * twicePi / triangleAmount))
			);
		}
            glEnd();


        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-2,rainy+0.6);
        glVertex2f(rainx-1.95, rainy+0.25 );
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-1.75, rainy+0.3 );
        glVertex2f(rainx-1.7,rainy+0);
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-2, rainy+0.1 );
        glVertex2f(rainx-1.95,rainy-0.2);
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-1.45, rainy+0.3 );
        glVertex2f(rainx-1.4,rainy+0);
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-1.25, rainy+0.5);
        glVertex2f(rainx-1.2,rainy+0.2);
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-1.2, rainy-0.1);
        glVertex2f(rainx-1.15,rainy-0.4);
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-1.6, rainy-0.2 );
        glVertex2f(rainx-1.55,rainy-0.5);
        glEnd();

        glColor3ub(255, 255, 255);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glVertex2f(rainx-1.85, rainy-0.25 );
        glVertex2f(rainx-1.8,rainy-0.55);
        glEnd();

    }



    void spe_key(int key, int x, int y)
{

	switch (key)
	{

		case GLUT_KEY_LEFT:
				tx -=0.1;
				if(tx<-3.4)
                {
                    tx=2.8;
                }
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=0.1;
				if(tx>=2)
                {
                    tx=-3.5;
                }
				glutPostRedisplay();
				break;
        default:
                break;
	}
}

     void timer(int)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60, timer, 0);


        if (x > -2)
        {
            x += 0.005;
            if (x >4.0 )
            {
                x += -3.805;
            }

        }


          if (rainx > -2)
            {
            rainx += 0.005;

            if (rainx > 4.0 )
                rainx += -3.805;
            }

            if (rainy > -0.55)
            {
            rainy -= 0.06 ;

        if (rainy < -0.55 )
        {
            rainy = 0;


        }
            }
    }





    void ship()
    {
//brown
glBegin(GL_QUADS);
glColor3ub(139,26,26);
glVertex2f(0.5,-1.3);
glVertex2f(1.45,-1.3);
glVertex2f(1.35,-1.6);
glVertex2f(0.6,-1.6);
glEnd();

//black
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(0.58,-1.55);
glVertex2f(1.37,-1.55);
glVertex2f(1.35,-1.6);
glVertex2f(0.6,-1.6);
glEnd();

//wave
glBegin(GL_QUADS);
glColor3ub(100,149,237);
glVertex2f(0.5,-1.63);
glVertex2f(1.45,-1.63);
glVertex2f(1.35,-1.6);
glVertex2f(0.6,-1.6);
glEnd();


//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(0.7,-1.5);
glVertex2f(0.8,-1.5);
glVertex2f(0.8,-1.35);
glVertex2f(0.7,-1.35);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(1.1,-1.5);
glVertex2f(1.2,-1.5);
glVertex2f(1.2,-1.35);
glVertex2f(1.1,-1.35);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(0.85,-1.5);
glVertex2f(1.05,-1.5);
glVertex2f(1.05,-1.35);
glVertex2f(0.85,-1.35);
glEnd();


//grey
glBegin(GL_QUADS);
glColor3ub(163,163,163);
glVertex2f(0.65,-1.05);
glVertex2f(1.3,-1.05);
glVertex2f(1.3,-1.3);
glVertex2f(0.65,-1.3);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(0.7,-1.25);
glVertex2f(0.9,-1.25);
glVertex2f(0.9,-1.1);
glVertex2f(0.7,-1.1);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(1.1,-1.25);
glVertex2f(1.2,-1.25);
glVertex2f(1.2,-1.1);
glVertex2f(1.1,-1.1);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(0.95,-1.25);
glVertex2f(1.05,-1.25);
glVertex2f(1.05,-1.1);
glVertex2f(0.95,-1.1);
glEnd();

//light grey
glBegin(GL_QUADS);
glColor3ub(189,189,189);
glVertex2f(0.75,-0.8);
glVertex2f(1.2,-0.8);
glVertex2f(1.2,-1.05);
glVertex2f(0.75,-1.05);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(0.85,-1.0);
glVertex2f(0.95,-1.0);
glVertex2f(0.95,-0.85);
glVertex2f(0.85,-0.85);
glEnd();

//window
glBegin(GL_QUADS);
glColor3ub(255,255,224);
glVertex2f(1,-1.0);
glVertex2f(1.1,-1.0);
glVertex2f(1.1,-0.85);
glVertex2f(1,-0.85);
glEnd();

//pillar1
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(0.81,-0.8);
glVertex2f(0.86,-0.8);
glVertex2f(0.86,-0.65);
glVertex2f(0.81,-0.65);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,26,26);
glVertex2f(0.8,-0.60);
glVertex2f(0.87,-0.60);
glVertex2f(0.87,-0.65);
glVertex2f(0.8,-0.65);
glEnd();

//pillar2
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(0.9,-0.8);
glVertex2f(.95,-0.8);
glVertex2f(.95,-0.65);
glVertex2f(0.9,-0.65);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,26,26);
glVertex2f(0.89,-0.60);
glVertex2f(0.96,-0.60);
glVertex2f(0.96,-0.65);
glVertex2f(0.89,-0.65);
glEnd();

//pillar3
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(1.0,-0.8);
glVertex2f(1.05,-0.8);
glVertex2f(1.05,-0.65);
glVertex2f(1.0,-0.65);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,26,26);
glVertex2f(0.99,-0.60);
glVertex2f(1.06,-0.60);
glVertex2f(1.06,-0.65);
glVertex2f(0.99,-0.65);
glEnd();

//pillar4
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(1.09,-0.8);
glVertex2f(1.14,-0.8);
glVertex2f(1.14,-0.65);
glVertex2f(1.09,-0.65);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,26,26);
glVertex2f(1.08,-0.60);
glVertex2f(1.15,-0.60);
glVertex2f(1.15,-0.65);
glVertex2f(1.08,-0.65);
glEnd();

}

void mountains ()
{
    //mountain1
glBegin(GL_TRIANGLES);
glColor3ub(34,139,34);
glVertex2f(-0.5,0);
glVertex2f(0.5,0);
glVertex2f(0,1);
glEnd();

//mountain2
glBegin(GL_TRIANGLES);
glColor3ub(34,139,34);
glVertex2f(0.5,0);
glVertex2f(1,0);
glVertex2f(0.75,0.5);
glEnd();

//mountain3
glBegin(GL_TRIANGLES);
glColor3ub(34,139,34);
glVertex2f(-0.5,0);
glVertex2f(-1,0);
glVertex2f(-0.75,0.5);
glEnd();

//mountain4
glBegin(GL_TRIANGLES);
glColor3ub(34,139,34);
glVertex2f(2,0);
glVertex2f(1,0);
glVertex2f(1.5,0.8);
glEnd();

//mountain5
glBegin(GL_TRIANGLES);
glColor3ub(34,139,34);
glVertex2f(-2,0);
glVertex2f(-1,0);
glVertex2f(-1.5,0.8);
glEnd();

}

void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_QUADS);
glColor3ub(173,216,230);
glVertex2f(-2,0);
glVertex2f(2,0);
glVertex2f(2,2);
glVertex2f(-2,2);
glEnd();



//sea
glBegin(GL_QUADS);
glColor3ub(65,105,225);
glVertex2f(-2,0);
glVertex2f(2,0);
glVertex2f(2,-2);
glVertex2f(-2,-2);
glEnd();


//mountain1
glBegin(GL_TRIANGLES);
glColor3ub(50,205,50);
glVertex2f(-0.5,0);
glVertex2f(0.5,0);
glVertex2f(0,1);
glEnd();

//mountain2
glBegin(GL_TRIANGLES);
glColor3ub(50,205,50);
glVertex2f(0.5,0);
glVertex2f(1,0);
glVertex2f(0.75,0.5);
glEnd();

//mountain3
glBegin(GL_TRIANGLES);
glColor3ub(50,205,50);
glVertex2f(-0.5,0);
glVertex2f(-1,0);
glVertex2f(-0.75,0.5);
glEnd();

//mountain4
glBegin(GL_TRIANGLES);
glColor3ub(50,205,50);
glVertex2f(2,0);
glVertex2f(1,0);
glVertex2f(1.5,0.8);
glEnd();

//mountain5
glBegin(GL_TRIANGLES);
glColor3ub(50,205,50);
glVertex2f(-2,0);
glVertex2f(-1,0);
glVertex2f(-1.5,0.8);
glEnd();

sun();
glPushMatrix();
//glutPostRedisplay();
glTranslatef(-0.35,0,0);
mountains();
glPopMatrix();

glPushMatrix();
glutPostRedisplay();
glTranslatef(tx,ty,0);
ship();
glPopMatrix();


clouds();

glPushMatrix();
glTranslatef(-1.75,0.45,0);
clouds();
glPopMatrix();

glPushMatrix();
glTranslatef(2,0.3,0);
clouds();
glPopMatrix();



glutSwapBuffers();

}






int main(int iArgc , char** cppArgv)
{

glutInit(&iArgc , cppArgv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


glutInitWindowSize(1000,600);
glutInitWindowPosition(200,200);
glutCreateWindow("Sunshower");


Initialize();


glutDisplayFunc(Draw);
glutSpecialFunc(spe_key);
glutTimerFunc(1000,timer,0);
sndPlaySound("D:\\MIST\\L4T2\\Graphics Lab\\sun\\rain-07.wav",SND_ASYNC); ///Add path to the sound track
glutMainLoop();


return 0;
}
