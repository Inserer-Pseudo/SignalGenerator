// To compile the project :
// g++ -std=c++20 Helper.cpp Signal.cpp Sinus.cpp Main.cpp -o Sinus.out

#include <iostream>
#include "Sinus.hpp"

const float SinusA0 = 1.5;
const float SinusAmplitude = 3.0;
const float SinusOmega = 6.28;
const float SinusPhi0 = 0.0;

const float SimStartTime = 0.0;
const float SimStopTime = 2.0;
const unsigned int SimNbPoints = 10000;

int main(int argc, char** argv) {
    
    SinusParam sParam{SinusA0, SinusAmplitude, SinusOmega, SinusPhi0};  
    ComputeParameters cParam{SimStartTime,SimStopTime,SimNbPoints};     

	Sinus mySinus{sParam, cParam};  

    unsigned int FileSize = mySinus.generate();

    return 0;
}