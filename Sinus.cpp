#include "Signal.hpp"
#include "Helper.hpp"
#include "Sinus.hpp"



void Sinus::compute() const noexcept {
    	
	SinusHelper myHelper{this->Parameters};
	
	this->tabSignal = myHelper.do_compute(this->SimulParams);
}
