MODULES = pg_strmatch
DATA_built = pg_strmatch_install.sql pg_strmatch_uninstall.sql
DOCS =
REGRESS = remove_spaces remove_stop_words

PG_CONFIG = pg_config
REGRESS_OPTS = --dbname=regression
PGXS = $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

all: pg_strmatch.so test

pg_strmatch.so: pg_strmatch.o strmatch_impl.o stop_words.o
	cc -shared $^ -o $@

test: test.o strmatch_impl.o stop_words.o
	cc $^ -o $@

stop_words.c:
	./generate_stop_words.py stop_words.txt stop_words.c.in > stop_words.c

%.o: %.c
	cc -fpic -o $@ -c $< -I/usr/include/postgresql/8.4/server

clean:
	rm -f *.o *.so test stop_words.c
