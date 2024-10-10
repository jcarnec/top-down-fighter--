#include <GL/glut.h>
#include <cmath>
#include <chrono> // For high-resolution timing
#include "Player.h"
#include "InputHandler.h"
#include "HitboxManager.h"
#include "HitResolver.h"

// I think the hit resolver should interact primariliy with the state machine, everything else will be done by the collision resolver.
// a FSA next state is a function of next state (Hitbox_Type{damage, knockback, type}, current_state). The statemachine will communicate with the physics entity.
// Hitbox should have Shape component and Type component.
// The type of command passed to the FSA for the hitting party can be decided by the hitResolver
// If a move hits a non FSA entity, there will be results only for the FSA, again decided by the hit resolver

// The Entity will have a collision component which decides how the player interact with other collision components other than hitboxes.

// Hitboxes check for collision with other hitboxes and with collision boxes.

// Collision boxes only check collision with other collisions. Will be passed to FSA???

float moveForce = 0.005f;

// Frame rate control
const int targetFPS = 60;
const float targetFrameTime = 1.0f / static_cast<float>(targetFPS);

int RESOLUTIONX = 500;
int RESOLUTIONY = 500;

std::shared_ptr<HitboxManager> mainHitboxManager = std::make_shared<HitboxManager>();
std::shared_ptr<HitResolver> mainHitResolver = std::make_shared<HitResolver>();
Player player(glm::vec2((RESOLUTIONX / 4) * 2, (RESOLUTIONX / 4) * 1), Shape(), mainHitboxManager, mainHitResolver);
Player player2(glm::vec2((RESOLUTIONX / 4) * 3, (RESOLUTIONX / 4) * 2), Shape(), mainHitboxManager, mainHitResolver);

// Timing variables
std::chrono::high_resolution_clock::time_point prevFrameTime;

// Keyboard callback
void keyboardUp(unsigned char key, int x, int y) {
    player.getComponent<InputHandler>()->keyboardUp(key, x, y);
}

void keyboardDown(unsigned char key, int x, int y) {
    player.getComponent<InputHandler>()->keyboardDown(key, x, y);
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
    player2.draw();
    mainHitboxManager->draw();

    glutSwapBuffers();
}

// Timer callback for animation
void update(int value) {
    // Calculate delta time
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(now - prevFrameTime).count();
    prevFrameTime = now;

    player.getComponent<InputHandler>()->update();
    //log input list
    player.update();
    player2.update();
    player.getComponent<InputHandler>()->clearInputList();
    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(static_cast<unsigned int>(targetFrameTime * 1000), update, 0); // Call update after targetFrameTime in milliseconds
}

int main(int argc, char** argv) {

    // create Entity with Circle shape
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
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutKeyboardUpFunc(keyboardUp);
    glutKeyboardFunc(keyboardDown);
    glutDisplayFunc(display);
    prevFrameTime = std::chrono::high_resolution_clock::now(); // Initialize prevFrameTime
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
