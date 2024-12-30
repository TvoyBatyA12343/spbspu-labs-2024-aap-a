#include "rectangle.hpp"
#include <stdexcept>

demehin::RectangleN::RectangleN(size_t vrtx_cnt, const point_t* vertex):
  plg_(nullptr)
{
  if (vrtx_cnt != 4)
  {
    throw std::logic_error("incorrect_shape");
  }
  plg_ = new demehin::Polygon(vrtx_cnt, vertex);
}

demehin::RectangleN::~RectangleN()
{
  delete plg_;
}

double demehin::RectangleN::getArea() const
{
  return plg_->getArea();
}

demehin::rectangle_t demehin::RectangleN::getFrameRect() const
{
  return plg_->getFrameRect();
}

void demehin::RectangleN::move(point_t s)
{
  plg_->move(s);
}

void demehin::RectangleN::move(double x, double y)
{
  plg_->move(x, y);
}

void demehin::RectangleN::scale(double k)
{
  plg_->scale(k);
}
