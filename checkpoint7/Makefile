a.exe: checkpoint7.y checkpoint7.l main.c
	bison -y -d checkpoint7.y
	flex checkpoint7.l
	gcc lex.yy.c y.tab.c main.c -lfl

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h c7.gstal
