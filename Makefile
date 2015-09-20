CXX = c++
CXXFLAGS = -O3 -g -Wall
LDFLAGS = -lX11 -lpthread

SRCS = driver.cc image.cc
OBJS = $(SRCS:.cc=.o)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS) 

run: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *~ run $(OBJS)