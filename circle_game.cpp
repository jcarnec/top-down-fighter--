#include <GL/glut.h>
#include <cmath>
#include <chrono> // For high-resolution timing

float moveSpeed = 0.005f;

// Frame rate control
const int targetFPS = 60;
const float targetFrameTime = 1.0f / static_cast<float>(targetFPS);

const int RESOLUTION = 800;

// Timing variables
std::chrono::high_resolution_clock::time_point prevFrameTime;

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glutSwapBuffers();
}

// Timer callback for animation
void update(int value) {
    // Calculate delta time
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(now - prevFrameTime).count();
    prevFrameTime = now;


    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(static_cast<unsigned int>(targetFrameTime * 1000), update, 0); // Call update after targetFrameTime in milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(RESOLUTION, RESOLUTION); // Set the resolution to 800 by 800
    glutCreateWindow("OpenGL Circle Game");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    prevFrameTime = std::chrono::high_resolution_clock::now(); // Initialize prevFrameTime
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
