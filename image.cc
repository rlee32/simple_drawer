#include "image.h"

using namespace cimg_library;
using namespace std;

// Returns the minimum value of an array.
double minimum(const double* x, const int points)
{
  double minimum = x[0];
  for (int i=0;i<points;++i) minimum = ( x[i] < minimum ) ? x[i] : minimum;
  return minimum;
}

// Returns the maximum value in an array.
double maximum(const double* x, const int points)
{
  double maximum = x[0];
  for (int i=0;i<points;++i) maximum = ( x[i] > maximum ) ? x[i] : maximum;
  return maximum;
}

// Adds the shift value to an entire array.
void shift(double* x, const int points, const double shift)
{
  for (int i=0;i<points;++i) x[i] += shift;
}

// Writes an image of the points in the data set.
void write_points(double* x, double* y, const int points)
{
  const double color[] = {255,255,0};
  double x_max = maximum(x,points);
  double y_max = maximum(y,points);
  double x_min = minimum(x,points);
  double y_min = minimum(y,points);

  shift(x,points,-x_min);
  shift(y,points,-y_min);

  double x_range = x_max - x_min;
  double y_range = y_max - y_min;

  double max_range = ( x_range > y_range ) ? x_range : y_range;
  double pixel_range = IMAGE_SIZE - 2*PIXEL_PADDING;
  double to_pixels = pixel_range / max_range;

  int x_pixels = x_range*to_pixels + 2*PIXEL_PADDING;
  int y_pixels = y_range*to_pixels + 2*PIXEL_PADDING;

  CImg<double> image( x_pixels, y_pixels,
    1, // Layers.
    3, // Color channels.
    0 // Initialization color value.
  );

  for ( int i = 0; i < points; ++i )
  {
    int px = PIXEL_PADDING + (x[i]*to_pixels);
    int py = PIXEL_PADDING + y_range*to_pixels - (y[i]*to_pixels);
    // image.draw_circle(px,py,5,color);
    image.draw_point(px,py,color);
  }

  string image_name("output.png");
  image.save(image_name.c_str());
}

// Writes an image of the lines connecting the points in the data set, in 
// order.
void write_lines(double* x, double* y, const int points)
{
  const double color[] = {255,255,0};
  double x_max = maximum(x,points);
  double y_max = maximum(y,points);
  double x_min = minimum(x,points);
  double y_min = minimum(y,points);

  shift(x,points,-x_min);
  shift(y,points,-y_min);

  double x_range = x_max - x_min;
  double y_range = y_max - y_min;

  double max_range = ( x_range > y_range ) ? x_range : y_range;
  double pixel_range = IMAGE_SIZE - 2*PIXEL_PADDING;
  double to_pixels = pixel_range / max_range;

  int x_pixels = x_range*to_pixels + 2*PIXEL_PADDING;
  int y_pixels = y_range*to_pixels + 2*PIXEL_PADDING;

  CImg<double> image( x_pixels, y_pixels,
    1, // Layers.
    3, // Color channels.
    0 // Initialization color value.
  );

  int* px = new int[points];
  int* py = new int[points];

  for ( int i = 0; i < points; ++i )
  {
    px[i] = PIXEL_PADDING + (x[i]*to_pixels);
    py[i] = PIXEL_PADDING + y_range*to_pixels - (y[i]*to_pixels);
  }

  for ( int i = 0; i < points-1; ++i )
  {
    image.draw_line(px[i],py[i],px[i+1],py[i+1],color);
  }
  image.draw_line(px[points-1],py[points-1],px[0],py[0],color);

  delete[] px;
  delete[] py;

  string image_name("output.png");
  image.save(image_name.c_str());
}