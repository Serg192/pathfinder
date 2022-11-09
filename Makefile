FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

pathfinder: install

install:
	make -C ./libmx
	clang $(FLAGS) -I libmx/inc src/*.c -L ./libmx -lmx -o pathfinder

uninstall: clean
	rm -rf obj
	rm -rf pathfinder
	make uninstall -C ./libmx

clean:
	rm -rf obj

reinstall: all
