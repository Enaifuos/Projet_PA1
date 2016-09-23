sdlmove:	sdlmove.c
	g++ sdlmove.c `sdl-config --cflags --libs` -o sdlmove

clean:
	rm sdlmove
