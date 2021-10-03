#pragma once

#include "point.hpp"

namespace geometrics
{

	class Vector3D : public Base3D {
	public:
		Vector3D();
		Vector3D(double x, double y, double z);
		Vector3D(const Vector3D& other);
		Vector3D(const Point3D& p);

		double length() const;
		Point3D coordinates() const;
		double scalar(const Vector3D& other) const;
		Vector3D cross(const Vector3D& other) const;
		void normalize();

		Vector3D& operator=(const Vector3D& other);

	};


	Vector3D operator+(const Vector3D& lv, const Vector3D& rv);
	Vector3D operator-(const Vector3D& lv, const Vector3D& rv);
	Vector3D operator*(const Vector3D& v, const double f);
	Vector3D operator*(const double f, const Vector3D& v);
	Point3D operator+(const Point3D& p, const Vector3D& v);
	std::ostream& operator<<(std::ostream& os, const Vector3D& v);
	double scalar(const Vector3D& lv, const Vector3D& rv);
	Vector3D cross(const Vector3D& lv, const Vector3D& rv);

	Vector3D::Vector3D() :
		Base3D() {}

	Vector3D::Vector3D(double x, double y, double z) :
		Base3D(x, y, z) {}

	Vector3D::Vector3D(const Vector3D& other) :
		Base3D(other._x, other._y, other._z) {}

	Vector3D::Vector3D(const Point3D& p) :
		Base3D(p.x(), p.y(), p.z()) {}

	double Vector3D::length() const {
		return weight();
	}

	Point3D Vector3D::coordinates() const {
		return Point3D(_x, _y, _z);
	}

	double Vector3D::scalar(const Vector3D& other) const {
		if (length() == 0.0 || other.length() == 0.0) {
			return 0.0;
		}
		return _x * other._x + _y * other._y + _z * other._z;
	}

	Vector3D Vector3D::cross(const Vector3D& other) const {
		double x = _y * other._z - _z * other._y;
		double y = _z * other._x - _x * other._z;
		double z = _x * other._y - _y * other._x;
		return Vector3D(x, y, z);
	}

	void Vector3D::normalize() {
		double norm = length();
		if (norm != 0) {
			_x /= norm;
			_y /= norm;
			_z /= norm;
		}
	}

	Vector3D& Vector3D::operator=(const Vector3D& other) {
		_x = other._x;
		_y = other._y;
		_z = other._z;
		return *this;
	}

	Vector3D operator+(const Vector3D& lv, const Vector3D& rv) {
		return Vector3D(lv.x() + rv.x(), lv.y() + rv.y(), lv.z() + rv.z());
	}

	Vector3D operator-(const Vector3D& lv, const Vector3D& rv) {
		return Vector3D(lv.x() - rv.x(), lv.y() - rv.y(), lv.z() - rv.z());
	}

	Vector3D operator*(const Vector3D& v, const double f) {
		return Vector3D(v.x() * f, v.y() * f, v.z() * f);
	}

	Vector3D operator*(const double f, const Vector3D& v) {
		return v * f;
	}

	Point3D operator+(const Point3D& p, const Vector3D& v) {
		auto x = p.x() + v.x();
		auto y = p.y() + v.y();
		auto z = p.z() + v.z();
		return Point3D(x, y, z);
	}

	std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
		os << "Vector3D(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
		return os;
	}

	double scalar(const Vector3D& lv, const Vector3D& rv) {
		return lv.scalar(rv);

	}

	Vector3D cross(const Vector3D& lv, const Vector3D& rv) {
		return lv.cross(rv);
	}

}



