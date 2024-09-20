
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++2a


SRCS := src/main.cpp src/source/Ship.cpp src/source/ManagerShips.cpp
OBJS := $(SRCS:.cpp=.o)


TARGET := game


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Ïðàâèëî äëÿ êîìïèëÿöèè .cpp ôàéëîâ â .o ôàéëû
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I src/headers -c $< -o $@


src/main.o: src/main.cpp src/headers/Ship.h src/headers/ManagerShips.h
src/source/Ship.o: src/source/Ship.cpp src/headers/Ship.h
src/source/ManagerShips.o: src/source/ManagerShips.cpp src/headers/ManagerShips.h


clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean
