#makefile for makeconv
all: main 

main: main.o bsdMake.o genMake.o ruleList.o rule.o
	g++ main.o bsdMake.o genMake.o ruleList.o rule.o -o main

main.o: main.h bsdMake.h genMake.h ruleList.h rule.h global.h
	g++ -c -Wall main.cpp

bsdMake.o: genMake.h bsdMake.h ruleList.h rule.h global.h
	g++ -c -Wall bsdMake.cpp

genMake.o: genMake.h ruleList.h rule.h global.h
	g++ -c -Wall genMake.cpp

ruleList.o: ruleList.h rule.h global.h
	g++ -c -Wall ruleList.cpp

rule.o: rule.h global.h
	g++ -c -Wall rule.cpp

clean:
	rm -rf *.o genMake
