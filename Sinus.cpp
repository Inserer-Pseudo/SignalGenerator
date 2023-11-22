#include "Signal.hpp"
#include "Helper.hpp"
#include "Sinus.hpp"

void Sinus::compute() const noexcept{
    // Creates Helper, then calls the do_compute method
	SinusHelper myHelper{this->Parameters};
	
	this->tabSignal = myHelper.do_compute(this->SimulParams);
}