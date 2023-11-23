#ifndef __NOISE_H__
#define	__NOISE_H__

#include <vector>
#include <cmath>
#include <filesystem>
#include "Signal.hpp"
#include "Helper.hpp"

constexpr	float 			NoisedefaultA0 = 0;			/**< Default offset */
constexpr	float 			NoisedefaultAmplitude = 1;	/**< Default amplitude */
constexpr   float           NoisedefaultEcartType =1;    /**< default ecart type*/

/**
 *	Noise class
 */ 	
class Noise:public Signal{
	private:
		NoiseParam Parameters{NoisedefaultA0,NoisedefaultAmplitude,NoisedefaultEcartType};	/**< 	Signal Parameters 	*/

		virtual	void compute() const noexcept;

	public:
		Noise()	= default ;				/**< Default Ctor	*/
		virtual ~Noise() = default;		/**< Default Dtor	*/


		explicit Noise(const NoiseParam &sParam)noexcept:Parameters{sParam}{};	/* création des constructeurs 3 cas différents */
			
		explicit Noise(const ComputeParameters &cParam):Signal(cParam){};
		
		Noise(const NoiseParam &sParam, const ComputeParameters &cParam):Signal(cParam),Parameters{sParam}{};

		/* Gestion des getters */

		[[nodiscard]] float getA0()const noexcept {return this->Parameters.A0;};
		[[nodiscard]] float getAmplitude()const noexcept {return this->Parameters.Amplitude;};
        [[nodiscard]] float getEcartType()const noexcept {return this->Parameters.EcartType;};

		/* Gestion des setters */
		
		void setA0(float A0) noexcept {this->Parameters.A0 = A0;setNeedToRecompute(true);}; 
		void setAmplitude(float Amplitude) noexcept {this->Parameters.Amplitude = Amplitude;setNeedToRecompute(true);};
        void setEcartType(float EcartType) noexcept {this->Parameters.EcartType = EcartType;setNeedToRecompute(true);};

};
#endif	// __NOISE_H__