#pragma once

#include <cmath>
#include <ostream>

namespace geometrics
{

	class Base3D {

	public:
		virtual ~Base3D() {}

		double x() const {
			return _x;
		}

		double y() const {
			return _y;
		}

		double z() const {
			return _z;
		}

		bool operator==(const Base3D& other) const {
			return _x == other._x && _y == other._y && _z == other._z;
		}

		bool operator!=(const Base3D& other) const {
			return !(*this == other);
		}

	protected:
		double _x;
		double _y;
		double _z;

		Base3D() : _x(0), _y(0), _z(0) {}
		Base3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
		Base3D(const Base3D& other) = delete;

		inline double weight() const {
			return sqrt(_x * _x + _y * _y + _z * _z);
		}
	};


	//class Point3D definition
	class Point3D : public Base3D {
	public:
		Point3D();
		Point3D(double x, double y, double z);
		Point3D(const Point3D& other);

		Point3D& operator=(const Point3D& other);

		friend double distance(const Point3D& fp, const Point3D& sp);
	};

	Point3D operator+(const Point3D& lp, const Point3D& rp);
	Point3D operator-(const Point3D& lp, const Point3D& rp);
	std::ostream& operator<<(std::ostream& os, const Point3D& p);


	Point3D::Point3D() :
		Base3D() {}

	Point3D::Point3D(double x, double y, double z) :
		Base3D(x, y, z) {}

	Point3D::Point3D(const Point3D& other) :
		Base3D(other._x, other._y, other._z) {}

	Point3D& Point3D::operator=(const Point3D& other) {
		_x = other._x;
		_y = other._y;
		_z = other._z;
		return *this;
	}

	Point3D operator+(const Point3D& lp, const Point3D& rp) {
		return Point3D(lp.x() + rp.x(), lp.y() + rp.y(), lp.z() + rp.z());
	}

	Point3D operator-(const Point3D& lp, const Point3D& rp) {
		return Point3D(lp.x() - rp.x(), lp.y() - rp.y(), lp.z() - rp.z());
	}

	double distance(const Point3D& fp, const Point3D& sp) {
		return (sp - fp).weight();
	}

	std::ostream& operator<<(std::ostream& os, const Point3D& p) {
		os << "Point3D(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
		return os;
	}

}