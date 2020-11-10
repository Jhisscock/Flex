a.exe: checkpoint6.y checkpoint6.l main.c symtable.h
	bison -y -d checkpoint6.y
	flex checkpoint6.l
	gcc lex.yy.c y.tab.c main.c -lfl

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h c6.gstal
