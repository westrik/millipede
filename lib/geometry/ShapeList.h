#pragma once

#include <vector>

#include "Shape.h"

namespace Millipede {

class ShapeList {
    std::vector<std::shared_ptr<Shape > > shape_list;
public:
    ShapeList() {}
    ~ShapeList() {}
    ShapeList(std::vector<std::shared_ptr<Shape > > list) { shape_list = list; };
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& hit_record) const;
};

}