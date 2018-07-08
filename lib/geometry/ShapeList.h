#pragma once

#include "Shape.h"

namespace Millipede {

class ShapeList {
    Shape **list;
    int size;
public:
    ShapeList() {}
    ShapeList(Shape **list, int size) : list(list), size(size) {};
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& hit_record) const;
};

}