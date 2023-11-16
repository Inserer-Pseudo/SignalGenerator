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

constexpr	unsigned int	defaultNbPoints = 100;	/**< Default number of points : 100	*/
constexpr	float 			defaulttStart = 0;		/**< Default start time : 0 (sec)	*/
constexpr	float 			defaulttStop = 1;		/**< Default stop time : 1 (sec)	*/

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

	public:
		Sinus()	= default ;				/**< Default Ctor	*/
		virtual ~Sinus() = default;	

		/**
		 * 	Constructor with Signal parameters 
		 * 
		 * 	@param[in]	Parameter(s) of the sinus signal to create
		 * 
		 * 	noexcept : this method throws no exception 
		 *  explicit : 	the given parameter MUST match the expected
		 * 				parameter. This avoids unintended concversions.
		 * 				cf C++ Core Guidelines C.46 
		 */
		explicit Sinus(const SinusParam &sParam)noexcept:Parameters{sParam}{};	
			
		/**
		 * 	Constructor with Compute parameters 
		 * 
		 * 	@param[in]	Compute Parameter(s) of the sinus signal to create
		 * 
		 * 	explicit : 	the given parameter MUST match the expected
		 * 				parameter. This avoids unintended conversions.
		 * 				cf C++ Core Guidelines C.46 
		 * 
		 * @throw 	std::domain_error("tStart can't be negative.") if the given parameter is negative.
		 * @throw 	std::overflow_error("tStart can’t be greater or equal than tStop.") if the given parameter is >= than tStop.
		 * @throw 	std::domain_error("tStop can’t be negative or null.") if the given parameter is negative or nul.
		 * @throw 	td::invalid_argument("nbPoints must be greater than 0.") if the given parameter is negative or nul.
		 */	
		explicit Sinus(const ComputeParameters &cParam):Signal(cParam){};
		
		/**
		 * 	Constructor with both parameters (signal AND compute) 
		 * 
		 *  @param[in]	Parameter(s) of the dummy signal to create
		 * 	@param[in]	Compute Parameter(s) of the dummy signal to create
		 * 
		 * @throw 	std::domain_error("tStart can't be negative.") if the given parameter is negative.
		 * @throw 	std::overflow_error("tStart can’t be greater or equal than tStop.") if the given parameter is >= than tStop.
		 * @throw 	std::domain_error("tStop can’t be negative or null.") if the given parameter is negative or nul.
		 * @throw 	td::invalid_argument("nbPoints must be greater than 0.") if the given parameter is negative or nul.
		 */
		Sinus(const SinusParam &sParam, const ComputeParameters &cParam):Signal(cParam),Parameters{sParam}{};
};

#endif	// __SINUS_H__