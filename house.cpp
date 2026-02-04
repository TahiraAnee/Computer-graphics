#include<windows.h>
#include <GL/glut.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);	// Background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);	// 2D coordinate system
}

void drawShapes(void)
{
    glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

    // ---------------- Roof ----------------
    glColor3f(1.0, 0.0, 0.0);  // Red
    glBegin(GL_TRIANGLES);
        glVertex2i(80, 150);
        glVertex2i(162, 220);
        glVertex2i(245, 150);
    glEnd();

    // ---------------- House Body ----------------
    glColor3f(1.0, 1.0, 1.0);  // White
    glBegin(GL_QUADS);
        glVertex2i(100, 50);
        glVertex2i(225, 50);
        glVertex2i(225, 150);  // Roof bottom = 150 → seamless
        glVertex2i(100, 150);
    glEnd();

    glColor3f(0.0, 0.0, 1.0); // White
    glBegin(GL_POLYGON);       // 6 vertex polygon
        glVertex2i(100, 55);  // point 1
        glVertex2i(90, 55);  // point 2
        glVertex2i(90, 45);  // point 3
        glVertex2i(235, 45); // point 4
        glVertex2i(235, 55); // point 5
        glVertex2i(225, 55); // point 6
    glEnd();

    // ---------------- Door ----------------
    int dx1=150, dx2=175, dy1=50, dy2=125;
    glColor3f(0.0, 1.0, 0.0);  // green
    glBegin(GL_QUADS);
        glVertex2i(dx1, dy1);
        glVertex2i(dx2, dy1);
        glVertex2i(dx2, dy2);
        glVertex2i(dx1, dy2);
    glEnd();

    // Door border
    glColor3f(0.0, 0.0, 0.0);  // Black border
    glBegin(GL_LINE_LOOP);
        glVertex2i(dx1, dy1);
        glVertex2i(dx2, dy1);
        glVertex2i(dx2, dy2);
        glVertex2i(dx1, dy2);
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // black line
    glBegin(GL_LINES);
        glVertex2i(dx1 + (dx2-dx1)/2, dy1);  // bottom
        glVertex2i(dx1 + (dx2-dx1)/2, dy2);  // top
    glEnd();


    // ---------------- Left Window ----------------
    int lx1=115, lx2=140, ly1=90, ly2=125;
    glColor3f(1.0, 1.0, 0.0);  // yellow window
    glBegin(GL_QUADS);
        glVertex2i(lx1, ly1);
        glVertex2i(lx2, ly1);
        glVertex2i(lx2, ly2);
        glVertex2i(lx1, ly2);
    glEnd();

    // Left window border
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(lx1, ly1);
        glVertex2i(lx2, ly1);
        glVertex2i(lx2, ly2);
        glVertex2i(lx1, ly2);
    glEnd();

    // Left window grill
    glBegin(GL_LINES);
        // 2 vertical
        glVertex2i(lx1 + (lx2-lx1)/3, ly1);
        glVertex2i(lx1 + (lx2-lx1)/3, ly2);

        glVertex2i(lx1 + 2*(lx2-lx1)/3, ly1);
        glVertex2i(lx1 + 2*(lx2-lx1)/3, ly2);

        // 2 horizontal
        glVertex2i(lx1, ly1 + (ly2-ly1)/3);
        glVertex2i(lx2, ly1 + (ly2-ly1)/3);

        glVertex2i(lx1, ly1 + 2*(ly2-ly1)/3);
        glVertex2i(lx2, ly1 + 2*(ly2-ly1)/3);
    glEnd();

    // ---------------- Right Window ----------------
    int rx1=185, rx2=210, ry1=90, ry2=125;
    glColor3f(1.0, 1.0, 0.0);  // yellow window
    glBegin(GL_QUADS);
        glVertex2i(rx1, ry1);
        glVertex2i(rx2, ry1);
        glVertex2i(rx2, ry2);
        glVertex2i(rx1, ry2);
    glEnd();

    // Right window border
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(rx1, ry1);
        glVertex2i(rx2, ry1);
        glVertex2i(rx2, ry2);
        glVertex2i(rx1, ry2);
    glEnd();

    // Right window grill
    glBegin(GL_LINES);
        // 2 vertical
        glVertex2i(rx1 + (rx2-rx1)/3, ry1);
        glVertex2i(rx1 + (rx2-rx1)/3, ry2);

        glVertex2i(rx1 + 2*(rx2-rx1)/3, ry1);
        glVertex2i(rx1 + 2*(rx2-rx1)/3, ry2);

        // 2 horizontal
        glVertex2i(rx1, ry1 + (ry2-ry1)/3);
        glVertex2i(rx2, ry1 + (ry2-ry1)/3);

        glVertex2i(rx1, ry1 + 2*(ry2-ry1)/3);
        glVertex2i(rx2, ry1 + 2*(ry2-ry1)/3);
    glEnd();

    glFlush();	// Process all OpenGL routines
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(300, 50);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("A House");

    init();
    glutDisplayFunc(drawShapes);
    glutMainLoop();

    return 0;
}
