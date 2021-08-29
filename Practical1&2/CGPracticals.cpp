#include "CGPracticals.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <dos.h>
#include <amp_graphics.h>

namespace p1 {
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };  /* Red diffuse light. */
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };  /* Infinite light location. */
    GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
      {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
      {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
    GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
      {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
      {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
    GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

    void drawBox(void)
    {
        int i;

        for (i = 0; i < 6; i++) {
            glBegin(GL_QUADS);
            glNormal3fv(&n[i][0]);
            glVertex3fv(&v[faces[i][0]][0]);
            glVertex3fv(&v[faces[i][1]][0]);
            glVertex3fv(&v[faces[i][2]][0]);
            glVertex3fv(&v[faces[i][3]][0]);
            glEnd();
        }
    }

    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawBox();
        glutSwapBuffers();
    }

    void init(void)
    {
        /* Setup cube vertex data. */
        v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
        v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
        v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
        v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
        v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
        v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

        /* Enable a single OpenGL light. */
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);

        /* Use depth buffering for hidden surface elimination. */
        glEnable(GL_DEPTH_TEST);

        /* Setup the view of the cube. */
        glMatrixMode(GL_PROJECTION);
        gluPerspective( /* field of view in degree */ 40.0,
            /* aspect ratio */ 1.0,
            /* Z near */ 1.0, /* Z far */ 10.0);
        glMatrixMode(GL_MODELVIEW);
        gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
            0.0, 0.0, 0.0,      /* center is at (0,0,0) */
            0.0, 1.0, 0.);      /* up is in positive Y direction */

          /* Adjust cube position to be asthetic angle. */
        glTranslatef(0.0, 0.0, -1.0);
        glRotatef(60, 1.0, 0.0, 0.0);
        glRotatef(-20, 0.0, 0.0, 1.0);
    }

    void main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutCreateWindow("red 3D lighted cube");
        glutDisplayFunc(display);
        init();
        glutMainLoop();
    }
}
namespace p2 {
	void init()
	{
		// Set display window color to as glClearColor(R,G,B,Alpha)
		glClearColor(0.5, 0.9, 0.4, 0.0);
		// Set projection parameters.
		glMatrixMode(GL_PROJECTION);
		// Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
		gluOrtho2D(0.0, 800, 0.0, 600);
	}
	void home()
	{
		//Roof
		glClear(GL_COLOR_BUFFER_BIT);     // Clear display window
		// Set line segment color as glColor3f(R,G,B)
		glColor3f(0.3, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2i(200, 500);
		glVertex2i(600, 500);
		glVertex2i(700, 350);
		glVertex2i(300, 350);
		glEnd();
		// Top of Front Wall
		glColor3f(0.1, 0.5, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex2i(200, 500);
		glVertex2i(100, 350);
		glVertex2i(300, 350);
		glEnd();
		// Front Wall
		glColor3f(0.7, 0.2, 0.3);
		glBegin(GL_POLYGON);
		glVertex2i(100, 350);
		glVertex2i(300, 350);
		glVertex2i(300, 100);
		glVertex2i(100, 100);
		glEnd();
		// Front Door
		glColor3f(0.7, 0.2, 0.9);
		glBegin(GL_POLYGON);
		glVertex2i(150, 250);
		glVertex2i(250, 250);
		glVertex2i(250, 100);
		glVertex2i(150, 100);
		glEnd();

		// Front Door Lock
		glColor3f(0.3, 0.7, 0.9);
		glPointSize(15);
		glBegin(GL_POINTS);
		glVertex2i(170, 170);
		glEnd();
		//side Wall
		glColor3f(0.1, 0.2, 0.3);
		glBegin(GL_POLYGON);
		glVertex2i(300, 350);
		glVertex2i(700, 350);
		glVertex2i(700, 100);
		glVertex2i(300, 100);
		glEnd();
		// window one
		glColor3f(0.2, 0.4, 0.3);
		glBegin(GL_POLYGON);
		glVertex2i(330, 320);
		glVertex2i(450, 320);
		glVertex2i(450, 230);
		glVertex2i(330, 230);
		glEnd();
		// line of window one
		glColor3f(0.1, 0.7, 0.5);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex2i(390, 320);
		glVertex2i(390, 230);
		glVertex2i(330, 273);
		glVertex2i(450, 273);
		glEnd();
		// window two
		glColor3f(0.2, 0.4, 0.3);
		glBegin(GL_POLYGON);
		glVertex2i(530, 320);
		glVertex2i(650, 320);
		glVertex2i(650, 230);
		glVertex2i(530, 230);
		glEnd();
		// lines of window two
		glColor3f(0.1, 0.7, 0.5);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex2i(590, 320);
		glVertex2i(590, 230);
		glVertex2i(530, 273);
		glVertex2i(650, 273);
		glEnd();
		// Entrance Path
		glColor3f(0.3, 0.5, 0.7);
		glLineWidth(3);
		glBegin(GL_POLYGON);
		glVertex2i(150, 100);
		glVertex2i(250, 100);
		glVertex2i(210, 0);
		glVertex2i(40, 0);
		glEnd();
		// Process all OpenGL routines as quickly as possible
		glFlush();
	}
	void main(int argc, char** argv)
	{
		// Initialize GLUT
		glutInit(&argc, argv);
		// Set display mode
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		// Set top - left display window position.
		glutInitWindowPosition(100, 100);
		// Set display window width and height
		glutInitWindowSize(800, 600);
		// Create display window with the given title
		glutCreateWindow("2D House in OpenGL ");
		// Execute initialization procedure
		init();
		// Send graphics to display window
		glutDisplayFunc(home);
		// Display everything and wait.
		glutMainLoop();
	}
}
namespace p22 {
	/* ASCII code for the escape key. */
#define ESCAPE 27

	GLint window;
	GLint window2;
	GLint Xsize = 1000;
	GLint Ysize = 800;
	float i, theta;
	GLint nml = 0, day = 1;

	char name3[] = "PROJECT:  3D CAR  ANIMATION";

	GLfloat xt = 0.0, yt = 0.0, zt = 0.0, xw = 0.0;   /* x,y,z translation */
	GLfloat tx = 295, ty = 62;
	GLfloat xs = 1.0, ys = 1.0, zs = 1.0;

	GLfloat xangle = 0.0, yangle = 0.0, zangle = 0.0, angle = 0.0;   /* axis angles */

	GLfloat r = 0, g = 0, b = 1;
	GLint light = 1;
	int count = 1, flg = 1;
	int view = 0;
	int flag1 = 0, aflag = 1;            //to switch car driving mode
	int flag2 = 0, wheelflag = 0;   //to switch fog effect
	GLUquadricObj* t;

	static void SpecialKeyFunc(int Key, int x, int y);

	/* Simple  transformation routine */
	GLvoid Transform(GLfloat Width, GLfloat Height)
	{
		glViewport(0, 0, Width, Height);              /* Set the viewport */
		glMatrixMode(GL_PROJECTION);                  /* Select the projection matrix */
		glLoadIdentity();				/* Reset The Projection Matrix */
		gluPerspective(45.0, Width / Height, 0.1, 100.0);  /* Calculate The Aspect Ratio Of The Window */
		glMatrixMode(GL_MODELVIEW);                   /* Switch back to the modelview matrix */
	}


	/* A general OpenGL initialization function.  Sets all of the initial parameters. */
	GLvoid InitGL(GLfloat Width, GLfloat Height)
	{

		glClearColor(1.0, 1.0, 1.0, 1.0);
		glLineWidth(2.0);              /* Add line width,   ditto */
		Transform(Width, Height); /* Perform the transformation */
		//newly added
		t = gluNewQuadric();
		gluQuadricDrawStyle(t, GLU_FILL);

		glEnable(GL_LIGHTING);

		glEnable(GL_LIGHT0);

		// Create light components
		GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
		GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
		GLfloat position[] = { 1.5f, 1.0f, 4.0f, 1.0f };

		// Assign created components to GL_LIGHT0
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
		glLightfv(GL_LIGHT0, GL_POSITION, position);

	}

	/* The function called when our window is resized  */
	GLvoid ReSizeGLScene(GLint Width, GLint Height)
	{
		if (Height == 0)     Height = 1;                   /* Sanity checks */
		if (Width == 0)      Width = 1;
		Transform(Width, Height);                   /* Perform the transformation */
	}

	void init()
	{
		glClearColor(0, 0, 0, 0);
		glPointSize(5.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 900.0, 0.0, 600.0, 50.0, -50.0);
		glutPostRedisplay(); 		// request redisplay
	}


	/* The main drawing function

	   In here we put all the OpenGL and calls to routines which manipulate
	   the OpenGL state and environment.

	   This is the function which will be called when a "redisplay" is requested.
	*/

	void display_string(int x, int y, const char* string, int font)
	{
		int len, i;
		glColor3f(0.8, 0.52, 1.0);
		glRasterPos2f(x, y);
		len = (int)strlen(string);
		for (i = 0; i < len; i++) {
			if (font == 1)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
			if (font == 2)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
			if (font == 3)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
			if (font == 4)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string[i]);
		}

	}

	void display1(void)
	{

		glClearColor(1.0, 1.0, 0.1, 1.0);
		display_string(180, 540, "NAME OF THE ENGINEERING COLLEGE", 1); //correct cordinate according to name
		display_string(215, 500, name3, 1);
		display_string(390, 470, "HELP", 2);
		display_string(10, 450, "MOUSE", 2);
		display_string(10, 410, "PRESS RIGHT BUTTON FOR MENU", 3);
		display_string(10, 370, "KEYBOARD", 2);
		display_string(10, 340, "X-Y-Z KEYS FOR CORRESPONDING ROTATION", 3);
		display_string(10, 310, "A-S-Q CAR CUSTOM SIZE SELECTION", 3);
		display_string(10, 280, "U-F FOR CAMERA VIEW SETTINGS", 3);
		display_string(10, 250, "USE LEFT ARROW(<-) AND RIGHT ARROW(->) TO MOVE CAR", 3);
		display_string(10, 220, "ESCAPE TO EXIT", 3);
		display_string(250, 150, "PRESS SPACE BAR TO ENTER", 2);
		glutPostRedisplay();
		glutSwapBuffers();

	}

	GLvoid DrawGLScene()
	{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	/* Clear The Screen And The Depth Buffer */
		if (view == 0)
		{
			init();
			display1();
		}
		else
		{
			if (count == 1)
				InitGL(Xsize, Ysize);
			if (aflag == 1)/* Initialize our window. */
				glClearColor(1, 1, 1, 1);
			else
				glClearColor(0.1, 0.1, 0.1, 0);
			glPushMatrix();
			glLoadIdentity();
			glTranslatef(-1.0, 0.0, -3.5);
			glRotatef(xangle, 1.0, 0.0, 0.0);
			glRotatef(yangle, 0.0, 1.0, 0.0);
			glRotatef(zangle, 0.0, 0.0, 1.0);
			glTranslatef(xt, yt, zt);
			glScalef(xs, ys, zs);
			glEnable(GL_COLOR_MATERIAL);
			glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

			if (flag2 == 1)
			{
				GLfloat fogcolour[4] = { 1.0,1.0,1.0,1.0 };

				glFogfv(GL_FOG_COLOR, fogcolour);              /* Define the fog colour */
				glFogf(GL_FOG_DENSITY, 0.1);                   /* How dense */
				glFogi(GL_FOG_MODE, GL_EXP);                   /* exponential decay */
				glFogf(GL_FOG_START, 3.0);                   /* Where wwe start fogging */
				glFogf(GL_FOG_END, 100.0);                       /* end */
				glHint(GL_FOG_HINT, GL_FASTEST);              /* compute per vertex */
				glEnable(GL_FOG);/* ENABLE */
			}
			if (flag2 == 0)
			{
				glDisable(GL_FOG);
			}

			if (!aflag) {
				glBegin(GL_POINTS);
				glColor3f(1, 1, 1);
				glPointSize(200.0);
				int ccount = 0;
				float x = 10, y = 10;
				while (ccount < 20)
				{
					glVertex2f(x, y);
					x += 10;
					y += 10;
					if (y > Ysize) y -= 10;
					if (x > Xsize) x -= 10;
					ccount++;
				}
				glEnd();
			}

			glColor3f(1.0, .75, 0.0);
			glPointSize(30.0);
			glBegin(GL_POINTS);
			glVertex3f(0.2, 0.3, 0.3);
			glVertex3f(0.2, 0.3, 0.5);
			glEnd();
			glPointSize(200.0);



			glBegin(GL_QUADS);                /* OBJECT MODULE*/

			/* top of cube*/
			//************************FRONT BODY****************************************
			glColor3f(r, g, b);
			glVertex3f(0.2, 0.4, 0.6);
			glVertex3f(0.6, 0.5, 0.6);
			glVertex3f(0.6, 0.5, 0.2);
			glVertex3f(0.2, 0.4, 0.2);

			/* bottom of cube*/
			glVertex3f(0.2, 0.2, 0.6);
			glVertex3f(0.6, 0.2, 0.6);
			glVertex3f(0.6, 0.2, 0.2);
			glVertex3f(0.2, 0.2, 0.2);

			/* front of cube*/
			glVertex3f(0.2, 0.2, 0.6);
			glVertex3f(0.2, 0.4, 0.6);
			glVertex3f(0.2, 0.4, 0.2);
			glVertex3f(0.2, 0.2, 0.2);

			/* back of cube.*/
			glVertex3f(0.6, 0.2, 0.6);
			glVertex3f(0.6, 0.5, 0.6);
			glVertex3f(0.6, 0.5, 0.2);
			glVertex3f(0.6, 0.2, 0.2);

			/* left of cube*/
			glVertex3f(0.2, 0.2, 0.6);
			glVertex3f(0.6, 0.2, 0.6);
			glVertex3f(0.6, 0.5, 0.6);
			glVertex3f(0.2, 0.4, 0.6);

			/* Right of cube */
			glVertex3f(0.2, 0.2, 0.2);
			glVertex3f(0.6, 0.2, 0.2);
			glVertex3f(0.6, 0.5, 0.2);
			glVertex3f(0.2, 0.4, 0.2);
			//****************************************************************************
			glVertex3f(0.7, 0.65, 0.6);
			glVertex3f(0.7, 0.65, 0.2);
			glVertex3f(1.7, 0.65, 0.2);        //top cover
			glVertex3f(1.7, 0.65, 0.6);
			//***************************back guard******************************
			glColor3f(r, g, b);            /* Set The Color To Blue*/
			glVertex3f(1.8, 0.5, 0.6);
			glVertex3f(1.8, 0.5, 0.2);
			glVertex3f(2.1, 0.4, 0.2);
			glVertex3f(2.1, 0.4, 0.6);

			/* bottom of cube*/
			glVertex3f(2.1, 0.2, 0.6);
			glVertex3f(2.1, 0.2, 0.2);
			glVertex3f(1.8, 0.2, 0.6);
			glVertex3f(1.8, 0.2, 0.6);

			/* back of cube.*/
			glVertex3f(2.1, 0.4, 0.6);
			glVertex3f(2.1, 0.4, 0.2);
			glVertex3f(2.1, 0.2, 0.2);
			glVertex3f(2.1, 0.2, 0.6);

			/* left of cube*/
			glVertex3f(1.8, 0.2, 0.2);
			glVertex3f(1.8, 0.5, 0.2);
			glVertex3f(2.1, 0.4, 0.2);
			glVertex3f(2.1, 0.2, 0.2);

			/* Right of cube */
			glVertex3f(1.8, 0.2, 0.6);
			glVertex3f(1.8, 0.5, 0.6);
			glVertex3f(2.1, 0.4, 0.6);
			glVertex3f(2.1, 0.2, 0.6);
			//******************MIDDLE BODY************************************
			glVertex3f(0.6, 0.5, 0.6);
			glVertex3f(0.6, 0.2, 0.6);
			glVertex3f(1.8, 0.2, 0.6);
			glVertex3f(1.8, 0.5, 0.6);

			/* bottom of cube*/
			glVertex3f(0.6, 0.2, 0.6);
			glVertex3f(0.6, 0.2, 0.2);
			glVertex3f(1.8, 0.2, 0.2);
			glVertex3f(1.8, 0.2, 0.6);

			/* back of cube.*/
			glVertex3f(0.6, 0.5, 0.2);
			glVertex3f(0.6, 0.2, 0.2);
			glVertex3f(1.8, 0.2, 0.2);
			glVertex3f(1.8, 0.5, 0.2);
			//*********************ENTER WINDOW**********************************
			glColor3f(0.3, 0.3, 0.3);
			glVertex3f(0.77, 0.63, 0.2);
			glVertex3f(0.75, 0.5, 0.2);        //quad front window
			glVertex3f(1.2, 0.5, 0.2);
			glVertex3f(1.22, 0.63, 0.2);

			glVertex3f(1.27, 0.63, .2);
			glVertex3f(1.25, 0.5, 0.2);        //quad back window
			glVertex3f(1.65, 0.5, 0.2);
			glVertex3f(1.67, 0.63, 0.2);

			glColor3f(r, g, b);
			glVertex3f(0.7, 0.65, 0.2);
			glVertex3f(0.7, 0.5, .2);       //first separation
			glVertex3f(0.75, 0.5, 0.2);
			glVertex3f(0.77, 0.65, 0.2);

			glVertex3f(1.2, 0.65, 0.2);
			glVertex3f(1.2, 0.5, .2);       //second separation
			glVertex3f(1.25, 0.5, 0.2);
			glVertex3f(1.27, 0.65, 0.2);

			glVertex3f(1.65, 0.65, 0.2);
			glVertex3f(1.65, 0.5, .2);     //3d separation
			glVertex3f(1.7, 0.5, 0.2);
			glVertex3f(1.7, 0.65, 0.2);

			glVertex3f(0.75, 0.65, 0.2);
			glVertex3f(0.75, 0.63, 0.2);        //line strip
			glVertex3f(1.7, 0.63, 0.2);
			glVertex3f(1.7, 0.65, 0.2);

			glVertex3f(0.75, 0.65, 0.6);
			glVertex3f(0.75, 0.63, 0.6);        //line strip
			glVertex3f(1.7, 0.63, 0.6);
			glVertex3f(1.7, 0.65, 0.6);

			glColor3f(0.3, 0.3, 0.3);
			glVertex3f(0.77, 0.63, 0.6);
			glVertex3f(0.75, 0.5, 0.6);        //quad front window
			glVertex3f(1.2, 0.5, 0.6);
			glVertex3f(1.22, 0.63, 0.6);

			glVertex3f(1.27, 0.63, .6);
			glVertex3f(1.25, 0.5, 0.6);        //quad back window
			glVertex3f(1.65, 0.5, 0.6);
			glVertex3f(1.67, 0.63, 0.6);

			glColor3f(r, g, b);
			glVertex3f(0.7, 0.65, 0.6);
			glVertex3f(0.7, 0.5, .6);       //first separation
			glVertex3f(0.75, 0.5, 0.6);
			glVertex3f(0.77, 0.65, 0.6);

			glVertex3f(1.2, 0.65, 0.6);
			glVertex3f(1.2, 0.5, .6);       //second separation
			glVertex3f(1.25, 0.5, 0.6);
			glVertex3f(1.27, 0.65, 0.6);

			glVertex3f(1.65, 0.65, 0.6);
			glVertex3f(1.65, 0.5, .6);
			glVertex3f(1.7, 0.5, 0.6);
			glVertex3f(1.7, 0.65, 0.6);
			glEnd();


			//**************************************************************
			glBegin(GL_QUADS);

			/* top of cube*/
			glColor3f(0.3, 0.3, 0.3);
			glVertex3f(0.6, 0.5, 0.6);
			glVertex3f(0.6, 0.5, 0.2);        //quad front window
			glVertex3f(0.7, 0.65, 0.2);
			glVertex3f(0.7, 0.65, 0.6);

			glVertex3f(1.7, 0.65, .6);
			glVertex3f(1.7, 0.65, 0.2);        //quad back window
			glVertex3f(1.8, 0.5, 0.2);
			glVertex3f(1.8, 0.5, 0.6);


			//*****************************road and surrounding development***********************************
			if (flag1)
			{
				glPushMatrix();
				glTranslatef(xw, 0, 0);
				glColor3f(0, 1, 0);
				glVertex3f(-100, 0.1, -100);
				glVertex3f(-100, 0.1, 0);         //a green surroundings
				glVertex3f(100, 0.1, 0);
				glVertex3f(100, 0.1, -100);

				glColor3f(0.7, 0.7, 0.7);
				glVertex3f(-100, 0.1, 0);
				glVertex3f(-100, 0.1, 0.45);         //a long road
				glVertex3f(100, 0.1, 0.45);
				glVertex3f(100, 0.1, 0);

				glColor3f(1.0, 0.75, 0.0);
				glVertex3f(-100, 0.1, 0.45);       //a median
				glVertex3f(-100, 0.1, 0.55);
				glVertex3f(100, 0.1, 0.55);
				glVertex3f(100, 0.1, 0.45);

				glColor3f(0.7, 0.7, 0.7);
				glVertex3f(-100, 0.1, 0.55);
				glVertex3f(-100, 0.1, 1);         //a long road
				glVertex3f(100, 0.1, 1);
				glVertex3f(100, 0.1, 0.55);

				glColor3f(0, 1, 0);
				glVertex3f(-100, 0.1, 1);
				glVertex3f(-100, 0.1, 100);         //a green surroundings
				glVertex3f(100, 0.1, 100);
				glVertex3f(100, 0.1, 1);
				glPopMatrix();
			}
			glEnd();

			if (wheelflag)
			{
				glPushMatrix();
				glTranslatef(xw, 0, 0);
				glColor3f(0.5, .2, 0.3);
				glBegin(GL_QUADS);
				for (i = 0;i < 200;i += 0.2)
				{
					glVertex3f(-100 + i, 0, 1);
					glVertex3f(-99.9 + i, 0, 1);
					glVertex3f(-99.9 + i, 0.2, 1);
					glVertex3f(-100 + i, 0.2, 1);
					i += 0.5;
				}
				for (i = 0;i < 200;i += 0.2)
				{
					glVertex3f(-100 + i, 0, 0);
					glVertex3f(-99.9 + i, 0, 0);
					glVertex3f(-99.9 + i, 0.2, 0);
					glVertex3f(-100 + i, 0.2, 0);
					i += 0.5;
				}
				glEnd();
				glPopMatrix();
			}
			//*************************************************************************************************
			glBegin(GL_TRIANGLES);                /* start drawing the cube.*/

			  /* top of cube*/
			glColor3f(0.3, 0.3, 0.3);
			glVertex3f(0.6, 0.5, 0.6);
			glVertex3f(0.7, 0.65, 0.6);       //tri front window
			glVertex3f(0.7, 0.5, 0.6);

			glVertex3f(0.6, 0.5, 0.2);
			glVertex3f(0.7, 0.65, 0.2);       //tri front window
			glVertex3f(0.7, 0.5, 0.2);

			glVertex3f(1.7, 0.65, 0.2);
			glVertex3f(1.8, 0.5, 0.2);       //tri back window
			glVertex3f(1.7, 0.5, 0.2);

			glVertex3f(1.7, 0.65, 0.6);
			glVertex3f(1.8, 0.5, 0.6);       //tri back window
			glVertex3f(1.7, 0.5, 0.6);

			glEnd();
			//************IGNITION SYSTEM**********************************
			glPushMatrix();
			glColor3f(0.7, 0.7, 0.7);
			glTranslatef(1.65, 0.2, 0.3);
			glRotatef(90.0, 0, 1, 0);
			gluCylinder(t, 0.02, 0.03, .5, 10, 10);
			glPopMatrix();
			//********************WHEEL*********************************************

			glColor3f(0.7, 0.7, 0.7);
			glPushMatrix();
			glBegin(GL_LINE_STRIP);
			for (theta = 0;theta < 360;theta = theta + 20)
			{
				glVertex3f(0.6, 0.2, 0.62);
				glVertex3f(0.6 + (0.08 * (cos(((theta + angle) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.62);
			}
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (theta = 0;theta < 360;theta = theta + 20)
			{
				glVertex3f(0.6, 0.2, 0.18);
				glVertex3f(0.6 + (0.08 * (cos(((theta + angle) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.18);
			}
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (theta = 0;theta < 360;theta = theta + 20)
			{
				glVertex3f(1.7, 0.2, 0.18);
				glVertex3f(1.7 + (0.08 * (cos(((theta + angle) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.18);
			}
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (theta = 0;theta < 360;theta = theta + 20)
			{
				glVertex3f(1.7, 0.2, 0.62);
				glVertex3f(1.7 + (0.08 * (cos(((theta + angle) * 3.14) / 180))), 0.2 + (0.08 * (sin(((theta + angle) * 3.14) / 180))), 0.62);
			}
			glEnd();
			glTranslatef(0.6, 0.2, 0.6);
			glColor3f(0, 0, 0);
			glutSolidTorus(0.025, 0.07, 10, 25);

			glTranslatef(0, 0, -0.4);
			glutSolidTorus(0.025, 0.07, 10, 25);

			glTranslatef(1.1, 0, 0);
			glutSolidTorus(0.025, 0.07, 10, 25);

			glTranslatef(0, 0, 0.4);
			glutSolidTorus(0.025, 0.07, 10, 25);
			glPopMatrix();
			//*************************************************************
			glPopMatrix();
			glEnable(GL_DEPTH_TEST);
			glutPostRedisplay();
			glutSwapBuffers();
		}
	}


	/*  The function called whenever a "normal" key is pressed. */
	void NormalKey(GLubyte key, GLint x, GLint y)
	{
		switch (key) {
		case ESCAPE: printf("escape pressed. exit.\n");
			glutDestroyWindow(window);	/* Kill our window */
			exit(0);
			break;

		case ' ':view = 1;
			DrawGLScene();
			break;

		case 'x': xangle += 5.0;
			glutPostRedisplay();
			break;

		case 'X':xangle -= 5.0;
			glutPostRedisplay();
			break;

		case 'y':
			yangle += 5.0;
			glutPostRedisplay();
			break;

		case 'Y':
			yangle -= 5.0;
			glutPostRedisplay();
			break;

		case 'z':
			zangle += 5.0;
			glutPostRedisplay();
			break;

		case 'Z':
			zangle -= 5.0;
			glutPostRedisplay();
			break;

		case 'u':                          /* Move up */
			yt += 0.2;
			glutPostRedisplay();
			break;

		case 'U':
			yt -= 0.2;                      /* Move down */
			glutPostRedisplay();
			break;

		case 'f':                          /* Move forward */
			zt += 0.2;
			glutPostRedisplay();
			break;

		case 'F':
			zt -= 0.2;                      /* Move away */
			glutPostRedisplay();
			break;

		case 's':zs += .2;
			glutPostRedisplay();
			break;

		case 'S':zs -= 0.2;
			glutPostRedisplay();
			break;

		case 'a':ys += .2;
			glutPostRedisplay();
			break;

		case 'A':ys -= 0.2;
			glutPostRedisplay();
			break;

		case 'q':xs += .2;
			glutPostRedisplay();
			break;

		case 'Q':xs -= 0.2;
			glutPostRedisplay();
			break;


		default:
			break;
		}

	}

	static void SpecialKeyFunc(int Key, int x, int y)
	{
		switch (Key) {
		case GLUT_KEY_RIGHT:
			if (!wheelflag)
				xt += 0.2;
			if (wheelflag)
			{
				angle += 5;
				xw += 0.2;
			}
			glutPostRedisplay();
			break;

		case GLUT_KEY_LEFT:
			if (!wheelflag)
				xt -= 0.2;
			if (wheelflag)
			{
				angle += 5;
				xw -= 0.2;
			}
			glutPostRedisplay();
			break;
		}
	}

	void myMenu(int id)
	{
		if (id == 1)
		{
			flag1 = 0;
			wheelflag = 0;
			glutPostRedisplay();

		}
		if (id == 2)
		{
			flag1 = 1;
			flag2 = 0;
			wheelflag = 0;
			xangle += 5.0;
			glutPostRedisplay();
		}
		if (id == 3)
		{
			flag2 = 1;
			wheelflag = 0;
			xangle += 5.0;
			glutPostRedisplay();
		}
		if (id == 4)
		{
			wheelflag = 1;
			glutPostRedisplay();
		}
		if (id == 5)
		{
			if (day)
			{

				if (light)
				{
					count++;
					glDisable(GL_LIGHTING);
					glDisable(GL_LIGHT0);
					light = 0;
				}
				else
				{
					count--;
					light = 1;
					glEnable(GL_LIGHTING);
					glEnable(GL_LIGHT0);
				}
				glutPostRedisplay();
			}
			else
			{

				if (nml == 0 && flag2 == 2)
				{
					flag2 = 0;
					nml = 1;
				}
				else
				{
					flag2 = 2;
					nml = 0;

					aflag = 0;
					day = 0;

					glClearColor(0.1, 0.1, 0.1, 0);
					GLfloat fogcolour[4] = { 0.0,0.0,0.0,1.0 };

					glFogfv(GL_FOG_COLOR, fogcolour);              /* Define the fog colour */
					glFogf(GL_FOG_DENSITY, 0.5);                   /* How dense */
					glFogi(GL_FOG_MODE, GL_EXP);                   /* exponential decay */
							/* end */
					glHint(GL_FOG_HINT, GL_FASTEST);              /* compute per vertex */
					glEnable(GL_FOG);


					glutPostRedisplay();
				}
			}

		}


		if (id == 12)
		{
			aflag = 1;
			day = 1;
			glClearColor(1, 1, 1, 1);
			glDisable(GL_FOG);
			glutPostRedisplay();
		}

		if (id == 13)
		{
			aflag = 0;
			day = 0;
			flag2 = 2;
			glClearColor(0.1, 0.1, 0.1, 0);
			GLfloat fogcolour[4] = { 0.0,0.0,0.0,1.0 };

			glFogfv(GL_FOG_COLOR, fogcolour);              /* Define the fog colour */
			glFogf(GL_FOG_DENSITY, 0.5);                   /* How dense */
			glFogi(GL_FOG_MODE, GL_EXP);                   /* exponential decay */
								   /* end */
			glHint(GL_FOG_HINT, GL_FASTEST);              /* compute per vertex */
			glEnable(GL_FOG);

			glutPostRedisplay();
		}
	}

	void colorMenu(int id)
	{
		if (id == 6)
		{
			r = g = 0;
			b = 1;
			glutPostRedisplay();

		}
		if (id == 7)
		{
			r = 0.8;
			b = g = 0;
			glutPostRedisplay();
		}
		if (id == 8)
		{
			g = 1;
			r = b = 0;
			glutPostRedisplay();
		}
		if (id == 9)
		{
			r = b = g = 0;
			glutPostRedisplay();
		}
		if (id == 10)
		{
			b = 0;
			r = g = 1;
			glutPostRedisplay();
		}
		if (id == 11)
		{
			b = r = g = .7;
			glutPostRedisplay();
		}

	}

	void myreshape(int w, int h)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (w <= h)
			glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
		else
			glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glutPostRedisplay();
	}


	//*************************** Main ***************************************************************

	void main(int argc, char** argv)
	{

		/* Initialisation and window creation */

		glutInit(&argc, argv);               /* Initialize GLUT state. */

		glutInitDisplayMode(GLUT_RGBA |      /* RGB and Alpha */
			GLUT_DOUBLE |     /* double buffer */
			GLUT_DEPTH);     /* Z buffer (depth) */

		glutInitWindowSize(Xsize, Ysize);     /* set initial window size. */
		glutInitWindowPosition(0, 0);         /* upper left corner of the screen. */

		glutCreateWindow("3D CAR ANIMATION"); /* Open a window with a title. */

	  /* Now register the various callback functions */

		glutReshapeFunc(myreshape);
		glutDisplayFunc(DrawGLScene);        /* Function to do all our OpenGL drawing. */
		glutReshapeFunc(ReSizeGLScene);
		glutKeyboardFunc(NormalKey);         /*Normal key is pressed */
		glutSpecialFunc(SpecialKeyFunc);
		InitGL(Xsize, Ysize);
		int submenu = glutCreateMenu(colorMenu);
		glutAddMenuEntry("blue", 6);
		glutAddMenuEntry("red", 7);
		glutAddMenuEntry("green", 8);
		glutAddMenuEntry("black", 9);
		glutAddMenuEntry("yellow", 10);
		glutAddMenuEntry("grey", 11);
		glutCreateMenu(myMenu);
		glutAddMenuEntry("car model mode", 1);
		glutAddMenuEntry("car driving mode", 2);
		glutAddMenuEntry("fog effect", 3);
		glutAddMenuEntry("wheel effect", 4);
		glutAddMenuEntry("toggle light", 5);
		glutAddSubMenu("car colors", submenu);
		glutAddMenuEntry("daymode", 12);
		glutAddMenuEntry("Night mode", 13);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

		/* Now drop into the event loop from which we never return */

		glutMainLoop();                      /* Start Event Processing Engine. */
	}

}
namespace p3 {
	void init()
	{
		// Set display window color to as glClearColor(R,G,B,Alpha)
		glClearColor(1.0, 1.0, 1.0, 0.0);
		// Set projection parameters.
		glMatrixMode(GL_PROJECTION);
		// Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
		gluOrtho2D(0.0, 640, 0.0, 480);
	}

	//void ddaline(double x1, double y1, double x2, double y2)
	void render()
	{
		//LINES, STRIP, LOOP
		glClear(GL_COLOR_BUFFER_BIT);     // Clear display window
		glColor3f(0.0, 0.0, 0.0);
		//int iX = 100;
		//int iLen = 0;
		//double zoomfactor = 1.0;
		//POINTS p[5];
		glBegin(GL_LINES);
		glVertex2i(200, 200);//P1
		glVertex2i(400, 400);//P2
		glVertex2i(400, 200);//P3
		glVertex2i(100, 300);//P4
		glVertex2i(500, 300);//P5
		glEnd();
		glFlush();
	}
	void main(int argc, char** argv)
	{
		// Initialize GLUT
		glutInit(&argc, argv);
		// Set display mode
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		// Set top - left display window position.
		glutInitWindowPosition(100, 100);
		// Set display window width and height
		glutInitWindowSize(640, 480);
		// Create display window with the given title
		glutCreateWindow("Practical 3.1_19012011094 ");
		// Execute initialization procedure
		init();
		// Send graphics to display window
		glutDisplayFunc(render);
		// Display everything and wait.
		glutMainLoop();
	}
}
/*
namespace p32{
	int abs(int n)
	{
		return ((n > 0) ? n : (n * (-1)));
	}
	void DDA(int X1, int Y1, int X2, int Y2)
	{
		int dx = X2 - X1;
		int dy = Y2 - Y1;

		int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

		float Xinc = dx / (float)steps;
		float Yinc = dy / (float)steps;

		float X = X1;
		float Y = Y1;
		for (int i = 0; i <= steps; i++) 
		{
			putpixel(round(X), round(Y), RED);
			X += Xinc;
			Y = +Yinc;
			delay(100);
		}
	}
	int main()
	{
		int gd = DETECT, gm;
		initgraph(&gd, &gm, "");
		int X1 = 10, Y1 = 10, X2 = 100, Y2 = 100;
		DDA(2, 2, 14, 16);
		return 0;
	}
}
*/