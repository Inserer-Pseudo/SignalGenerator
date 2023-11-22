#include <iostream>
#include "Sinus.hpp"

const float SinusA0 = 2.5;
const float SinusAmplitude = 2;
const float SinusOmega = 12.56;
const float SinusPhi0 = 0.0;

float 			simultStart = 0;	 	/**< Start time. In "time units", 0 by default.	*/
float 			simultStop = 2;		/**< Stop time. In "time units", 1 by default. */
unsigned int	simulnbPoints = 10000;	/**< Simulation step. Defined by (tStop - tStart) / nbPoints. */


int main(){

    SinusParam ParamBigSinus{SinusA0,SinusAmplitude,SinusOmega,SinusPhi0};
	

    ComputeParameters BigSinusComputParam{ simultStart, simultStop, simulnbPoints};

    Sinus BigSinus{ParamBigSinus,BigSinusComputParam};

    unsigned int FileSize = BigSinus.generate();

}

