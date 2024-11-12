#pragma once
#include <iostream>
#include "HitTransfer.h"
#include "BasicPhysicsComponent.h"
class MassBasedHitTransfer : public HitTransfer {

    MassBasedHitTransfer(BasicPhysicsComponent& pcA, BasicPhysicsComponent& pcB) : HitTransfer("MASS_BASED") {
        massObjectA = pcA.getMass();
        massObjectB = pcB.getMass();
    }

    private:
    int massObjectA;
    int massObjectB;

};