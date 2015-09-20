// C++ Simple Image Maker
// Author: Robert Lee
// Created: Fall 2015

#include <cstdlib>

#include <iostream>
#include <fstream>
#include <string>

#include "CImg.h"

#include "image.h"

using namespace std;

int main(int argc,char**argv)
{
  if (argc < 2) 
  {
    cout << "\nUsage: ./run <input_file_name> <line_flag>\n"
      << "\tinput_file_name: path of the input file.\n" 
      << "\tline_flag: optional. If set to 1, then lines will be drawn in\n"
      << "\t\tbetween the points. If set to 0, only points will be drawn.\n"
      << endl;
    return EXIT_SUCCESS;
  }

	string file_name(argv[1]);
  bool drawlines = (argc > 2) ? stoi(argv[2]) : 0;

	ifstream file_stream(file_name.c_str());
	if(file_stream.peek() == std::ifstream::traits_type::eof())
	{
		cout << "\nCould not locate the file. Exiting.\n\n";
		return EXIT_SUCCESS;
	}

	int points = 0;
	file_stream >> points;
	cout << "Number of points: " << points << endl;

	double* x = new double[points];
	double* y = new double[points];

  bool success = true;
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

  if(success)
  {
    if (drawlines)
    {
      write_lines(x,y,points);
    }
    else
    {
      write_points(x,y,points);
    }
  }

	delete[] x;
	delete[] y;

	return EXIT_SUCCESS;
}