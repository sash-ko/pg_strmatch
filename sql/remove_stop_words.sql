CREATE OR REPLACE FUNCTION remove_stop_words(text) RETURNS text
    AS 'pg_strmatch.so', 'remove_stop_words'
    LANGUAGE C STRICT;

SELECT remove_stop_words(NULL) IS NULL;
SELECT remove_stop_words('') = '';
SELECT remove_stop_words('  ') = '';
SELECT remove_stop_words('the') = '';
SELECT remove_stop_words('test of the test') = 'test test';
SELECT remove_stop_words('test') = 'test';
