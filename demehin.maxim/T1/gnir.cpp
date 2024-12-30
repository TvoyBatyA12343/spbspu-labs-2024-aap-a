#include "ring.hpp"
#include <stdexcept>
#include <cmath>

namespace
{
  double getPlgSide(const demehin::point_t* vrt)
  {
    double vector_x = vrt[1].x - vrt[0].x;
    double vector_y = vrt[1].y - vrt[0].y;
    return std::sqrt(vector_x * vector_x + vector_y * vector_y);
  }
}

demehin::RingN::RingN(size_t vrt_cnt1, const point_t* vrt1, size_t vrt_cnt2, const point_t* vrt2):
  inner_plg_(nullptr),
  outer_plg_(nullptr)
{
  double len1 = getPlgSide(vrt1);
  double len2 = getPlgSide(vrt2);
  if (len1 == len2 || vrt_cnt1 != 13 || vrt_cnt2 != 13)
  {
    throw std::logic_error("incorrect_shape");
  }

  try
  {
    if (len1 > len2)
    {
      inner_plg_ = new demehin::Polygon(vrt_cnt2, vrt2);
      outer_plg_ = new demehin::Polygon(vrt_cnt1, vrt1);
    }
    else
    {
      inner_plg_ = new demehin::Polygon(vrt_cnt1, vrt1);
      outer_plg_ = new demehin::Polygon(vrt_cnt2, vrt2);
    }
  }
  catch (const std::bad_alloc& e)
  {
    delete inner_plg_;
    delete outer_plg_;
    throw;
  }
  catch (const std::logic_error& e)
  {
    delete inner_plg_;
    delete outer_plg_;
    throw;
  }

}

demehin::RingN::~RingN()
{
  delete inner_plg_;
  delete outer_plg_;
}

double demehin::RingN::getArea() const
{
  return outer_plg_->getArea() - inner_plg_->getArea();
}

demehin::rectangle_t demehin::RingN::getFrameRect() const
{
  return outer_plg_->getFrameRect();
}

void demehin::RingN::move(point_t s)
{
  inner_plg_->move(s);
  outer_plg_->move(s);
}

void demehin::RingN::move(double x, double y)
{
  inner_plg_->move(x, y);
  outer_plg_->move(x, y);
}

void demehin::RingN::scale(double k)
{
  inner_plg_->scale(k);
  outer_plg_->scale(k);
}
