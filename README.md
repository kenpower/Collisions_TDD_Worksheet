# Collisions TDD Worksheet

# Before you write any code

**IMPORTANT** Before you touch the code files, build and run the tests using TestExplorer (CTRL-E, T) to confirm that the code & test setup works. You should see three passing tests.
Do not modify anything until you have confirmed that the tests run successfully.

## Set up the RedGreenGo-Coach

RedGreenGo-Coach is an app that powers a simple “Red/Green/Go” workflow for tracking TDD status and progress in real timea nd give advise as to what to do next


To run it in this  project:

Open a terminal in Visual Studio `CTRL+'`

in the terminal, run this command `python rgg_server.py --class-code AGILE_2026` 

<img width="1460" height="475" alt="image" src="https://github.com/user-attachments/assets/b63a8c7a-586e-4908-98c0-748ab1a04d6a" />


This should open a web browser with the RedGreenGo-Coach[^1] - enter your pair names and "press start". (If no start button or diabled, let Ken know)

[^1]: if the browser window does not open automatically, try this link: [http://127.0.0.1:8000/?helper=1&class=AGILE_2026](http://127.0.0.1:8000/?helper=1&class=AGILE_2026)


Read the rest of this README.md, then follow the instructions from RedGreenGo-Coach (note you must run the test  via test explorer for RedGreenGo-Coach to update for next step)

# Introduction

A C++ worksheet for practising Test-Driven Development (TDD) with Google Test. You will build a function that detects whether two rectangles overlap.

## Existing Code

### `collisions.hpp`
- `Point` - a struct with `x` and `y` floats.
- `Rectangle` - a struct with `topLeft` and `bottomRight` points.
- `isPointInsideRectangle(point, rect)` - returns `true` if the point is inside or on the edge of the rectangle.
- `doRectanglesOverlap(rect1, rect2)` - commented out, with a TODO. This is the function you will build.

Coordinates use screen convention: `x` increases to the right and `y` increases **downwards**. So `topLeft.y <= bottomRight.y`.

### `test.cpp`
Google Test cases:
- `Rectangles.IsPointInsideRectangle` - a point at (5,5) is inside a (0,0)-(10,10) rectangle.
- `Rectangles.IsPointOutsideRectangle` - a point at (15,5) is outside the same rectangle.


## Running the Tests
Open the solution in Visual Studio, then build and run the tests from Test Explorer (**Test > Test Explorer**), or run the project's executable.

## Your Task: Build `doRectanglesOverlap` Using TDD

Implement:

```cpp
bool doRectanglesOverlap(const Rectangle& rect1, const Rectangle& rect2);
```

It returns `true` if the rectangles share any area, and `false` otherwise.

### The TDD cycle
Repeat for each scenario below:
1. **Red** - write one failing test in `test.cpp`.
2. **Green** - write the simplest code in `collisions.hpp` that makes it pass.
3. **Refactor** - tidy the code while keeping all tests green.

Do not write the whole function up front. Let the tests drive it.

### Scenarios to cover
Use a reference rectangle such as `{{0,0},{10,10}}`.

| # | Scenario | Example rect2 | Expected |
|---|----------|---------------|----------|
| 1 | Stub compiles, no overlap | far away, e.g. `{{100,100},{110,110}}` | `false` |
| 2 | Partially overlapping | `{{5,5},{15,15}}` | `true` |
| 3 | Completely to the **left** | `{{-20,0},{-10,10}}` | `false` |
| 4 | Completely to the **right** | `{{20,0},{30,10}}` | `false` |
| 5 | Completely **above** | `{{0,-20},{10,-10}}` | `false` |
| 6 | Completely **below** | `{{0,20},{10,30}}` | `false` |
| 7 | rect2 **enclosed** in rect1 | `{{2,2},{8,8}}` | `true` |
| 8 | rect1 **enclosed** in rect2 | swap the arguments from #7 | `true` |

### Edge cases to consider
- Rectangles that only touch along an edge or corner. Decide whether this counts as overlap, document your choice, and write a test for it.
- Identical rectangles.
- Argument order. `doRectanglesOverlap(a, b)` should equal `doRectanglesOverlap(b, a)`.

### Suggested test names
```cpp
TEST(Rectangles, DoNotOverlapWhenFarApart)
TEST(Rectangles, OverlapWhenPartiallyOverlapping)
TEST(Rectangles, DoNotOverlapWhenLeft)
TEST(Rectangles, DoNotOverlapWhenRight)
TEST(Rectangles, DoNotOverlapWhenAbove)
TEST(Rectangles, DoNotOverlapWhenBelow)
TEST(Rectangles, OverlapWhenEnclosed)
```

### Hints
- Start by uncommenting the stub, which returns `false`.
- Two rectangles do **not** overlap if one is entirely left, right, above or below the other.
- Do not reach for the "answer" before a test forces you to.

### Done when
- Every scenario above has a test.
- All tests pass.
- The code is clean and you can explain why each test exists.

## Stretch Goals
Finished early? See [stretch_goals.md](stretch_goals.md) for more complex tests and extensions.
