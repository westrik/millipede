#pragma once

#include <vector>
#include <memory>

#include "Shape.h"

namespace Millipede {

class ShapeList : public Shape {
    std::vector<std::shared_ptr<Shape> > shape_list;
public:
    ShapeList() {}
    ~ShapeList() {}
    ShapeList(std::vector<std::shared_ptr<Shape> > list) : shape_list(list) {};
    virtual bool hit(const Ray& r, double t_min, double t_max, 
        std::shared_ptr<HitRecord>& hit_record) const;
};

}