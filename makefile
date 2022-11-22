#dictionery 
CC = gcc -c
CFLAGS = -Wall -g
CLIBSA = ar rcs
CLOBSO = gcc -shared -o

all : mains maindloop maindrec libclassloops.a libclassrec.a libclassloops.so libclassrec.so

.PHONY : clean
clean : 
	rm -rf *.o *.a *.so mains maindloop maindrec 

loops : libclassloops.a
recursives : libclassrec.a
loopd : libclassloops.so
recursived : libclassrec.so

mains : main.o libclassrec.a 
	gcc -Wall main.o ./libclassrec.a -o mains -lm
maindloop : main.o libclassloops.so 
	gcc -Wall main.o ./libclassloops.so -o maindloop -lm
maindrec : main.o libclassrec.so
	gcc -Wall main.o ./libclassrec.so -o maindrec -lm



libclassloops.a : basicClassification.o advancedClassificationLoop.o 
	$(CLIBSA) libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	$(CLIBSA) libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassloops.so : basicClassification.o advancedClassificationLoop.o
	$(CLOBSO) libclassloops.so basicClassification.o advancedClassificationLoop.o

libclassrec.so : basicClassification.o advancedClassificationRecursion.o
	$(CLOBSO) libclassrec.so basicClassification.o advancedClassificationRecursion.o



advancedClassificationLoop.o : advancedClassificationLoop.c NumClass.h 
	$(CC) $(CFLAGS) -fPIC advancedClassificationLoop.c

advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -fPIC advancedClassificationRecursion.c

basicClassification.o : basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -fPIC basicClassification.c

main.o : main.c NumClass.h
	$(CC) $(CFLAGS) main.c 



