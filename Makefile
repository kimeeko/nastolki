all: main.o nastolki.o
        gcc main.o nastolki.o
main.o:
        gcc -c main.c
nastolki.o:
        gcc -c nastolki.c
clean:
        rm *.o
        rm a.out
