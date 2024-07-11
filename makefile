CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS = -lbenchmark -lflatbuffers -lprotobuf -pthread

SRCS = main.cc data_generator.cc serializers.cc data_generator_string.cc ProtoData.pb.cc
# TODO: add -lprotobuf to LDFLAGS and testData.pb.cc to SRCS

# e.g) g++ test.cpp testData.pb.cc -o test -lprotobuf
OBJS = $(SRCS:.cc=.o)
TARGET = benchmark_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
