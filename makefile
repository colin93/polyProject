objects := polycreadel.o addPoly.o subPoly.o polyMultDivNorm.o fillPoly.o printPoly.o polyOrder.o insertElement.o polyPointers.o polyMain.o
exec := $(objects) polyProgram runProgram

all: $(exec)

polycreadel.o: polycreadel.c poly.h
	gcc -Wall -ggdb -c polycreadel.c

addPoly.o: addPoly.c poly.h
	gcc -Wall -ggdb -c addPoly.c

subPoly.o: subPoly.c poly.h
	gcc -Wall -ggdb -c subPoly.c

fillPoly.o: fillPoly.c poly.h
	gcc -Wall -ggdb -c fillPoly.c

polyMultDivNorm.o: polyMultDivNorm.c poly.h
	gcc -Wall -ggdb -c polyMultDivNorm.c

printPoly.o: printPoly.c poly.h
	gcc -Wall -ggdb -c printPoly.c

polyOrder.o: polyOrder.c poly.h
	gcc -Wall -ggdb -c polyOrder.c

insertElement.o: insertElement.c poly.h
	gcc -Wall -ggdb -c insertElement.c

polyPointers.o: polyPointers.c poly.h
	gcc -Wall -ggdb -c polyPointers.c

polyMain.o: polyMain.c poly.h
	gcc -Wall -ggdb -c polyMain.c

polyProgram: $(objects)
	gcc -o polyProgram $(objects)

runProgram: polyProgram
	./polyProgram

clean:
	rm $(exec) *.o *#


