#pragma once

struct Point {
	float x;
	float y;
};

struct Rectangle {
	Point topLeft;
	Point bottomRight;
};

bool isPointInsideRectangle(const Point& point, const Rectangle& rect) {
	bool isInsideOnXaxis = (point.x >= rect.topLeft.x && point.x <= rect.bottomRight.x);
	bool isInsideOnYaxis = (point.y >= rect.topLeft.y && point.y <= rect.bottomRight.y);

	return isInsideOnXaxis && isInsideOnYaxis;
}



//bool doRectanglesOverlap(const Rectangle& rect1, const Rectangle& rect2) {
// TODO: Implement the function to check if two rectangles overlap
//	return false;
//}

