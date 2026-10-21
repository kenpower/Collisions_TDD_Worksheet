# Stretch Goals

Extra challenges once `doRectanglesOverlap` passes the core scenarios in the [README](README.md). Keep following TDD: write a failing test first, then make it pass, then refactor.

Reference rectangle used below: `A = {{0,0},{10,10}}`.

## 1. Touching and boundaries
- Shared edge: `{{10,0},{20,10}}` (right edge). Decide whether touching counts as overlap and document the choice. Test the left, top and bottom edges too.
- Shared corner only: `{{10,10},{20,20}}`.
- Tiny overlap: `{{9.999f,9.999f},{20,20}}` should be `true`.
- Tiny gap: `{{10.001f,0},{20,10}}` should be `false`.

## 2. Diagonal and partial positions
- Diagonally apart in each of the four directions, e.g. `{{11,11},{20,20}}`. This catches code that only checks one axis.
- Overlap on x but not y, and on y but not x, e.g. `{{5,20},{15,30}}` should be `false`.
- Corner overlap from each of the four corners.
- Cross shape: `{{-5,4},{15,6}}` and `{{4,-5},{6,15}}`. No corner of either is inside the other, but they overlap. A corner-only check fails this one.
- Edge poke-through: `{{-5,2},{5,8}}` crosses one side only.

## 3. Containment
- Enclosed with a shared edge: `{{0,0},{5,5}}` inside A.
- Identical rectangles.
- Enclosure in both directions (swap the arguments).

## 4. Degenerate inputs
- Zero width or height (a line): inside, outside and on the edge of A.
- Zero area (a point): inside, outside and on the boundary.
- Inverted rectangles where `topLeft` is greater than `bottomRight`. Either normalise them or document that they are invalid.

## 5. Numeric cases
- Negative coordinates, with both rectangles fully negative.
- Rectangles spanning the origin: `{{-5,-5},{5,5}}`.
- Very large values (e.g. `1e9f`) and very small fractions.

## 6. Property-style tests
Loop over a list of rectangle pairs and check:
- **Symmetry:** `overlap(a,b) == overlap(b,a)`.
- **Reflexivity:** every non-degenerate rectangle overlaps itself.
- **Translation invariance:** shifting both rectangles by the same offset doesn't change the result.
- **Consistency with `isPointInsideRectangle`:** if any corner of one rectangle is inside the other, they must overlap.

## 7. Test structure
- Refactor repeated tests into a parameterised test (`TEST_P` with `INSTANTIATE_TEST_SUITE_P`) over a table of `{rectA, rectB, expected}`.
- Use a test fixture (`TEST_F`) with a shared reference rectangle.

## 8. Further extensions
- Add `getOverlapArea(rect1, rect2)` that returns the area of the intersection, or `0` if none.
- Add `getOverlapRectangle(rect1, rect2)` that returns the intersecting rectangle.
- Add a `Circle` struct with `doCirclesOverlap` and `doesCircleOverlapRectangle`.
