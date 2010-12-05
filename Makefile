
all: pg_strmatch.so test

pg_strmatch.so: pg_strmatch.o strmatch_impl.o
	cc -shared $< -o $@

test: test.o strmatch_impl.o
	cc $< -o $@ 

%.o: %.c
	cc -fpic -o $@ -c $< -I/usr/include/postgresql/8.4/server

clean:
	rm -f *.o *.so test
