main:	main.o add.o sub.o 
	gcc -o main main.o add.o sub.o
main:
	gcc -c main.c
add.o:
	gcc -c add.c 
sub.o:
	gcc -c sub.c
clean:
	rm -rf *.o main
lib:
	ar -cvr libvk.a add.o sub.o
dyna:
	gcc -o libv.so add.o sub.o -shared -fPIC
