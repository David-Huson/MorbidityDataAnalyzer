CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

CATCH = test/catch/catch.o

main: main.o morbidity.o state.o stats.o week-data.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./main < main-input-1.txt
	./main < main-input-2.txt
	./main < main-input-3.txt

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* $(CATCH) test/test-stats test/test-week-object test/test-state-object test/test-morbidity core main

test-all: test-stats test-week-object test-state-object test-morbidity

test-week-object: week-data.cpp $(CATCH) test/test-week-object.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-stats: stats.cpp week-data.cpp $(CATCH) test/test-stats.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-state-object: state.cpp stats.cpp week-data.cpp $(CATCH) test/test-state-object.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-morbidity: morbidity.cpp state.cpp week-data.cpp stats.cpp $(CATCH) test/test-morbidity.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

catch.o: test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -c $<

week-data.o: week-data.cpp
	$(CXX) $(CXXFLAGS) -c $<

stats.o: stats.cpp week-data.cpp
	$(CXX) $(CXXFLAGS) -c $<

state.o: state.cpp stats.cpp week-data.cpp
	$(CXX) $(CXXFLAGS) -c $<

morbidity.o: morbidity.cpp state.cpp week-data.cpp stats.cpp
	$(CXX) $(CXXFLAGS) -c $<