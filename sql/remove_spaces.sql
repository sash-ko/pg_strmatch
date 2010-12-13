CREATE OR REPLACE FUNCTION remove_spaces(text) RETURNS text
    AS 'pg_strmatch.so', 'remove_spaces'
    LANGUAGE C STRICT;

SELECT remove_spaces('') = '' AS result;
SELECT remove_spaces(NULL) IS NULL AS result;
SELECT remove_spaces('   ') = '' AS result;
SELECT remove_spaces('no  space') = 'no space' AS result;
SELECT remove_spaces(' spaces  ') = 'spaces' AS result;
SELECT remove_spaces('  more  and more spaces!!  ') = 'more and more spaces!!' AS result;
SELECT remove_spaces('no_space') = 'no_space' AS result;
