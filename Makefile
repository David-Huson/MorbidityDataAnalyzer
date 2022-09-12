CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

CATCH = test/catch/catch.o

main: main.cpp morbidity.cpp state.cpp stats.cpp week-data.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	./main

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

test-state-object: state.cpp week-data.cpp $(CATCH) test/test-state-object.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-morbidity: morbidity.cpp state.cpp week-data.cpp $(CATCH) test/test-morbidity.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
