CC = gcc
CFLAGS=-std=c11 -Wall -Wextra -g
GTK_FLAGS=`pkg-config --cflags --libs gtk+-3.0`
GTK_INC=`pkg-config --cflags gtk+-3.0`
MATH_FLAGS=-lm
TEAM_NAME = vychodniari 

.PHONY: All Build Profile Clean Test Pack GetLib

All: Build Profile

Build:
	@mkdir -p build
	$(CC) $(CFLAGS) $(GTK_INC) -c gui.c -o build/gui.o
	$(CC) $(CFLAGS) -c math.c -o build/math.o
	$(CC) $(CFLAGS) build/gui.o build/math.o -o calculator $(GTK_FLAGS) $(MATH_FLAGS)

Profile: Clean
	@mkdir -p build
	$(CC) $(CFLAGS) -pg $(GTK_INC) -c gui.c -o build/gui.o
	$(CC) $(CFLAGS) -pg -c math.c -o build/math.o
	$(CC) $(CFLAGS) -pg build/gui.o build/math.o -o calculator_prof $(GTK_FLAGS) $(MATH_FLAGS)
	./calculator_prof
	gprof calculator_prof gmon.out > profiling_result.txt
	@echo "Profiling complete. Results in profiling_result.txt"

Test:
	@mkdir -p build
	$(CC) $(CFLAGS) -c test_math.c -o build/test_math.o
	$(CC) $(CFLAGS) -c math.c -o build/math.o
	$(CC) $(CFLAGS) build/test_math.o build/math.o -o run_tests $(MATH_FLAGS)
	./run_tests

Pack: Clean
	mkdir -p $(TEAM_NAME)/src
	cp src/*.c src/*.h $(TEAM_NAME)/src/
	cp Makefile Doxyfile $(TEAM_NAME)/
	zip -r $(TEAM_NAME).zip $(TEAM_NAME)
	rm -rf $(TEAM_NAME)

Clean:
	rm -rf build calculator calculator_prof run_tests gmon.out profiling_result.txt $(TEAM_NAME) $(TEAM_NAME).zip ../doxygen_output warning_doxygen.txt

GetLib:
	sudo apt-get update
	sudo apt-get install -y gcc make pkg-config libgtk-3-dev doxygen

