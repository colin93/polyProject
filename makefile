objects := createPoly.o deletePoly.o addPoly.o subPoly.o polyMultDivNorm.o polyPrint.o polyOrder.o insertElement.o polyCopy.o fillPoly.o polyPointers.o polyMain.o
exec := $(objects) polyProgram

all: $(exec)

createPoly.o: createPoly.c poly.h
	gcc -Wall -ggdb -c createPoly.c
	
deletePoly.o: deletePoly.c poly.h
	gcc -Wall -ggdb -c deletePoly.c

addPoly.o: addPoly.c poly.h
	gcc -Wall -ggdb -c addPoly.c

subPoly.o: subPoly.c poly.h
	gcc -Wall -ggdb -c subPoly.c

polyMultDivNorm.o: polyMultDivNorm.c poly.h
	gcc -Wall -ggdb -c polyMultDivNorm.c

polyPrint.o: polyPrint.c poly.h
	gcc -Wall -ggdb -c polyPrint.c

polyOrder.o: polyOrder.c poly.h
	gcc -Wall -ggdb -c polyOrder.c

insertElement.o: insertElement.c poly.h
	gcc -Wall -ggdb -c insertElement.c

polyCopy.o: polyCopy.c poly.h
	gcc -Wall -ggdb -c polyCopy.c

fillPoly.o: fillPoly.c poly.h
	gcc -Wall -ggdb -c fillPoly.c
	
polyPointers.o: polyPointers.c poly.h
	gcc -Wall -ggdb -c polyPointers.c

polyMain.o: polyMain.c poly.h
	gcc -Wall -ggdb -c polyMain.c

polyProgram: $(objects)
	gcc -o polyProgram $(objects)
	
	
clean:
	rm $(exec) *.o *~ *#


