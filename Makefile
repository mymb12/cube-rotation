all:
	clang++ main.cpp -std=c++20 -I/opt/homebrew/Cellar/sdl2/2.30.4/include -L/opt/homebrew/Cellar/sdl2/2.30.4/lib -lSDL2 -I/opt/homebrew/Cellar/sdl2/2.30.4/include/SDL2 -D_THREAD_SAFE -L/opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib -lSDL2_image -I/opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2 -o prog
