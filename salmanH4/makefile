H4.out : salmanH4.o Real.o
	g++ -g -o H4.out salmanH4.o Real.o

salmanH4.o : salmanH4.cpp Real.h
	g++ -g -c salmanH4.cpp

Real.o : Real.cpp Real.h
	g++ -g -c Real.cpp

clean : 
	rm *.o H4.out *.gch

run:
	./H4.out input.txt

submit : salmanH4.cpp Real.h Real.cpp
	rm -rf salmanH4
	mkdir salmanH4
	cp salmanH4.cpp salmanH4
	cp input.txt salmanH4
	cp Real.h salmanH4
	cp Real.cpp salmanH4	
	cp makefile salmanH4
	cp README.txt salmanH4
	tar cfvz salmanH4.tgz salmanH4
	cp salmanH4.tgz ~tiawatts/cs460drop
