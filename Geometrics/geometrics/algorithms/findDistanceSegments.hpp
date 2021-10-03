#pragma once

#include <iostream>
#include <cmath>
#include "../primitives/segment.hpp"

namespace geometrics
{

	double findDistance(const Segment3D& first, const Segment3D& second);

	class DistanceFunctor {

	public:
		DistanceFunctor(const Segment3D& first, const Segment3D& second);
		double operator() (double s, double t);

	private:
		const Segment3D& _first;
		const Segment3D& _second;
	};

	DistanceFunctor::DistanceFunctor(const Segment3D& first, const Segment3D& second) :
		_first(first), _second(second) {}

	double DistanceFunctor::operator()(double s, double t) {
		return distance(_first.pointFromParameter(s), _second.pointFromParameter(t));
	}


	double findDistance(const Segment3D& first, const Segment3D& second) {
		auto f_v = first.directionVector();
		auto s_v = second.directionVector();
		auto dif_origin = first.vectorToOrigin() - second.vectorToOrigin();

		DistanceFunctor fun(first, second);

		double a = scalar(f_v, f_v);
		double b = scalar(f_v, s_v);
		double c = scalar(s_v, s_v);
		double d = scalar(dif_origin, f_v);
		double e = scalar(dif_origin, s_v);
		double f = scalar(dif_origin, dif_origin);
		// dist(s, t) = |a*s^2 - 2bst + ct^2 + 2ds - 2et + f|

		double det = a * c - b * b;

		double s = 0;
		double t = 0;
		auto in_bounds = [](double value) {
			if (value >= 1) {
				return 1.0;
			}
			else if (value <= 0) {
				return 0.0;
			}
			return value;
		};
		double s_numerator = b * e - c * d;
		double t_numerator = a * e - b * d;
		if (det > 0) {
			if (s_numerator <= 0) {
				if (e <= 0) {
					s = in_bounds(-d / a);
					t = 0;
				}
				else if (e < c) {
					s = 0;
					t = e / c;
				}
				else {
					s = in_bounds((b - d) / a);
					t = 1;
				}
			}
			else {
				if (s_numerator >= det) {
					if ((b + e) <= 0) {
						s = in_bounds(-d / a);
						t = 0;
					}
					else if ((b + e) < c) {
						s = 1;
						t = (b + e) / c;
					}
					else {
						s = in_bounds((b - d) / a);
						t = 1;
					}
				}
				else {
					if (t_numerator <= 0) {
						s = in_bounds(-d / a);
						t = 0;
					}
					else {
						if (t_numerator >= det) {
							s = in_bounds((b - d) / a);
							t = 1;
						}
						else {
							s = s_numerator / det;
							t = t_numerator / det;
						}
					}
				}
			}
		}
		else {
			if (e <= 0) {
				s = in_bounds(-d / a);
				t = 0;
			}
			else if (e >= c) {
				s = in_bounds((b - d) / a);
				t = 1;
			}
			else {
				s = 0;
				t = e / c;
			}
		}

		return fun(s, t);

	}


}



