/**
 *	@file	Helper.cpp
 * 	@brief 	Helper class implementation file
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */
#include "Helper.hpp"
//----------------------------------------------------------------------
std::vector<SignalPoint> DummyHelper::compute(const ComputeParameters &SimulParameters) const noexcept{
	std::vector<SignalPoint> locSignal{};
	SignalPoint	Point{};
	
	float 	dt = (SimulParameters.tStop - SimulParameters.tStart) / static_cast<float>(SimulParameters.nbPoints);	/**< Simulation Step		*/
	
	for (unsigned int t=0 ; t < SimulParameters.nbPoints ; ++t){
		Point.tn = SimulParameters.tStart + (static_cast<float>(t) * dt);
		Point.sig_tn = this->getValue();
		locSignal.push_back(Point);
	}
		
	return locSignal;
}
//----------------------------------------------------------------------
std::vector<SignalPoint> SinusHelper::compute(const ComputeParameters &SimulParameters) const noexcept{
	std::vector<SignalPoint> locSignal{};
	SignalPoint	Point{};
	
	float 	dt = (SimulParameters.tStop - SimulParameters.tStart) / static_cast<float>(SimulParameters.nbPoints);	/**< Simulation Step		*/
	float 	tmp;

	for (unsigned int t=0 ; t < SimulParameters.nbPoints ; ++t){
		Point.tn = SimulParameters.tStart + (static_cast<float>(t) * dt);

		tmp = (this->Parameters.Omega * Point.tn) + this->Parameters.Phi0;
		tmp = sin(tmp);
		tmp *= this->Parameters.Amplitude;
		tmp += this->Parameters.A0;
		Point.sig_tn = tmp;

		locSignal.push_back(Point);
	}
		
	return locSignal;
}

//----------------------------------------------------------------------
std::vector<SignalPoint> NoiseHelper::compute(const ComputeParameters &SimulParameters) const noexcept{
	std::vector<SignalPoint> locSignal{};
	SignalPoint	Point{};
	
	float 	dt = (SimulParameters.tStop - SimulParameters.tStart) / static_cast<float>(SimulParameters.nbPoints);	/**< Simulation Step		*/
	float 	tmp;

    const double mean = this->Parameters.A0;
    const double stddev = 0.1;
    std::default_random_engine generator;
    std::normal_distribution<double> dist(mean, stddev);

	for (unsigned int t=0 ; t < SimulParameters.nbPoints ; ++t){
		Point.tn = SimulParameters.tStart + (static_cast<float>(t) * dt);

		tmp = this->Parameters.A0;
		tmp += dist(generator);
		tmp *= this->Parameters.Amplitude;
		Point.sig_tn = tmp;

		locSignal.push_back(Point);
	}
		
	return locSignal;
}