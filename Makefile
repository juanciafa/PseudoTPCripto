CCFLAGS= -Wall -g
CC= g++ 

all: tp clean
data_test: data_main clean
stree_test: stree_main clean
sensor_test: sensor_main clean

data_main: mainData.o data.o
	$(CC) $(CCFLAGS) -o data_test mainData.o data.o

stree_main: mainSeg.o data.o segment_tree.o
	$(CC) $(CCFLAGS) -o seg_test mainSeg.o data.o segment_tree.o

sensor_main: mainSensor.o data.o segment_tree.o sensor.o
	$(CC) $(CCFLAGS) -o sen_test mainSensor.o data.o segment_tree.o sensor.o

mainSensor.o: mainSensor.cpp data.h Array.h segment_tree.h sensor.h
	$(CC) $(CCFLAGS) -c mainSensor.cpp -o mainSensor.o 

mainData.o: mainData.cpp data.h
	$(CC) $(CCFLAGS) -c mainData.cpp -o mainData.o 

mainSeg.o: mainSeg.cpp data.h Array.h segment_tree.h
	$(CC) $(CCFLAGS) -c mainSeg.cpp -o mainSeg.o 

sensor.o: sensor.cpp sensor.h Array.h segment_tree.h data.h
	$(CC) $(CCFLAGS) -c sensor.cpp -o sensor.o 

data.o: data.cpp data.h
	$(CC) $(CCFLAGS) -c data.cpp -o data.o 

segment_tree.o: segment_tree.cpp segment_tree.h data.h Array.h
	$(CC) $(CCFLAGS) -c segment_tree.cpp -o segment_tree.o 

tp: main.o cmdline.o 
	$(CC) $(CCFLAGS) -o testArray main.o cmdline.o 

main.o: main.cpp Array.h cmdline.h 
	$(CC) $(CCFLAGS) -c main.cpp -o main.o 

cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CCFLAGS) -c cmdline.cc -o cmdline.o 

Tests: 
	./testArray -i testAnda.txt > salida.txt
	diff -q salida.txt salAnda.txt
	./testArray -i testDifDim.txt > salida.txt
	diff -q salida.txt salDifDim.txt
	./testArray -i testLet.txt > salida.txt
	diff -q salida.txt salLet.txt
	./testArray -i testNoP.txt > salida.txt
	diff -q salida.txt salNoP.txt

TestValgrind:
	valgrind --leak-check=full ./testArray -i testAnda.txt
	valgrind --leak-check=full ./testArray -i testDifDim.txt
	valgrind --leak-check=full ./testArray -i testLet.txt
	valgrind --leak-check=full ./testArray -i testNoP.txt

clean:
	$(RM) *.o 
