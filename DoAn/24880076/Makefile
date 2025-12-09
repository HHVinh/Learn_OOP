CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Wno-unused-variable -Wno-unused-but-set-variable
TARGET = QuanLyCuaHang

CPP_FILES = $(wildcard *.cpp)

all: $(TARGET)

$(TARGET): $(CPP_FILES)
	@echo "🔨 Compiling..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(CPP_FILES)
	@echo "✅ Build successful! (No errors)"

clean:
	rm -f $(TARGET)

run: $(TARGET)
	@echo "🚀 Running program..."
	@echo "========================================"
	./$(TARGET)

.PHONY: all clean run