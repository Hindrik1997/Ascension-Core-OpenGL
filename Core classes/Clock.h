//
// Created by hindrik on 29-11-16.
//

#ifndef ASCENSION_CORE_CLOCK_H
#define ASCENSION_CORE_CLOCK_H

#include <chrono>

class Clock {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_previousFrame;
public:
    float getDeltaTime();

};


#endif //ASCENSION_CORE_CLOCK_H
