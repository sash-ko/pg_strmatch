CREATE OR REPLACE FUNCTION remove_spaces(text) RETURNS text
    AS 'pg_strmatch.so', 'remove_spaces'
    LANGUAGE C STRICT;

SELECT remove_spaces('') = '' AS;
SELECT remove_spaces(NULL) IS NULL;
SELECT remove_spaces('   ') = '';
SELECT remove_spaces('no  space') = 'no space';
SELECT remove_spaces(' spaces  ') = 'spaces';
SELECT remove_spaces('  more  and more spaces!!  ') = 'more and more spaces!!';
SELECT remove_spaces('no_space') = 'no_space';
