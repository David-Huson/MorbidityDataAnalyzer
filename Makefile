CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

CATCH = test/catch/catch.o

main: TO_DO_DEPENDENCIES
	TO_DO_COMMAND

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* $(CATCH) test/test-stats test/test-week-object test/test-state-object test/test-morbidity core main

test-all: test-stats test-week-object test-state-object test-morbidity

test-week-object: TO_DO_DEPENDENCIES $(CATCH) test/test-week-object.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-stats: TO_DO_DEPENDENCIES $(CATCH) test/test-stats.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-state-object: TO_DO_DEPENDENCIES $(CATCH) test/test-state-object.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-morbidity: TO_DO_DEPENDENCIES $(CATCH) test/test-morbidity.cpp
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
