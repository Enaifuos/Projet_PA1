survival:	survival.c
	gcc survival.c `sdl-config --cflags --libs` -o survival

clean:
	rm survival
