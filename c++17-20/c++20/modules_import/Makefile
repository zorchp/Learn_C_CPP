cc =g++-12 -g -std=c++20 -fmodules-ts
prom = main
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o)
lib = -lboost_thread \
          -lboost_system \
          -pthread

$(prom):$(obj) $(cc) -o $(prom) $(obj) $(lib)
%.o:%.cpp $(deps) $(cc) -c $< -o $@ $(lib)
