compile:
	clang++ flying_bird.cpp -o flying_bird -lSDL2 -lSDL2_image -l SDL2_ttf
run:
	./flying_bird
clean:
	rm -rf flying_bird
