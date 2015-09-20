#include "image.hh"

void write_static_image(const dtype*x, const dtype*y, const int n, 
	const int timestep, const dtype view_dimension)
{
	CImg<float> image(IMAGE_SIZE,IMAGE_SIZE,1,3,0);
	const float color[] = {255,255,0};
	for(int i=0;i<n;++i)
	{
		dtype max_bounds = 0.5 + view_dimension;
		dtype min_bounds = 0.5 - view_dimension;
		bool xbounds = x[i] < max_bounds and x[i] > min_bounds;
		bool ybounds = y[i] < max_bounds and y[i] > min_bounds;
		if(xbounds and ybounds)
		{
			dtype range = max_bounds - min_bounds;
			int px = (x[i] - min_bounds) / range * IMAGE_SIZE;
			// int py = IMAGE_SIZE - (y[i] - min_bounds) / range * IMAGE_SIZE;
			int py = (y[i] - min_bounds) / range * IMAGE_SIZE;
			// image.draw_circle(px,py,BODY_RADIUS,color);
			image.draw_point(px,py,color);
		}
	}

	char buffer[100];
	sprintf(buffer, "%d", timestep);
	std::string prefix("output/timestep");
	std::string number(buffer);
	std::string suffix(".png");
	std::string imagename = prefix+number+suffix;
	image.save(imagename.c_str());
}

void write_dynamic_image(const dtype*x, const dtype*y, 
	const dtype*xold, const dtype*yold,
	const int n, const int timestep, const dtype view_dimension)
{
	CImg<float> image(IMAGE_SIZE,IMAGE_SIZE,1,3,0);
	const float color[] = {255,255,0};
	for(int i=0;i<n;++i)
	{
		dtype max_bounds = 0.5 + view_dimension;
		dtype min_bounds = 0.5 - view_dimension;
		bool xbounds = x[i] < max_bounds and x[i] > min_bounds;
		bool ybounds = y[i] < max_bounds and y[i] > min_bounds;
		if(xbounds and ybounds)
		{
			dtype range = max_bounds - min_bounds;
			int px = (x[i] - min_bounds) / range * IMAGE_SIZE;
			int py = IMAGE_SIZE - (y[i] - min_bounds) / range * IMAGE_SIZE;
			int pxold = (xold[i] - min_bounds) / range * IMAGE_SIZE;
			int pyold = IMAGE_SIZE - (yold[i] - min_bounds) / range * IMAGE_SIZE;
			// image.draw_circle(px,py,BODY_RADIUS,color);
			image.draw_line(px,py,pxold,pyold,color);
			image.draw_point(px,py,color);
		}
	}

	char buffer[100];
	sprintf(buffer, "%05d", timestep);
	std::string prefix("output/timestep");
	std::string number(buffer);
	std::string suffix(".png");
	std::string imagename = prefix+number+suffix;
	image.save(imagename.c_str());
}
