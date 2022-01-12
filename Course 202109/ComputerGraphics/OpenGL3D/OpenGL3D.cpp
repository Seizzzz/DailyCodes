#include <windows.h>
#include <gl/glut.h>
#include <gl/glaux.h>
#include <iostream>
#include <fstream>

#pragma comment(lib, "glaux.lib")

int iButtonType = -1;
int iButtonState = -1;
float fRotationX = 20.0f;
float fRotationY = -45.0f;

GLfloat ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat	lightPos[] = { -2.0f, 10.0f, -5.0f, 1.0f };

GLfloat gray[] = { 0.3f, 0.3f, 0.3f, 1.0f };

GLuint texture_box;
const char* texture_box_filename = "texture_box.bmp";

#define drawWithConvert(method, rots_x, rots_y, rots_z, scale_x, scale_y, scale_z, trans_x, trans_y, trans_z) \
{ \
	glPushMatrix();\
	glRotatef(rots_x, 1.0f, 0.0f, 0.0f);\
	glRotatef(rots_y, 0.0f, 1.0f, 0.0f);\
	glRotatef(rots_z, 0.0f, 0.0f, 1.0f);\
	glScalef(scale_x, scale_y, scale_z);\
	glTranslatef(trans_x, trans_y, trans_z);\
	method;\
	glPopMatrix();\
}

AUX_RGBImageRec* LoadBMP(const CHAR* Filename) // 通过GLAux读取BMP图片文件
{
	std::fstream f(Filename, std::fstream::in);
	if (f.is_open())
	{
		return auxDIBImageLoadA(Filename);
	}
	return NULL;
}

void LoadGLTextures(GLuint* tex, const char* bmp_filename, int texture_id) // 加载BMP图片文件构造纹理
{
	AUX_RGBImageRec* BMPImg = nullptr;
	if (BMPImg = LoadBMP(bmp_filename))
	{
		glGenTextures(texture_id, tex);   
		glBindTexture(GL_TEXTURE_2D, *tex);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, BMPImg->sizeX, BMPImg->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, BMPImg->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	if (BMPImg)
	{
		if (BMPImg->data) free(BMPImg->data);
		free(BMPImg);
	}
}

void drawTexturedCube(GLuint texId) // 绘制具有纹理的立方体
{
	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);

	// front
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// back
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// top
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// bottom
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// right
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// left
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
}

void drawCylinder(GLdouble radius, GLdouble height, GLint slices, GLint stacks) // 绘制圆柱（侧面+顶面）
{
	GLUquadric* cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, radius, radius, height, slices, stacks); // 绘制圆柱侧面
	gluDisk(cylinder, 0, radius, slices, stacks); // 绘制圆柱顶面
	gluDeleteQuadric(cylinder);
}

void drawSurface(GLdouble radius, GLint slices, GLint stacks) // 绘制曲面（曲面圆环）
{
	GLUquadric* cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluDisk(cylinder, radius/2, radius, slices, stacks);
	gluDeleteQuadric(cylinder);
}

void Display() // 每帧绘制场景
{
	// Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Rotate
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -12.0f);
	glRotatef(fRotationX, 1.0f, 0.0f, 0.0f);
	glRotatef(fRotationY, 0.0f, 1.0f, 0.0f);

	// Scene
	// wall
	drawWithConvert(glutSolidCube(1.0f), 0.0f, 0.0f, 0.0f, 5.0f, 0.1f, 5.0f, 0.5f, 0.0f, 0.5f);
	drawWithConvert(glutSolidCube(1.0f), 90.0f, 0.0f, 0.0f, 5.0f, 0.1f, 5.0f, 0.5f, 0.0f, -0.5f);
	drawWithConvert(glutSolidCube(1.0f), 0.0f, 0.0f, 90.0f, 5.0f, 0.1f, 5.0f, 0.5f, 0.0f, 0.5f);
	// object
	drawWithConvert(drawTexturedCube(texture_box), 0.0f, 60.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 8.0f);
	drawWithConvert(glutSolidSphere(1.0f, 20, 20), 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 5.0f, 1.0f, 5.0f);
	drawWithConvert(glutSolidCone(1.0f, 4.0f, 20, 20), -90.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 8.0f, -8.0f, 0.0f);
	drawWithConvert(glutSolidDodecahedron(), 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 5.0f, 1.5f, 8.0f);
	drawWithConvert(drawCylinder(1.0f, 2.0f, 32, 8), 90.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 3.0f, 2.0f, -2.0f);
	drawWithConvert(drawSurface(1.0f, 32, 8), 90.0f, 90.0f, 0.0f, 1.0f, 1.0f, 1.0f, 3.0f, 2.0f, 0.5f);

	// Restore
	glPopMatrix();

	// Flush drawing commands
	glutSwapBuffers();

}

void SetupRC() // 初始设置
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Enable Depth Testing
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_AMBIENT, gray);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, gray);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	//glMaterialf(GL_FRONT, GL_SHININESS, 10.0f);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	
	LoadGLTextures(&texture_box, texture_box_filename, 1);
}


void Resize(int w, int h) // 窗口尺寸改变
{
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, double(w) / double(h), 1.0f, 1000.0f);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

float dx = 0.0f;
float dy = 0.0f;

void Mouse(int button, int state, int x, int y) // 鼠标点击事件
{
	iButtonType = button;
	iButtonState = state;
	switch (iButtonType)
	{
	case GLUT_LEFT_BUTTON: {
		if (iButtonState == GLUT_DOWN) {
			dx = x - fRotationY;
			dy = -y + fRotationX;
		}
		break;
	}

	default:
		break;
	}
}

void Motion(int x, int y) // 鼠标移动事件
{
	switch (iButtonType)
	{
	case GLUT_LEFT_BUTTON: {
		if (iButtonState == GLUT_DOWN) {
			fRotationX = y + dy;
			fRotationY = x - dx;
		}
		glutPostRedisplay();
		break;
	}

	default:
		break;
	}

}

int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(1280, 720);
	auto MainWindow = glutCreateWindow("OpenGL3D");

	SetupRC();
	LoadGLTextures(&texture_box, texture_box_filename, 1);
	
	glutDisplayFunc(Display);
	glutReshapeFunc(Resize);  //function for changing window size
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);

	glutMainLoop();
}
