
/**
 * @file HitboxManager.h
 * @brief Implements a HitboxManager class that manages hitboxes and hitbox observers
 */

#pragma once

#include <vector>
#include <memory>
#include "Hitbox.h"

/**
 * @brief A class that manages hitboxes and hitbox observers
 */
class HitboxManager
{

public:

    // display function that displays all hitboxes as red circles and hitbox observers as yellow circles
    void draw() const
    {


        for (auto &hitbox : hitboxes)
        {
            hitbox->log();
            hitbox->getEntity()->getShape().draw();
        }
        for (auto &hitboxObserver : hitboxObservers)
        {
            hitboxObserver->log();
            hitboxObserver->getEntity()->getShape().draw();
        }
    }

    void addHitbox(std::shared_ptr<Hitbox> hitbox)
    {
        for (auto &hitboxObserver : hitboxObservers)
        {
            if (checkHitboxInteraction(hitbox, hitboxObserver))
            {
                hitbox->attach(hitboxObserver);
            }
        }
        hitboxes.push_back(hitbox);
    }

    void addHitboxObserver(std::shared_ptr<HitboxObserver> hitboxObserver)
    {
        hitboxObservers.push_back(hitboxObserver);
        for (auto &hitbox : hitboxes)
        {
            if (checkHitboxInteraction(hitbox, hitboxObserver))
            {
                hitbox->attach(hitboxObserver);
            }
        }
    }

    void removeHitbox(std::shared_ptr<Hitbox> hitbox)
    {
        hitboxes.erase(std::remove(hitboxes.begin(), hitboxes.end(), hitbox), hitboxes.end());
    }

    void removeHitboxObserver(std::shared_ptr<HitboxObserver> hitboxObserver)
    {
        hitboxObservers.erase(std::remove(hitboxObservers.begin(), hitboxObservers.end(), hitboxObserver), hitboxObservers.end());
    }

    std::vector<std::shared_ptr<Hitbox>> &getHitboxCollection()
    {
        return hitboxes;
    }

    std::vector<std::shared_ptr<HitboxObserver>> &getHitboxObserverCollection()
    {
        return hitboxObservers;
    }

private:
    std::vector<std::shared_ptr<Hitbox>> hitboxes;
    std::vector<std::shared_ptr<HitboxObserver>> hitboxObservers;

    bool checkHitboxInteraction(std::shared_ptr<Hitbox> hitbox, std::shared_ptr<HitboxObserver> hitboxObserver)
    {
        // Check if hitbox and hitbox observer are from the same player
        return (hitbox->getEntity()->getId() != hitboxObserver->getEntity()->getId());
    }
};