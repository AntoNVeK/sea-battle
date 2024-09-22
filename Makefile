# Компилятор и флаги
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++2a


SRCS := src/main.cpp src/source/Ship.cpp src/source/ManagerShips.cpp src/source/Table.cpp
OBJS := $(SRCS:.cpp=.o)


TARGET := game


all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для компиляции .cpp файлов в .o файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I src/headers -c $< -o $@

# Зависимости
src/main.o: src/main.cpp src/headers/Ship.h src/headers/ManagerShips.h
src/source/Ship.o: src/source/Ship.cpp src/headers/Ship.h
src/source/ManagerShips.o: src/source/ManagerShips.cpp src/headers/ManagerShips.h
src/source/Table.o: src/source/Table.cpp src/headers/Table.h
# Правило для очистки
clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean
