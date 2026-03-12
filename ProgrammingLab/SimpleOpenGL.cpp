#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex2f(0.0, 0.5);
        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Colored Triangle");
    glClearColor(0, 0, 0, 1); // Black background
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}