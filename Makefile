CXX=g++
CXXFLAGS= -std=c++0x -g -fprofile-arcs -ftest-coverage

LINKFLAGS= -lgtest

PROJECT_DIR = VincentCote

SRC_DIR = src
SRCS = $(SRC_DIR)/Card.cpp $(SRC_DIR)/Deck.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/GameUI.cpp $(SRC_DIR)/GoFish.cpp $(SRC_DIR)/GoFishUI.cpp $(SRC_DIR)/Player.cpp

TEST_DIR = test

GMOCK = /usr/src/gmock/gmock-all.cc -lpthread
#GMOCK = -L. -lgmock -lgmock_main -lpthread

SRC_INCLUDE = include
TEST_INCLUDE = test
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

MEMCHECK_RESULTS = ValgrindOut.xml

STATIC_RESULTS = CppCheckResults.xml

PROGRAM = cardGame
PROGRAM_TEST = testGame

.PHONY: all
all: $(PROGRAM) coverage docs static

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o *.gcov *.gcda *.gcno $(COVERAGE_RESULTS) $(PROGRAM) $(PROGRAM_TEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR) $(STATIC_RESULTS) docs


.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM) $(PROGRAM_TEST)

$(PROGRAM):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRC_DIR)/*.cpp $(LINKFLAGS)

$(PROGRAM_TEST): $(TEST_DIR)/*.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRCS) $(LINKFLAGS) $(GMOCK)
	$(PROGRAM_TEST)

memcheck-game: $(PROGRAM)
	rm -f
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM)


memcheck-test: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_RESULTS) $(PROGRAM_TEST)

coverage: $(PROGRAM_TEST)
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/$(PROJECT_DIR)/src/*" -o $(COVERAGE_RESULTS)
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	rm -f *.gc*

static: ${SRC_DIR}
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${TEST_DIR} ${INCLUDE} --suppress=missingInclude &> $(STATIC_RESULTS)

docs: ${SRC_INCLUDE}
	doxygen doxyfile
