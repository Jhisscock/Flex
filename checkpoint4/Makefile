a.exe: checkpoint4.y checkpoint4.l main.c
	bison -y -d checkpoint4.y
	flex checkpoint4.l
	gcc lex.yy.c y.tab.c main.c -lfl

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h
