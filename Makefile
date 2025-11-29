all:
	mkdir -p ./bin
	gcc -oFast ./src/main.c -o ./bin/bce

debug:
	mkdir -p ./bin
	gcc ./src/main.c -o ./bin/bce

run: all
	./bin/bce

clean:
	rm -rf ./bin
