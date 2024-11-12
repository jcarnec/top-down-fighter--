#pragma once
#include <iostream>
class HitTransfer {

    public:
    HitTransfer(std::string kbt) : knockbackType(kbt) {};

    private:

    std::string knockbackType;

};