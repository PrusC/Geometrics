#pragma once

#include "point.hpp"
#include "vector.hpp"

namespace geometrics
{

	class Segment3D {
	public:
		Segment3D() = default;
		Segment3D(const Point3D& origin, const Point3D& end);
		Segment3D(const Segment3D& other);

		double length() const;
		Vector3D directionVector() const;
		Vector3D vectorToOrigin() const;

		Point3D pointFromParameter(double parameter) const;
		Segment3D& operator=(const Segment3D& other);

	private:
		Point3D _origin;
		Point3D _end;
		Vector3D _direction_vector;
	};


	Segment3D::Segment3D(const Point3D& origin, const Point3D& end) :
		_origin(origin), _end(end), _direction_vector(end - origin) {}

	Segment3D::Segment3D(const Segment3D& other) :
		_origin(other._origin), _end(other._end), _direction_vector(other._direction_vector) {}

	double Segment3D::length() const {
		return distance(_origin, _end);
	}

	Vector3D Segment3D::directionVector() const {
		return _direction_vector;
	}

	Vector3D Segment3D::vectorToOrigin() const {
		return Vector3D(_origin);
	}

	Point3D Segment3D::pointFromParameter(double parameter) const {
		if (parameter <= 0) {
			return _origin;
		}
		else if (parameter >= 1) {
			return _end;
		}
		return _origin + _direction_vector * parameter;
	}

	Segment3D& Segment3D::operator=(const Segment3D& other) {
		_origin = other._end;
		_end = other._end;
		_direction_vector = Vector3D(_end - _origin);
		return *this;
	}

}
