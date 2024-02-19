#ifndef CONTAINER_H
#define CONTAINER_H
#include "Point.h"

class Container {
public:
    virtual bool isEmpty() = 0;
    virtual void add(Point value) = 0;
    virtual Point getItem(int index) = 0;
    virtual void remove(std::string value) = 0;
    virtual bool search(std::string value) = 0;
    virtual std::string getList() = 0;
    virtual void insertAfter(std::string targetName, Point newValue) = 0;
    virtual void clear() = 0;
    virtual int size() = 0;
};

#endif // CONTAINER_H