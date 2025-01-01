#include "rectangle.hpp"
#include <stdexcept>

demehin::Rectangle::Rectangle(size_t vrtx_cnt, const point_t* vertex):
  plg_(nullptr)
{
  if (vrtx_cnt != 4)
  {
    throw std::logic_error("incorrect_shape");
  }
  plg_ = new demehin::Polygon(vrtx_cnt, vertex);
}

demehin::Rectangle::~Rectangle()
{
  delete plg_;
}

double demehin::Rectangle::getArea() const
{
  return plg_->getArea();
}

demehin::rectangle_t demehin::Rectangle::getFrameRect() const
{
  return plg_->getFrameRect();
}

void demehin::Rectangle::move(point_t s)
{
  plg_->move(s);
}

void demehin::Rectangle::move(double x, double y)
{
  plg_->move(x, y);
}

void demehin::Rectangle::scale(double k)
{
  plg_->scale(k);
}
