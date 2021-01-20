#ifndef OPEN_HPP
#define OPEN_HPP

#include "Singlton.hpp"

void Open(){
    log = std::make_unique<HLA::Logger>("", L"");
}

#endif // OPEN_HPP
