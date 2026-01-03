
CXX		:= clang++
CXXFLAGS:= -std=c++17 -O3 $(shell pkg-config --cflags librtlsdr)
LDFLAGS := $(shell pkg-config --libs librtlsdr) -lpthread

TARGET	:= testThread
SRCS 	:= testThread.cc

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)