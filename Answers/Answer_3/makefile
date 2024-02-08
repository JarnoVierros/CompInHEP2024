tester: tester.o libmeasurement.a
	g++ tester.o -L . -l measurement -o tester

tester.o: tester.cpp
	g++ -c tester.cpp -o tester.o

libmeasurement.a: measurement.o
	ar rcs libmeasurement.a measurement.o

measurement.o: measurement.cpp measurement.h
	g++ -c measurement.cpp -o measurement.o

reset:
	make clean
	-rm libmeasurement.a
	-rm tester

clean:
	-rm *.o
