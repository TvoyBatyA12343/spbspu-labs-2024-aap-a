#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "polygon.hpp"

namespace demehin
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(size_t vrtx_cnt, const point_t* vertex);
    ~Rectangle();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    Polygon* plg_;
  };
}

#endif
