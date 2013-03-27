//
//  main.cpp
//  MultimediaOpenGLProject
//
//  Created by Glenn Maricaux on 14/02/13.
//  Copyright (c) 2013 Glenn Maurits. All rights reserved.
//
#include "stdafx.h"
#include <stdlib.h>
// Cross-platform
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h> //GLUT bevat OpenGL en GLU

#endif


#include "imageloader.h"
#include <fstream>
#include <assert.h>



#define GL_CLAMP_TO_EDGE 0x812F //ontbreekt in OpenGL 1.1(windows standaard)
using namespace std;

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
GLfloat xspeed;
GLfloat yspeed;
GLfloat z=-3.0f;
float deltaAngle = 0.0f;
int xOrigin = -1;
bool active=true;
bool fullscreen=true;
GLfloat mouse_x;
GLfloat mouse_y;
float scaler = 2.0f;
float sphereRadius= 1.0f;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    //
}

void display(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    
    //glLoadIdentity(); //clear matrix
    //gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //viewing information
    //glScalef(1.0, 2.0, 1.0);//modelling transformation
    //glutWireCube(1.0); //draw primitive
    
    //glFlush();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
    
	glPushMatrix();

	/* Camera position */
	glTranslatef(0.0f, -0.25f, z); //Move forward 50 units
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
    // Bottom section - two triangles
   /* glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    
    
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    
    // Front Face
    glNormal3f(0.0f, 0.535331905781585f, 0.856531049250535f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    
    // Left Face
    glNormal3f(-0.856531049250535f, 0.535331905781585f, 0.0f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    
    // Back Face
    glNormal3f(0.0f, 0.535331905781585f, -0.856531049250535f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    
    // Right Face
    glNormal3f(0.856531049250535f, 0.535331905781585f, 0.0f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, -0.5f);

	*/
	static GLUquadricObj * sphere=gluNewQuadric();
	glEnable(GL_LIGHTING);
	/*glMaterialfv(GL_FRONT, GL_AMBIENT, COLOR(1.0f, 0.0f, 0.0f, 0.0f));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, COLOR(1.0f, 0.0f, 0.0f, 0.0f));
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 32.0f);*/
	glEnable(GL_CULL_FACE);

	gluSphere(sphere, sphereRadius, 48, 24);
			
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	
	glEnd();
	
		
		
	
	
	glPopMatrix();
	
	glutSwapBuffers();

	

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
        case GLUT_KEY_LEFT:
            //key d
            yRot += 5.0f;
            break;
        case GLUT_KEY_RIGHT:
            //key f
            yRot -= 5.0f;
            break;
		case 119:
			//key r
			z-=0.1f;
			break;
		case 115:
			//key s
			z+=0.1f;
			break;
	/*	case GLUT_LEFT_BUTTON:
			if(GLUT_UP)
				//no mousecontrol

			else if (GLUT_DOWN)
			//mousecontrtol
		break;*/
    }
    glutPostRedisplay();
}

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {
	
}

Image::~Image() {
	delete[] pixels;
}

namespace {
	//Converts a four-character array to an integer, using little-endian form
	int toInt(const char* bytes) {
		return (int)(((unsigned char)bytes[3] << 24) |
					 ((unsigned char)bytes[2] << 16) |
					 ((unsigned char)bytes[1] << 8) |
					 (unsigned char)bytes[0]);
	}
	
	//Converts a two-character array to a short, using little-endian form
	short toShort(const char* bytes) {
		return (short)(((unsigned char)bytes[1] << 8) |
					   (unsigned char)bytes[0]);
	}
	
	//Reads the next four bytes as an integer, using little-endian form
	int readInt(ifstream &input) {
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}
	
	//Reads the next two bytes as a short, using little-endian form
	short readShort(ifstream &input) {
		char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
	}
	
	//Just like auto_ptr, but for arrays
	template<class T>
	class auto_array {
    private:
        T* array;
        mutable bool isReleased;
    public:
        explicit auto_array(T* array_ = NULL) :
        array(array_), isReleased(false) {
        }
        
        auto_array(const auto_array<T> &aarray) {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }
        
        ~auto_array() {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
        }
        
        T* get() const {
            return array;
        }
        
        T &operator*() const {
            return *array;
        }
        
        void operator=(const auto_array<T> &aarray) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }
        
        T* operator->() const {
            return array;
        }
        
        T* release() {
            isReleased = true;
            return array;
        }
        
        void reset(T* array_ = NULL) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = array_;
        }
        
        T* operator+(int i) {
            return array + i;
        }
        
        T &operator[](int i) {
            return array[i];
        }
	};
}

Image* loadBMP(const char* filename) {
	ifstream input;
	input.open(filename, ifstream::binary);
	assert(!input.fail() || !"Could not find file");
	char buffer[2];
	input.read(buffer, 2);
	assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
	input.ignore(8);
	int dataOffset = readInt(input);
	
	//Read the header
	int headerSize = readInt(input);
	int width;
	int height;
	switch(headerSize) {
		case 40:
			//V3
			width = readInt(input);
			height = readInt(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			assert(readShort(input) == 0 || !"Image is compressed");
			break;
		case 12:
			//OS/2 V1
			width = readShort(input);
			height = readShort(input);
			input.ignore(2);
			assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
			break;
		case 64:
			//OS/2 V2
			assert(!"Can't load OS/2 V2 bitmaps");
			break;
		case 108:
			//Windows V4
			assert(!"Can't load Windows V4 bitmaps");
			break;
		case 124:
			//Windows V5
			assert(!"Can't load Windows V5 bitmaps");
			break;
		default:
			assert(!"Unknown bitmap format");
	}
	
	//Read the data
	int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	int size = bytesPerRow * height;
	auto_array<char> pixels(new char[size]);
	input.seekg(dataOffset, ios_base::beg);
	input.read(pixels.get(), size);
	
	//Get the data into the right format
	auto_array<char> pixels2(new char[width * height * 3]);
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			for(int c = 0; c < 3; c++) {
				pixels2[3 * (width * y + x) + c] =
                pixels[bytesPerRow * y + 3 * x + (2 - c)];
			}
		}
	}
	
	input.close();
	return new Image(pixels2.release(), width, height);
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				 //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


void sphereSizer(){
	if(sphereRadius < 1.5)
	{
		sphereRadius = sphereRadius +0.01;
	}
	else
	{
		while(sphereRadius >  0.5){
		sphereRadius = sphereRadius -0.01;
		}
	}

}




GLuint _textureId; //The id of the texture

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //initialize glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//single buffer, color system (could also be RGBA)
    
    glutInitWindowSize(500, 500);//set window size
    glutInitWindowPosition(100, 100);//set window pos
    glScalef(scaler,scaler,scaler);
    glutCreateWindow(argv[0]);//create window!
   // init();
    glEnable(GL_DEPTH_TEST); //Initializes 3D rendering (makes 3D drawing work when something is in front of something else)
    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);		// Do not calculate inside of jet
    
    // Enable lighting
    glEnable(GL_LIGHTING);
	
    // Light values and coordinates
    GLfloat whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };
    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);
	
    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    
    Image* testImg = loadBMP("/Users/Maurits/Programming/MMOpenGLProject/MultimediaOpenGLProject/MMOPENGLPROJECT/MMOPENGLPROJECT/test.bmp");
    _textureId = loadTexture(testImg);
    delete testImg;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);
    
    glutMainLoop();
    return 0;
    
}