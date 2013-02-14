//
//  main.cpp
//  MultimediaOpenGLProject
//
//  Created by Glenn Maricaux on 14/02/13.
//  Copyright (c) 2013 Glenn Maurits. All rights reserved.
//

// Cross-platform
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h> //GLUT bevat OpenGL en GLU
#endif


// ---- Prototypes ----
void Render(void);
void Initialise();

// ---- Main Function ----
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Project Multimedia 6");
	glutDisplayFunc(Render);
	Initialise();
	glutMainLoop();
}

// ---- Render Function ----
void Render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
	glEnd();
    
	glFlush();
}

// ---- Initialise Function ----
void Initialise()
{
	glClearColor (1.0, 0.0, 1.0, 0.0);
}