#include "pch.h"
#include "collisions.hpp"

TEST(Rectangle_And_Point, IsPointInsideRectangle) {
  Point p = {5.0f, 5.0f};
  Rectangle r = {{0.0f, 0.0f}, {10.0f, 10.0f}};
  EXPECT_TRUE(isPointInsideRectangle(p, r));
}

TEST(Rectangle_And_Point, IsPointOutsideRectangle) {
	Point p = { 15.0f, 5.0f };
	Rectangle r = { {0.0f, 0.0f}, {10.0f, 10.0f} };
	EXPECT_FALSE(isPointInsideRectangle(p, r));
}

TEST(Rectangle_And_Point, IsPointOnEdgeOfRectangle) {

	Rectangle r = { {0.0f, 0.0f}, {10.0f, 10.0f} };

	EXPECT_TRUE(isPointInsideRectangle({ 10.0f, 5.0f }, r));//Right Edge
	EXPECT_TRUE(isPointInsideRectangle({ 0.0f, 5.0f }, r));//Left Edge
	EXPECT_TRUE(isPointInsideRectangle({ 5.0f, 0.0f }, r));//Top Edge
	EXPECT_TRUE(isPointInsideRectangle({ 5.0f, 10.0f }, r));//Bottom Edge

}

