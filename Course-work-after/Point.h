#pragma once
#include <iostream>

// Определение класса Point
class Point
{
    int x;
    int y;
    std::string name;
public:
    Point()
    {
        x = 0; y = 0; name = "undefinded";
    }
    Point(int x, int y, std::string name)
    {
        this->x = x;
        this->y = y;
        this->name = name;
    }
    ~Point()
    {
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    std::string getName()
    {
        return name;
    }
};


