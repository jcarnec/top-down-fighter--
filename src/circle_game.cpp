#include <GL/glut.h>
#include <cmath>
#include <chrono> // For high-resolution timing
#include "Player.h"
#include "InputHandler.h"



float moveForce = 0.005f;

// Frame rate control
const int targetFPS = 60;
const float targetFrameTime = 1.0f / static_cast<float>(targetFPS);

int RESOLUTIONX;
int RESOLUTIONY;


Player player(glm::vec2(RESOLUTIONX / 2, RESOLUTIONX / 2), 50.0f);

// Timing variables
std::chrono::high_resolution_clock::time_point prevFrameTime;

// Keyboard callback
void keyboardUp(unsigned char key, int x, int y) {
    player.getInputHandler().keyboardUp(key, x, y);
}

void keyboardDown(unsigned char key, int x, int y) {
    player.getInputHandler().keyboardDown(key, x, y);
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, RESOLUTIONX, 0, RESOLUTIONY, -1, 1); // Set up an orthographic projection
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    player.draw();

    glutSwapBuffers();
}

// Timer callback for animation
void update(int value) {
    // Calculate delta time
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(now - prevFrameTime).count();
    prevFrameTime = now;

    player.getInputHandler().update();
    //log input list
    player.getInputHandler().logInputList();
    player.update();
    player.getInputHandler().clearInputList();
    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(static_cast<unsigned int>(targetFrameTime * 1000), update, 0); // Call update after targetFrameTime in milliseconds
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    // get resolution from monitor
    RESOLUTIONX = glutGet(GLUT_SCREEN_WIDTH);
    RESOLUTIONY = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(RESOLUTIONX, RESOLUTIONY); // Set the resolution to 800 by 800
    glutCreateWindow("OpenGL Circle Game");
    // fix window size
    glutReshapeWindow(RESOLUTIONX, RESOLUTIONY);
    

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutKeyboardUpFunc(keyboardUp);
    glutKeyboardFunc(keyboardDown);
    glutDisplayFunc(display);
    prevFrameTime = std::chrono::high_resolution_clock::now(); // Initialize prevFrameTime
    glutTimerFunc(0, update, 0);

    player.getInputHandler().initializeKeyBindings();
    glutMainLoop();
    return 0;
}
