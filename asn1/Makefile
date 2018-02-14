CXX=g++
CXXFLAGS= -std=c++1y -g -fprofile-arcs -ftest-coverage

LINKFLAGS= -lgtest

SRC_DIR = src
SRCS = $(filter-out $(SRC_DIR)/Main.cpp, $(wildcard $(SRC_DIR)/*.cpp))

TEST_DIR = test

GMOCK = /usr/src/gmock/gmock-all.cc -lpthread

SRC_INCLUDE = include
TEST_INCLUDE = test
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

MEMCHECK_DIR = memcheck

MEMCHECK_GAME_RESULTS = game.xml
MEMCHECK_TEST_RESULTS = test.xml

CPPCHECK_DIR = cppcheck

CPPCHECK_RESULTS = results.xml

PROGRAM = cardGame
PROGRAM_TEST = testGame

.PHONY: all
all: $(PROGRAM) $(PROGRAM_TEST) memcheck-test coverage docs style
# Don't put memcheck-game here because that won't complete without input

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o obj *.gcov *.gcda *.gcno $(COVERAGE_RESULTS) $(MEMCHECK_DIR) $(COVERAGE_DIR) $(CPPCHECK_DIR)


.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM) $(PROGRAM_TEST) docs

$(PROGRAM):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRC_DIR)/*.cpp $(LINKFLAGS)

game: $(PROGRAM)

$(PROGRAM_TEST):
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRCS) $(LINKFLAGS) $(GMOCK)
	$(PROGRAM_TEST)

test: $(PROGRAM_TEST)

memcheck-game: $(PROGRAM)
	mkdir -p $(MEMCHECK_DIR)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_DIR)/$(MEMCHECK_GAME_RESULTS) $(PROGRAM)

memcheck-test: $(PROGRAM_TEST)
	mkdir -p $(MEMCHECK_DIR)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_DIR)/$(MEMCHECK_TEST_RESULTS) $(PROGRAM_TEST)

coverage: $(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/asn1/src/*" -o $(COVERAGE_RESULTS)
	# Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	# Remove all of the generated files from gcov
	rm -f *.gc*
	mv $(COVERAGE_RESULTS) $(COVERAGE_DIR)/$(COVERAGE_RESULTS)

style: ${SRC_DIR}
	mkdir -p $(CPPCHECK_DIR)
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${TEST_DIR} ${INCLUDE} --suppress=missingInclude &> $(CPPCHECK_DIR)/$(CPPCHECK_RESULTS)

static: style

docs:
	doxygen
