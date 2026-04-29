CC = gcc
CFLAGS=-std=c11 -Wall -Wextra -g
GTK_FLAGS=`pkg-config --cflags --libs gtk+-3.0`
GTK_INC=`pkg-config --cflags gtk+-3.0`
MATH_FLAGS=-lm
TEAM_NAME = vychodniari 

.PHONY: all build test pack doc run stddev clean help

all: build stddev

build:
	@mkdir -p build
	$(CC) $(CFLAGS) $(GTK_INC) -c gui.c -o build/gui.o
	$(CC) $(CFLAGS) -c math.c -o build/math.o
	$(CC) $(CFLAGS) build/gui.o build/math.o -o calculator $(GTK_FLAGS) $(MATH_FLAGS)

test:
	@mkdir -p build
	$(CC) $(CFLAGS) -c test_math.c -o build/test_math.o
	$(CC) $(CFLAGS) -c math.c -o build/math.o
	$(CC) $(CFLAGS) build/test_math.o build/math.o -o run_tests $(MATH_FLAGS)
	./test_math

pack: clean
	mkdir -p ../$(TEAM_NAME)/repo
	cp -r . ../$(TEAM_NAME)/repo
	cd .. && zip -r $(TEAM_NAME).zip $(TEAM_NAME)/repo
	rm -rf ../$(TEAM_NAME)
	@echo "Projekt bol zabalený do $(TEAM_NAME).zip"

doc:
	doxygen Doxyfile

run: build
	./calculator

stddev:
	@mkdir -p build
	$(CC) $(CFLAGS) -pg $(GTK_INC) -c gui.c -o build/gui.o
	$(CC) $(CFLAGS) -pg -c math.c -o build/math.o
	$(CC) $(CFLAGS) -pg build/gui.o build/math.o -o calculator_prof $(GTK_FLAGS) $(MATH_FLAGS)


clean:
	rm -rf build calculator calculator_prof run_tests gmon.out profiling_result.txt $(TEAM_NAME) $(TEAM_NAME).zip ../doxygen_output warning_doxygen.txt

help:
	@echo "Postup pre úspešnú kompiláciu:"
	@echo "1. Nainštalujte dependencies: sudo apt install libgtk-3-dev doxygen"
	@echo "2. Spustite 'make' pre build"
	@echo "3. Spustite 'make run' pre spustenie kalkulačky"
	@echo "4. Spustite 'make test' pre otestovanie matematickej knižnice"
	@echo "5. Spustite 'make doc' pre vygenerovanie dokumentácie pomocou Doxygen"
