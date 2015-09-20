#ifndef POINT_SET_H_
#define POINT_SET_H_

#include <string>
#include <iostream>
#include <fstream>

// This is a point set that is initialized by an input file.
// A particular file format is assumed. See the README.
class PointSet
{
public:
  PointSet(std::string file_name);
  ~PointSet()
  {
    delete[] x_;
    delete[] y_;
  }
private:
  int points_;
  double *x_, *y_;
  double x_min_, x_max_;
  double y_min_, y_max_;

  double minimum(const double* x, const int points);
  double maximum(const double* x, const int points);
  void shift(double* x, const int points, const double shift);
};

#endif