CXX := g++
CXXFLAGS := -std=c++11 -Wall
LDFLAGS := -lcryptopp

SRCS := main.cpp fcrypt.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := fcrypt

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)


