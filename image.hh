#pragma once

#include <string>

#include "CImg.h"
#include "types.hh"

using namespace cimg_library;

#define IMAGE_SIZE 800
#define BODY_RADIUS 2





void write_static_image(const dtype*x, const dtype*y, const int n, const int timestep, const dtype view_dimension);

void write_dynamic_image(const dtype*x, const dtype*y, 
	const dtype*xold, const dtype*yold,
	const int n, const int timestep, const dtype view_dimension);