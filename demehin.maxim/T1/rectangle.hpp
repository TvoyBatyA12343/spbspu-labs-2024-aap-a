#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "polygon.hpp"

namespace demehin
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t left_bot, point_t right_top);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t lb_;
    point_t rt_;
  };

  class RectangleN final: public Shape
  {
  public:
    RectangleN(size_t vrtx_cnt, const point_t* vertex);
    ~RectangleN();
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
