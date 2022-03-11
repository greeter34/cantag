all:
	g++ -g *.c *.cpp -o test -lcurses
	x86_64-w64-mingw32-g++ *.c *.cpp -o test.exe -lcurses -l:libgcc_eh.a  -l:libstdc++.a

linux:
	g++ -g *.c *.cpp -o test -lcurses

windows:
	x86_64-w64-mingw32-g++ *.c *.cpp -o test.exe -lcurses -l:libgcc_eh.a  -l:libstdc++.a

clean:
	rm *.o *.exe test
