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

#include <stdlib.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    //
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    glLoadIdentity(); //clear matrix
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //viewing information
    glScalef(1.0, 2.0, 1.0);//modelling transformation
    glutWireCube(1.0); //draw primitive
    
    glFlush();
    
}

void reshape(int w, int h) //function called when window is resized 
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)//function called when key is pressed
{
    //exit program when exit is pressed (key 27)
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //initialize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//single buffer, color system (could also be RGBA)
    
    glutInitWindowSize(500, 500);//set window size
    glutInitWindowPosition(100, 100);//set window pos
    
    glutCreateWindow(argv[0]);//create window!
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
    
}