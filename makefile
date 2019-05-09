
plot.png: onda.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: ejercicio30.cpp
	g++ ejercicio30.cpp

clean:
	rm -rf a.out onda.dat plot.png *~
