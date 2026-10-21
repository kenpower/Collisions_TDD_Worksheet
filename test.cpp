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

	// One logical concept per test, not one expect per test.

// Multiple EXPECT_* calls in a single test are appropriate when they're all verifying the same behavior or scenario with different values. 
// You should split into separate tests when the assertions test distinct, independent behaviors.
// in this case we are testing one behavior four times to be confident 
// it holds generally, not just for one lucky coordinate.

	EXPECT_TRUE(isPointInsideRectangle({ 10.0f, 5.0f }, r));//Right Edge
	EXPECT_TRUE(isPointInsideRectangle({ 0.0f, 5.0f }, r));//Left Edge
	EXPECT_TRUE(isPointInsideRectangle({ 5.0f, 0.0f }, r));//Top Edge
	EXPECT_TRUE(isPointInsideRectangle({ 5.0f, 10.0f }, r));//Bottom Edge

}

