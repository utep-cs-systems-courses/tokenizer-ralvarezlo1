CFLAGS=-g -O3

# first target is built by default
all: tokenizer

# include file dependencies
tokenizer.o: tokenizer.h

history.o: history.h tokenizer.h

simpleUI.o: tokenizer.h history.h

# $@=target, $^=prerequisites
tokenizer: tokenizer.o history.o simpleUI.o
	cc -o $@ $^ $(CFLAGS)

# deletes files generated by compilation
clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer
