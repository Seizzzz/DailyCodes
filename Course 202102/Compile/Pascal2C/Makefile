OUT := out
PROGRAM := pascal2c

$(OUT).exe: $(PROGRAM).tab.o $(PROGRAM).yy.o
        gcc -o $(OUT) $(PROGRAM).tab.o $(PROGRAM).yy.o -lm

$(PROGRAM).yy.o: $(PROGRAM).yy.c $(PROGRAM).tab.h
        gcc -c $(PROGRAM).yy.c

$(PROGRAM).tab.o: $(PROGRAM).tab.c
        gcc -c $(PROGRAM).tab.c

$(PROGRAM).yy.c: $(PROGRAM).l
        flex --outfile=$(PROGRAM).yy.c $(PROGRAM).l

$(PROGRAM).tab.c: $(PROGRAM).y
        bison -dv $(PROGRAM).y

$(PROGRAM).tab.h: $(PROGRAM).y
        echo "$(PROGRAM).tab.h should has been created together with $(PROGRAM).tab.c"

clean:
        rm -f *.o *.output *.yy.c *.tab.h *.tab.c *.gch
