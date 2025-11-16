CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRCS = main.cpp Chip8.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = chip8

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Chip8.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(IBJS) $(TARGET)
