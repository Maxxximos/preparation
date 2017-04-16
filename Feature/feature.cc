/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   feature.cc
 * Author: mzhirkov
 *
 * Created on February 20, 2017, 12:46 PM
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>

class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    Circle(std::pair<double, double> center_point, double radius)
        : point(center_point), radius(radius) {};

    void draw() { std::cout << "Draw Circle\n"; }

private:
    std::pair<double, double> point;
    double radius;
};

class Poligon : public Shape
{
public:
    Poligon(std::vector<std::pair<double, double>> points, int size)
        : points(points), size(size) {};
    void draw() { std::cout << "Draw Poligon\n"; }

private:
    std::vector<std::pair<double, double>> points;
    int size;
};

int main(int argc, char* argv[])
{
    std::vector<std::pair<double, double>> poly_points;

    std::vector<std::shared_ptr<Shape>> vec = 
        { 
            std::make_shared<Circle>(std::make_pair(1, 2), 3), 
            std::make_shared<Poligon>(poly_points, 10),
            std::make_shared<Circle>(std::make_pair(3, 4), 6)
        };

    for (auto element : vec)
    {
        element->draw();
    }
    return 0;
}
