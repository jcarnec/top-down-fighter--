#include "State.h"
#include "Player.h"

void State::draw() {
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f); // Set line color to red
    glTranslatef(player->getPhysics().getPosition().x, player->getPhysics().getPosition().y, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * player->getSize(), sin(degInRad) * player->getSize());
    }
    glEnd();

    // draw a separate line to show the direction the player is moving
    glm::vec2 velocity = player->getPhysics().getVelocity();
    glm::vec2 direction = velocity * 10.0f;

    // draw the line
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); // Set line color to red
    glVertex2f(0.0f, 0.0f); // Starting point of the line (center of the player)
    glVertex2f(direction.x, direction.y); // Ending point of the line
    glEnd();

    // acceleration in red
    glm::vec2 acceleration = player->getPhysics().getAcceleration();
    glm::vec2 accelerationDirection = acceleration * 10.0f;
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f); // Set line color to red
    glVertex2f(0.0f, 0.0f); // Starting point of the line (center of the player)
    glVertex2f(accelerationDirection.x, accelerationDirection.y); // Ending point of the line
    glEnd();


    glPopMatrix();
}


void State::physicsUpdate() {
        player->getPhysics().applyPhysics();
        player->getPhysics().setAcceleration(glm::vec2(0.0f, 0.0f));
        player->getPhysics().setEAcceleration(glm::vec2(0.0f, 0.0f));

}
