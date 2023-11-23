/**
 *	@file	Noise.hpp
 * 	@brief 	Noise class
 * 	@author	Benjamin
 * 	@date	2023-11
 * 
 */
#ifndef __Noise_H__
#define	__Noise_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <filesystem>
#include "Signal.hpp"
#include "Helper.hpp"

constexpr	float 			NoiseDefaultA0 = 0;			/**< Default offset */
constexpr	float 			NoiseDefaultAmplitude = 1;	/**< Default amplitude */

/**
 *	Noise class
 */
class Noise:public Signal{
	private:
		NoiseParam Parameters{NoiseDefaultA0,NoiseDefaultAmplitude};	/**< 	Signal Parameters 	*/

		virtual	void compute() const noexcept;

	public:
		Noise()	= default ;				/**< Default Ctor	*/
		virtual ~Noise() = default;		/**< Default Dtor	*/

		explicit Noise(const NoiseParam &sParam)noexcept:Parameters{sParam}{};	
			
		explicit Noise(const ComputeParameters &cParam):Signal(cParam){};
		
		Noise(const NoiseParam &sParam, const ComputeParameters &cParam):Signal(cParam),Parameters{sParam}{};

		[[nodiscard]] float getA0()const noexcept {return this->Parameters.A0;};

		[[nodiscard]] float getAmplitude()const noexcept {return this->Parameters.Amplitude;};

		void setA0(float A0) noexcept {this->Parameters.A0 = A0;setNeedToRecompute(true);}; 

		void setAmplitude(float Amplitude) noexcept {this->Parameters.Amplitude = Amplitude;setNeedToRecompute(true);};
};

#endif	// __Noise_H__