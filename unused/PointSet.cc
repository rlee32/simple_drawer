#include "PointSet.h"

using namespace std;

PointSet::PointSet(std::string file_name) : points_(0)
{
  ifstream file_stream(file_name.c_str());

  if(file_stream.peek() == std::ifstream::traits_type::eof())
  {
    cout << "\nCould not locate the file. Exiting.\n\n";
  }
  int points = 0;
  file_stream >> points;
  cout << "Number of points: " << points << endl;
  if (points > 0)
  {
    x_ = new double[points];
    y_ = new double[points];
  }
  for(int i = 0; i < points; ++i)
  {
    int point_id;
    file_stream >> point_id >> x[i] >> y[i];
    if ( point_id != i+1 )
    {
      cout << "Error! The point id did not match the iteration number!" << 
        endl;
      cout << "Exiting at iteration number " << i << "\n";
      success = false;
      break;
    }
  }
  cout << "Done reading the input file!" << endl;

  x_min_ = minimum(x_, points);
  y_min_ = minimum(y_, points);
  x_max_ = maximum(x_, points);
  y_max_ = maximum(y_, points);

  
}

// Returns the minimum value of an array.
double PointSet::minimum(const double* x, const int points)
{
  double minimum = x[0];
  for (int i=0;i<points;++i) minimum = ( x[i] < minimum ) ? x[i] : minimum;
  return minimum;
}

// Returns the maximum value in an array.
double PointSet::maximum(const double* x, const int points)
{
  double maximum = x[0];
  for (int i=0;i<points;++i) maximum = ( x[i] > maximum ) ? x[i] : maximum;
  return maximum;
}

// Adds the shift value to an entire array.
void PointSet::shift(double* x, const int points, const double shift)
{
  for (int i=0;i<points;++i) x[i] += shift;
}