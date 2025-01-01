#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
#include "polygon.hpp"

namespace demehin
{
  class Ring final: public Shape
  {
  public:
    Ring(size_t vrt_cnt1, const point_t* vrt1, size_t vrt_cnt2, const point_t* vrt2);
    ~Ring();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    Polygon* inner_plg_;
    Polygon* outer_plg_;
  };
}


#endif
