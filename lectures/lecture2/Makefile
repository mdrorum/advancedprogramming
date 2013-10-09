#OPTIONS=-std=c++11 -g -O2 -lstdc++
OPTIONS=-std=c++11 -g -lstdc++

SRCS=$(wildcard *.cpp)

OBJS=$(SRCS:.cpp=)

all: $(OBJS)

%: %.cpp
	g++ $(OPTIONS) $< -o $@

clean: 
	rm -f $(OBJS)
	rm -f tags

.PHONY: all clean
