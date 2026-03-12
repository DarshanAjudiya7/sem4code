#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float x = 0.0, y = 0.0;
float r = 1.0, g = 1.0, b = 1.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x-0.1, y-0.1);
        glVertex2f(x+0.1, y-0.1);
        glVertex2f(x+0.1, y+0.1);
        glVertex2f(x-0.1, y+0.1);
    glEnd();
    glFlush();
}

void keyboard(int key, int, int) {
    float step = 0.05;
    if (key == GLUT_KEY_LEFT)  x -= step;
    if (key == GLUT_KEY_RIGHT) x += step;
    if (key == GLUT_KEY_UP)    y += step;
    if (key == GLUT_KEY_DOWN)  y -= step;
    glutPostRedisplay();
}

void mouse(int button, int state, int, int) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        r = (float)rand()/RAND_MAX;
        g = (float)rand()/RAND_MAX;
        b = (float)rand()/RAND_MAX;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Move Square");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}