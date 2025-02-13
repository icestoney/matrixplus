# Makefile settings
.PHONY: all clean test s21_matrix_oop.a gcov_report val check cppcheck test_build 

# File Extension
C_EXT = .cpp
H_EXT = .h

# Runners
CC = g++
LOCAL_GCOVR = gcovr
VALGRIND = valgrind
CPPCHECK = cppcheck
CLANG = clang-format

# Runner's config
CFLAGS = -std=c++17 -Wall -Wextra -Werror -O2
TEST_FLAGS = $(shell pkg-config --cflags --libs gtest)
GCOV_FLAGS = --coverage -lgcov 
GCOVR_FLAGS := --html-details --html-medium-threshold 70.0 --html-high-threshold 80.0

VALGRIND_FLAGS = -s --leak-check=full --show-leak-kinds=all --track-origins=yes
CPPCHECK_FLAGS = --language=c++ --enable=all --suppress=missingIncludeSystem
CLANG_FLAGS = --style=Google -n

# Files and targets
TARGET = s21_matrix_oop.a

SRC_DIRS = . funcs
CFILES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*$(C_EXT)))
HEADERS = $(foreach dir, $(SRC_DIRS) $(TESTS_DIR), $(wildcard $(dir)/*$(H_EXT)))
OFILES = *.o

TEST_TARGET = s21_tests.out
TESTS_DIR = tests
TEST_CFILES = $(foreach dir, $(TESTS_DIR), $(wildcard $(dir)/*$(C_EXT)))

GCOV_TARGET = gcov_report.html
GCOV_DIR = gcov_report
GCOV_REPORT = ./$(GCOV_DIR)/$(GCOV_TARGET)

# Other
export PATH:=${PATH}:$(shell realpath ~/.local/bin):$(shell pwd)/$(TESTS_DIR)

all: test gcov_report

$(TARGET):
	$(CC) $(CFLAGS) -c $(CFILES)
	@echo;
	ar rcs $@ $(OFILES)
	@echo;

test_build: clean $(TARGET)
	$(CC) $(CFLAGS) $(TEST_CFILES) -L. -l:$(TARGET) -o $(TEST_TARGET) $(TEST_FLAGS)

test: test_build
	./$(TEST_TARGET)

gcov_report: clean
	@$(MAKE) test CFLAGS="$(CFLAGS) $(GCOV_FLAGS)"
	@rm -f s21_tests*.gc*
	@mkdir -p $(GCOV_DIR)
	gcovr $(GCOVR_FLAGS) -o $@/$(GCOV_TARGET)
	@rm -f *.gc* $(OFILES)* $(TARGET)

val: test_build
	@$(VALGRIND) $(VALGRIND_FLAGS) ./$(TEST_TARGET)

clang:
	$(CLANG) $(CLANG_FLAGS) *.h */*.cpp */*.h

cppcheck:
	@$(CPPCHECK) $(CPPCHECK_FLAGS) $(CFILES) $(TEST_CFILES) $(HEADERS)

check: clang cppcheck val

gtest:
	sudo apt install libgtest-dev
	sudo apt-get install libtbb-dev
	sudo apt-get install cmake

clean:
	rm -rf *.gcda *.gcno $(TEST_TARGET) \
	$(TARGET) $(TEST_TARGET) $(OFILES) \
	$(GCOV_DIR) $(GCOV_TARGET)
	@echo;