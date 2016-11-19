survival:	survival.c
	gcc -g survival.c `sdl-config --cflags --libs ` -o survival

clean:
	rm survival
