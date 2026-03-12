#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

float r = 1.0, g = 1.0, b = 1.0;

void display() {
    glClearColor(r, g, b, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void menu(int choice) {
    if (choice == 1) { r=1; g=0; b=0; } // Red
    if (choice == 2) { r=0; g=1; b=0; } // Green
    if (choice == 3) { r=0; g=0; b=1; } // Blue
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Menu OpenGL");
    glutDisplayFunc(display);
    int m = glutCreateMenu(menu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}