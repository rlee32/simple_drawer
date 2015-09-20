This C++ code reads in point coordinates and outputs images of points or segments 
drawn between points. CImg is used.

# Input File Format

If we denote 'N' as the number of points, the following point coordinate file 
format is assumed:

<N>
1 <x-coordinate> <y-coordinate>
2 <x-coordinate> <y-coordinate>
3 <x-coordinate> <y-coordinate>
4 <x-coordinate> <y-coordinate>
....
<N> <x-coordinate> <y-coordinate>

# Compilation

Compile with 'make'.

# Examples

After compiling, you can run the following examples.

1. ./run examples/usa13509.tsp
1. ./run examples/test.inp 1


