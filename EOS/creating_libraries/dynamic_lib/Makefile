main: main.o add.o sub.o
	gcc -o main main.o add.o sub.o
main.o:
	gcc -c main.c
add.o:
	gcc -c add.c
sub.o:
	gcc -c sub.c
clean:
	rm -rf *.o
lib:
	gcc -o libvk.so add.o sub.o -shared -fPIC
