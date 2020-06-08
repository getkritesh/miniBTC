main.out: *.cpp *.h
	g++ *.cpp -o main.out
run:	main.out
	./main.out
