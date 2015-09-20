#include <cstdlib>
#include <fstream>
#include <string>

#include "CImg.h"
#include "types.hh"
#include "image.hh"

int main(int argc,char**argv)
{
	fprintf(stdout, "Locating timestep data from '../output.txt'... ");
	std::string timestep_file("../output.txt");
	std::ifstream infile(timestep_file.c_str());
	if(infile.peek() == std::ifstream::traits_type::eof())
	{
		fprintf(stdout, "\nCould not locate the file. Exiting.\n");
		return EXIT_SUCCESS;
	}
	fprintf(stdout, "Done.\n");

	dtype view_dimension = 5;
	// int trail_length = 2;

	int n = 0;
	infile >> n;
	fprintf(stdout, "Number of bodies: %d\n",n);

	dtype* x = new dtype[n];
	dtype* y = new dtype[n];
	// dtype* x = new dtype[n*(trail_length+1)];
	// dtype* y = new dtype[n*(trail_length+1)];
	// dtype* xold = new dtype[n];
	// dtype* yold = new dtype[n];

	int counter = 0;
	int timestep = 0;
	while (infile >> x[counter] >> y[counter])
	{
    	if(counter == 0) fprintf(stdout, "Timestep %d\n",timestep);
    	// fprintf(stdout, "%f %f\n", x[counter],y[counter]);
    	++counter;
    	if(counter == n)
    	{
    		// if(timestep==0)
    		{
    			write_static_image(x,y,n,timestep,view_dimension);
    		}
    		// else
    		// {
    		// 	write_dynamic_image(x,y,xold,yold,n,timestep,view_dimension);
    		// }
    		counter = 0;
    		++timestep;
    		// dtype* xtmp = x;
    		// dtype* ytmp = y;
    		// x = xold;
    		// y = yold;
    		// xold = xtmp;
    		// yold = ytmp;
    	}
	}
	fprintf(stdout, "Done reading file.\n");



	delete[] x;
	delete[] y;
	// delete[] xold;
	// delete[] yold;

	return EXIT_SUCCESS;
}