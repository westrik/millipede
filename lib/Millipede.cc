#include "lib/Millipede.h"

#include "lib/Vector.h"
#include "lib/Ray.h"
#include "lib/Colour.h"
#include "lib/Output.h"

namespace Millipede {

Colour colour(const Ray& ray) {
    Vector unit_direction = unit_vector(ray.direction());
}
void render() {
}

}
