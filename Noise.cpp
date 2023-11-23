#include "Noise.hpp"

void Noise::compute() const noexcept{
	NoiseHelper myHelper{this->Parameters};
	
	this->tabSignal = myHelper.do_compute(this->SimulParams);
}