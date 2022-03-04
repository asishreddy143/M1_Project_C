#TargetName : Dependencies
#<TAB>commands

Build : Code.c
	gcc code.c -o code.out

Run : code.out
	./code.out
	
Clean:
	rm -rf *.o *.out *.i *.s
