// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// math.h
//
// Currently just a few constants
// Adapted from Ogre3D

#ifndef MATH_H
#define MATH_H

#include <cstdlib>
#include <algorithm>
#include "Vector3.h"

#undef min
#undef max

namespace T3D
{

	class Math
	{
	public:
        static const float PI;
        static const float TWO_PI;
        static const float HALF_PI;
		static const float DEG2RAD;
		static const float RAD2DEG;
		static const float LOG2;
		static const float SQRT2;
		static const float SQRT3;

		static float lerp(float first, float second, float t){ return t*(second-first)+first; }

		static float** generateFractal(int size, float min, float max, float roughness, bool tile = false);

		/*! randRange
		  Generates a random value in a given range
		  \param minimum	range from 
		  \param maximum	range to 
		  */
		static float randRange(float minimum, float maximum){ 
			float r = float(rand())/RAND_MAX;
			return r*(maximum-minimum)+minimum; 
		}

		static Vector3 randRange(Vector3 minimum, Vector3 maximum) {
			return Vector3(
				randRange(minimum.x, maximum.x),
				randRange(minimum.y, maximum.y),
				randRange(minimum.z, maximum.z));
		}

		/*! randRangeND
		  Generates a random value in a given range with an
		  approximation of a normal distribution, uses Central
		  limit theorem.
		  \param minimum	range from 
		  \param maximum	range to 
		  \param maximum	iterations (more for better distribution curve)
		  */
		static float randRangeND(float minimum, float maximum, int iterations=3){ 
			float r = 0;
			for (int i=0; i<iterations; i++)
				r += float(rand())/RAND_MAX;
			return r / (float)iterations * (maximum - minimum) + minimum; 
		}

		static float clamp(float value, float minimum, float maximum){ 
			return std::max(
				std::min(maximum,value),minimum
				); 
		}

		template <float(*M)(float, float)>
		inline static Vector3 merge(Vector3 left, Vector3 right) {
			return Vector3(
				M(left.x, right.x),
				M(left.y, right.y),
				M(left.z, right.z));
		}

		inline static Vector3 minvec(Vector3 left, Vector3 right) {
			return merge<std::fminf>(left, right);
		}

		inline static Vector3 maxvec(Vector3 left, Vector3 right) {
			return merge<std::fmaxf>(left, right);
		}
	};
}

#endif

