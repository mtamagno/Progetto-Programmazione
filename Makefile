Test.exe: Test.c Makefile
	gcc -ansi -Wall -O Test.c Progetto.c -o Test.exe
pulisci:
 	rm -f Test.o
pulisci_tutto:
	rm -f Test.exe Test.o