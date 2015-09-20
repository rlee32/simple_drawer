#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include <iostream>

#include "CImg.h"

#define IMAGE_SIZE 800
#define PIXEL_PADDING 25

void write_points(double* x, double* y, const int points);
void write_lines(double* x, double* y, const int points);

#endif