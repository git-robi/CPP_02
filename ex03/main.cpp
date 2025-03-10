/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:25:04 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/10 11:25:06 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

void printTestResult(const char* testName, bool result) {
    std::cout << testName << ": " << (result ? "PASS" : "FAIL") << std::endl;
}

int main(void)
{
    // Test 1: Point inside a triangle
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(2.0f, 2.0f);  // Point clearly inside the triangle
        printTestResult("Test 1 (Point inside triangle)", bsp(a, b, c, point));
    }

    // Test 2: Point outside triangle
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(5.0f, 5.0f);  // Point clearly outside the triangle
        printTestResult("Test 2 (Point outside triangle)", !bsp(a, b, c, point));
    }

    // Test 3: Point on vertex
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(0.0f, 0.0f);  // Point on vertex A
        printTestResult("Test 3 (Point on vertex)", !bsp(a, b, c, point));
    }

    // Test 4: Point on edge
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(2.0f, 0.0f);  // Point on base edge
        printTestResult("Test 4 (Point on edge)", !bsp(a, b, c, point));
    }

    // Test 5: Point very close to edge (but inside)
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(2.0f, 0.1f);  // Point very close to base edge but inside
        printTestResult("Test 5 (Point near edge - inside)", bsp(a, b, c, point));
    }

    // Test 6: Point outside - left side
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(-1.0f, 2.0f);  // Point to the left of the triangle
        printTestResult("Test 6 (Point outside - left)", !bsp(a, b, c, point));
    }

    // Test 7: Point outside - right side
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(5.0f, 2.0f);  // Point to the right of the triangle
        printTestResult("Test 7 (Point outside - right)", !bsp(a, b, c, point));
    }

    // Test 8: Point outside - below
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(2.0f, -1.0f);  // Point below the triangle
        printTestResult("Test 8 (Point outside - below)", !bsp(a, b, c, point));
    }

    // Test 9: Point outside - near vertex
    {
        Point a(0.0f, 0.0f);
        Point b(4.0f, 0.0f);
        Point c(2.0f, 4.0f);
        Point point(2.1f, 4.1f);  // Point just outside top vertex
        printTestResult("Test 9 (Point outside - near vertex)", !bsp(a, b, c, point));
    }

    return 0;
}
