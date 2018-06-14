# Project Mouse makefile
XX = g++  
CFLAGS = -g   
CLIBS = -lpthread

TARGET = main
OBJ = main.o

$(TARGET): $(OBJ)
	$(XX) $(OBJ) -o $(TARGET)

main.o: main.cpp
	$(XX) -c main.cpp -o main.o



.PHONY : clean
clean:
	@echo "Removing *.o files <xianmin>"
	-rm $(OBJ) 