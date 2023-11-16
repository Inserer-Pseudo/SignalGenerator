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

// std::vector<SignalPoint> SinusComputeHelper::Compute(const SinusParam &SinusParameters, const ComputeParameters &SimulParameters) const noexcept{
	
	
// 	float 	dt;		/**< Simulation Step		*/
// 	dt = (SimulParameters.tStop - SimulParameters.tStart) / static_cast<float>(SimulParameters.nbPoints);
	
// 	std::vector<SignalPoint> Res{};
// 	SignalPoint	locSP{};
// 	float 	realt;
// 	float 	tmp;
// 	for (unsigned int t = 0 ; t < SimulParameters.nbPoints ; ++t){
// 		realt = SimulParameters.tStart + t * dt;
// 		locSP.tn=realt;
		
// 		tmp = (SinusParameters.Omega * realt) + SinusParameters.Phi0;
// 		tmp = sin(tmp);
// 		tmp *= SinusParameters.Amplitude;
// 		tmp += SinusParameters.A0;
// 		locSP.sig_tn = tmp;
		
// 		Res.push_back(locSP);
// 	} 
	
// 	return Res;
// }	
//----------------------------------------------------------------------
//----------------------------------------------------------------------

