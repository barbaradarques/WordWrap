all:
	g++ src/*.cpp -I./include -o ./build/wrapper -lm -std=c++11
run:
	./build/wrapper < entrada.txt
val:
	g++ src/*.cpp -I./include -o ./build/wrapper -lm -std=c++11 -g -O0
	valgrind --leak-check=yes ./build/wrapper  < entrada.txt
git:
	git add --all
	git commit -m "$m"
	git push