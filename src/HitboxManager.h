
/**
 * @file HitboxManager.h
 * @brief Implements a HitboxManager class that manages hitboxes and hitbox observers
*/

#pragma once

#include <vector>
#include <memory>
#include "Hitbox.h"
#include "HitboxObserver.h"

/**
 * @brief A class that manages hitboxes and hitbox observers
*/
class HitboxManager {
    public:
    void addHitbox(std::shared_ptr<Hitbox> hitbox) {
        for(auto& hitboxObserver : hitboxObservers) {
            if (checkHitboxInteraction(hitbox, hitboxObserver)) {
                hitbox->attach(hitboxObserver);
            }
        }
        hitboxes.push_back(hitbox);
    }

    void addHitboxObserver(std::shared_ptr<HitboxObserver> hitboxObserver) {
        hitboxObservers.push_back(hitboxObserver);
        for(auto& hitbox : hitboxes) {
            if (checkHitboxInteraction(hitbox, hitboxObserver)) {
                hitbox->attach(hitboxObserver);
            }
        }
    }

    void removeHitbox(std::shared_ptr<Hitbox> hitbox) {
        hitboxes.erase(std::remove(hitboxes.begin(), hitboxes.end(), hitbox), hitboxes.end());
    }

    void removeHitboxObserver(std::shared_ptr<HitboxObserver> hitboxObserver) {
        hitboxObservers.erase(std::remove(hitboxObservers.begin(), hitboxObservers.end(), hitboxObserver), hitboxObservers.end());
    }


private:
    std::vector<std::shared_ptr<Hitbox>> hitboxes; /**< The hitbox collection */
    std::vector<std::shared_ptr<HitboxObserver>> hitboxObservers; /**< The hitbox observer collection */

    std::vector<std::shared_ptr<Hitbox>>& getHitboxCollection() {
        return hitboxes;
    }

    std::vector<std::shared_ptr<HitboxObserver>>& getHitboxObserverCollection() {
        return hitboxObservers;
    }

    /**
    * @brief Decide whether a hitbox and hitbox observer interact with each other
    * @param hitbox The hitbox to check
    * @param hitboxObserver The hitbox observer to check
    */

    bool checkHitboxInteraction(std::shared_ptr<Hitbox> hitbox, std::shared_ptr<HitboxObserver> hitboxObserver) {
        // Check if hitbox and hitbox observer are from the same player
        return (hitbox->getOwner() == hitboxObserver->getOwner());
    }
};