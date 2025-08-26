#include <iomanip>
#include "bsp.hpp"

// Helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << "Test " << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test bsp function: Basic cases with multiple triangles, adjusted for _fr_bits=8
void testBspFunction() {
    // Triangle 1: A(0,0), B(4,0), C(0,4) - Right triangle
    Point a1(0.0f, 0.0f);
    Point b1(4.0f, 0.0f);
    Point c1(0.0f, 4.0f);

    // Test 1: Point clearly inside Triangle 1
    {
        Point p(1.0f, 1.0f);
        bool result = bsp(a1, b1, c1, p);
        printTestResult("Triangle 1: Point Inside (1,1)", result == true);
    }

    // Test 2: Point clearly outside Triangle 1
    {
        Point p(5.0f, 5.0f);
        bool result = bsp(a1, b1, c1, p);
        printTestResult("Triangle 1: Point Outside (5,5)", result == false);
    }

    // Test 3: Point on vertex A of Triangle 1
    {
        Point p(0.0f, 0.0f);
        bool result = bsp(a1, b1, c1, p);
        printTestResult("Triangle 1: Point on Vertex A (0,0)", result == false);
    }

    // Test 4: Point on edge BC of Triangle 1 (midpoint)
    {
        Point p(2.0f, 2.0f);
        bool result = bsp(a1, b1, c1, p);
        printTestResult("Triangle 1: Point on Edge BC (2,2)", result == false);
    }

    // Triangle 2: A(1,1), B(2,4), C(5,2) - Scalene triangle
    Point a2(1.0f, 1.0f);
    Point b2(2.0f, 4.0f);
    Point c2(5.0f, 2.0f);

    // Test 5: Point clearly inside Triangle 2
    {
        Point p(2.0f, 2.0f);
        bool result = bsp(a2, b2, c2, p);
        printTestResult("Triangle 2: Point Inside (2,2)", result == true);
    }

    // Test 6: Point clearly outside Triangle 2
    {
        Point p(6.0f, 5.0f);
        bool result = bsp(a2, b2, c2, p);
        printTestResult("Triangle 2: Point Outside (6,5)", result == false);
    }

    // Test 7: Point on vertex B of Triangle 2
    {
        Point p(2.0f, 4.0f);
        bool result = bsp(a2, b2, c2, p);
        printTestResult("Triangle 2: Point on Vertex B (2,4)", result == false);
    }

    // Test 8: Point on edge CA of Triangle 2 (midpoint)
    {
        Point p(3.0f, 1.5f);
        bool result = bsp(a2, b2, c2, p);
        printTestResult("Triangle 2: Point on Edge CA (3,1.5)", result == false);
    }

    // Triangle 3: A(0,0), B(2,4), C(5,0) - Scalene triangle
    Point a3(0.0f, 0.0f);
    Point b3(2.0f, 4.0f);
    Point c3(5.0f, 0.0f);

    // Test 9: Point clearly inside Triangle 3
    {
        Point p(2.0f, 2.0f);
        bool result = bsp(a3, b3, c3, p);
        printTestResult("Triangle 3: Point Inside (2,2)", result == true);
    }

    // Test 10: Point clearly outside Triangle 3
    {
        Point p(6.0f, 5.0f);
        bool result = bsp(a3, b3, c3, p);
        printTestResult("Triangle 3: Point Outside (6,5)", result == false);
    }

    // Test 11: Point on vertex C of Triangle 3
    {
        Point p(5.0f, 0.0f);
        bool result = bsp(a3, b3, c3, p);
        printTestResult("Triangle 3: Point on Vertex C (5,0)", result == false);
    }

    // Test 12: Point on edge AB of Triangle 3 (midpoint)
    {
        Point p(1.0f, 2.0f);
        bool result = bsp(a3, b3, c3, p);
        printTestResult("Triangle 3: Point on Edge AB (1,2)", result == false);
    }
}

int main() {
    std::cout << "=== Testing BSP Function ===" << std::endl;
    testBspFunction();
    std::cout << "\nAll tests completed!" << std::endl;
    return 0;
}