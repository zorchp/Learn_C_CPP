objects=file1.o file2.o file3.o file4.o

all:main.out
	@echo "build completed!"

main.out: $(objects)
	@echo $<
	gcc -o $@ $^
# c++    -c -o file1.o file1.cpp
# c++    -c -o file2.o file2.cpp
# c++    -c -o file3.o file3.cpp
# c++    -c -o file4.o file4.cpp
# file1.o
# gcc -o main file1.o file2.o file3.o file4.o
# build completed!
file1.o: file.h file1.cpp
#	gcc -c file.h file1.cpp # can be deduced automatically
file2.o: file.h file2.cpp
#	gcc -c file.h file2.cpp
file3.o: file.h file3.cpp
#	gcc -c file.h file3.cpp
file4.o: file.h file4.cpp
#	gcc -c file.h file4.cpp

clean:
	@echo "cleaning..."
	-rm  $(objects) main file.h.gch
	@echo "clean completed!"

.PHONY:clean



foo=$(bar)
bar=hello

run:
	./main.out
