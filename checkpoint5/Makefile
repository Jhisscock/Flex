a.exe: checkpoint5.y checkpoint5.l main.c symtable.h
	bison -y -d checkpoint5.y
	flex checkpoint5.l
	gcc lex.yy.c y.tab.c main.c symtable.h -lfl

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h symtable.h.gch
