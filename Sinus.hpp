/**
 *	@file	Sinus.hpp
 * 	@brief 	Sinus class
 * 	@author	Benjamin
 * 	@date	2023-11
 * 
 */
#ifndef __SINUS_H__
#define	__SINUS_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <filesystem>
#include "Signal.hpp"
#include "Helper.hpp"

constexpr	float 			defaultA0 = 0;			/**< Default offset */
constexpr	float 			defaultAmplitude = 1;	/**< Default amplitude */
constexpr	float 			defaultOmega = 6.28;	/**< Default angular frequency - makes a 1Hz Sine */
constexpr	float 			defaultPhi0 = 0;		/**< Default phase at t=0 */

/**
 *	Sinus class
 */ 	
class Sinus:public Signal{
	private:
		SinusParam Parameters{defaultA0,defaultAmplitude,defaultOmega,defaultPhi0};	/**< 	Signal Parameters 	*/

		virtual	void compute() const noexcept;

	public:
		Sinus()	= default ;				/**< Default Ctor	*/
		virtual ~Sinus() = default;		/**< Default Dtor	*/

		explicit Sinus(const SinusParam &sParam)noexcept:Parameters{sParam}{};	
			
		explicit Sinus(const ComputeParameters &cParam):Signal(cParam){};
		
		Sinus(const SinusParam &sParam, const ComputeParameters &cParam):Signal(cParam),Parameters{sParam}{};


		[[nodiscard]] float getA0()const noexcept {return this->Parameters.A0;};

		[[nodiscard]] float getAmplitude()const noexcept {return this->Parameters.Amplitude;};

		[[nodiscard]] float getOmega()const noexcept {return this->Parameters.Omega;};

		[[nodiscard]] float getPhi0()const noexcept {return this->Parameters.Phi0;};

		void setA0(float A0) noexcept {this->Parameters.A0 = A0;setNeedToRecompute(true);}; 

		void setAmplitude(float Amplitude) noexcept {this->Parameters.Amplitude = Amplitude;setNeedToRecompute(true);};

		void setOmega(float _Omega){if (_Omega < 0) throw std::domain_error("Omega can’t be negative.") ;this->Parameters.Omega = _Omega;setNeedToRecompute(true);};

		void setPhi0(float Phi0) noexcept {this->Parameters.Phi0 = Phi0;setNeedToRecompute(true);};
};

#endif	// __SINUS_H__