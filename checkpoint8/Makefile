a.exe: checkpoint8.y checkpoint8.l main.c
	bison -y -d checkpoint8.y
	flex checkpoint8.l
	gcc lex.yy.c y.tab.c main.c -lfl

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h c7.gstal
