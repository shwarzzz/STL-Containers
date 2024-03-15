CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
LFLAGS = -lgtest 
SOURCE = ./tests/*.cc
MAIN_TEST = ./tests/main_tests.cc
TESTS_EXECUTABLE = test array_test map_test multiset_test set_test vector_test list_test stack_test queue_test

ifeq ($(shell uname), Linux)
  LFLAGS += -lpthread 
endif

all: clean test

clean:
	@rm -rf $(TESTS_EXECUTABLE) *.gcno *.gcda report test.info

test:
	@$(CC) $(CFLAGS) $(SOURCE) $(LFLAGS) -o test
	./test

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) $(LFLAGS) -o test --coverage
	@./test
	@lcov -t "test" -o test.info -c -d . -no-external --include */src/s21_containers/*.h 
	@genhtml -o report test.info
	@open report/index.html

array_test:
	@$(CC) $(CFLAGS) ./tests/array_tests.cc $(MAIN_TEST) $(LFLAGS) -o array_test
	./array_test

map_test:
	@$(CC) $(CFLAGS) -g ./tests/map_tests.cc $(MAIN_TEST) $(LFLAGS) -o map_test
	./map_test

multiset_test:
	@$(CC) $(CFLAGS) ./tests/multiset_tests.cc $(MAIN_TEST) $(LFLAGS) -o multiset_test
	./multiset_test

set_test:
	@$(CC) $(CFLAGS) ./tests/set_tests.cc $(MAIN_TEST) $(LFLAGS) -o set_test
	./set_test

vector_test:
	@$(CC) $(CFLAGS) ./tests/vector_tests.cc $(MAIN_TEST) $(LFLAGS) -o vector_test
	./vector_test

list_test:
	@$(CC) $(CFLAGS) ./tests/list_tests.cc $(MAIN_TEST) $(LFLAGS) -o list_test
	./list_test

stack_test:
	@$(CC) $(CFLAGS) ./tests/stack_tests.cc $(MAIN_TEST) $(LFLAGS) -o stack_test
	./stack_test

queue_test:
	@$(CC) $(CFLAGS) ./tests/queue_tests.cc $(MAIN_TEST) $(LFLAGS) -o queue_test
	./queue_test

.PHONY: all clean test gcov_report 