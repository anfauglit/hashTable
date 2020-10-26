objects = ls.o main.o 

main: $(objects)
	gcc -o main $(objects)

$(objects) : list.h

clean:
	rm main $(objects)
