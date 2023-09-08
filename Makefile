compile:
	g++ flying_bird.cpp -o flying_bird `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -l SDL2_ttf
run:
	./flying_bird
clean:
	rm -rf flying_bird
gitpush:
	git add .
	git commit -m "$(commit)"
	git push origin main -f
