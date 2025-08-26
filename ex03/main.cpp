#include <iostream>
#include "Point.hpp" // Assumes Point.hpp contains the Point class and bsp function declaration
#include "Fixed.hpp" // Assumes Fixed.hpp is included for the Fixed class

// Helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << "Test " << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Helper function to compare Fixed values with a small tolerance for floating-point precision
bool areEqual(const Fixed& a, const Fixed& b, float tolerance = 0.0001f) {
    float diff = (a.toFloat() - b.toFloat());
    return diff < tolerance && diff > -tolerance;
}

// Test Point class: Constructors, Copy Constructor, Copy Assignment, and Destructor
void testPointClass() {
    // Test 1: Default Constructor
    {
        Point p;
        bool passed = areEqual(p.getX(), Fixed(0)) && areEqual(p.getY(), Fixed(0));
        printTestResult("Default Constructor (x=0, y=0)", passed);
    }

    // Test 2: Parameterized Constructor
    {
        Point p(1.5f, 2.5f);
        bool passed = areEqual(p.getX(), Fixed(1.5f)) && areEqual(p.getY(), Fixed(2.5f));
        printTestResult("Parameterized Constructor (x=1.5, y=2.5)", passed);
    }

    // Test 3: Copy Constructor
    {
        Point p1(3.0f, 4.0f);
        Point p2(p1);
        bool passed = areEqual(p1.getX(), p2.getX()) && areEqual(p1.getY(), p2.getY());
        printTestResult("Copy Constructor", passed);
    }

    // Test 4: Copy Assignment Operator
    {
        Point p1(5.0f, 6.0f);
        Point p2;
        p2 = p1;
        bool passed = areEqual(p1.getX(), p2.getX()) && areEqual(p1.getY(), p2.getY());
        printTestResult("Copy Assignment Operator", passed);
    }

    // Test 5: Const Correctness (ensuring x and y are const)
    {
        Point p(7.0f, 8.0f);
        // Note: Cannot test setting x or y directly since they are private and const
        // Instead, verify getters return expected values
        bool passed = areEqual(p.getX(), Fixed(7.0f)) && areEqual(p.getY(), Fixed(8.0f));
        printTestResult("Const Correctness of x and y", passed);
    }
}

// Test bsp function: Inside, Outside, Vertex, Edge cases
void testBspFunction() {
    // Define a triangle with vertices A(0,0), B(4,0), C(0,4)
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 4.0f);

    // Test 6: Point inside the triangle
    {
        Point p(1.0f, 1.0f); // Inside triangle
        bool result = bsp(a, b, c, p);
        printTestResult("Point Inside Triangle (1,1)", result == true);
    }

    // Test 7: Point outside the triangle
    {
        Point p(5.0f, 5.0f); // Outside triangle
        bool result = bsp(a, b, c, p);
        printTestResult("Point Outside Triangle (5,5)", result == false);
    }

    // Test 8: Point on vertex A
    {
        Point p(0.0f, 0.0f); // Vertex A
        bool result = bsp(a, b, c, p);
        printTestResult("Point on Vertex A (0,0)", result == false);
    }

    // Test 9: Point on vertex B
    {
        Point p(4.0f, 0.0f); // Vertex B
        bool result = bsp(a, b, c, p);
        printTestResult("Point on Vertex B (4,0)", result == false);
    }

    // Test 10: Point on vertex C
    {
        Point p(0.0f, 4.0f); // Vertex C
        bool result = bsp(a, b, c, p);
        printTestResult("Point on Vertex C (0,4)", result == false);
    }

    // Test 11: Point on edge AB
    {
        Point p(2.0f, 0.0f); // On edge AB
        bool result = bsp(a, b, c, p);
        printTestResult("Point on Edge AB (2,0)", result == false);
    }

    // Test 12: Point on edge BC
    {
        Point p(2.0f, 2.0f); // On edge BC (line from (4,0) to (0,4))
        bool result = bsp(a, b, c, p);
        printTestResult("Point on Edge BC (2,2)", result == false);
    }

    // Test 13: Point on edge CA
    {
        Point p(0.0f, 2.0f); // On edge CA
        bool result = bsp(a, b, c, p);
        printTestResult("Point on Edge CA (0,2)", result == false);
    }

    // Test 14: Degenerate triangle (collinear points)
    {
        Point a2(0.0f, 0.0f);
        Point b2(2.0f, 0.0f);
        Point c2(4.0f, 0.0f); // Collinear with a2 and b2
        Point p(1.0f, 1.0f);
        bool result = bsp(a2, b2, c2, p);
        printTestResult("Degenerate Triangle (collinear points)", result == false);
    }

    // Test 15: Point very close to edge but inside
    {
        Point p(0.01f, 0.01f); // Very close to vertex A but inside
        bool result = bsp(a, b, c, p);
        printTestResult("Point very close to Vertex A but inside (0.01,0.01)", result == true);
    }

    // Test 16: Negative coordinates
    {
        Point a2(-2.0f, -2.0f);
        Point b2(2.0f, -2.0f);
        Point c2(0.0f, 2.0f);
        Point p(0.0f, 0.0f); // Inside triangle
        bool result = bsp(a2, b2, c2, p);
        printTestResult("Triangle with Negative Coordinates, Point Inside (0,0)", result == true);
    }
}

int main() {
    std::cout << "=== Testing Point Class ===" << std::endl;
    testPointClass();
    std::cout << "\n=== Testing BSP Function ===" << std::endl;
    testBspFunction();
    return 0;
}