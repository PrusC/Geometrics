#include <iostream>

#include "geometrics/primitives/segment.hpp"
#include "geometrics/algorithms/findDistanceSegments.hpp"

using namespace std;
using namespace geometrics;

int main() {
	{
		Segment3D s1(Point3D(1, 1, -34), Point3D(3, 3, 6));
		Segment3D s2(Point3D(3, 2, 64), Point3D(3, 3, 6));
		cout << findDistance(s1, s2) << endl;
	}

	{
		Segment3D s1(Point3D(4, -2, 5), Point3D(3, 3, 0));
		Segment3D s2(Point3D(14, 2, 40), Point3D(-4, 0, 0));
		cout << findDistance(s1, s2) << endl;
	}

	{
		Segment3D s1(Point3D(1, 1, -2), Point3D(4, 4, -2));
		Segment3D s2(Point3D(1, 2, -2), Point3D(3, 4, -2));
		cout << findDistance(s1, s2) << endl;
	}

	{
		Segment3D s1(Point3D(1, 1, 0), Point3D(3, 3, 0));
		Segment3D s2(Point3D(3, 2, 0), Point3D(5, 3, 0));
		cout << findDistance(s1, s2) << endl;
	}


}
