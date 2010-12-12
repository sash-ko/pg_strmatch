CREATE OR REPLACE FUNCTION remove_spaces(text) RETURNS text
    AS 'pg_strmatch.so', 'remove_spaces'
    LANGUAGE C STRICT;
