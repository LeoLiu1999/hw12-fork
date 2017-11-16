all: c.c
	gcc -o forko c.c

run: all
	./forko

clean:
	rm forko *~

debug: c.c
	gcc -o debugo -g c.c
