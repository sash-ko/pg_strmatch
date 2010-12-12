SELECT 'Failed tests ' || count(*) FROM
    (SELECT remove_spaces('') = '' AS result
     UNION
     SELECT remove_spaces(NULL) IS NULL AS result
     UNION
     SELECT remove_spaces('   ') = '' AS result
     UNION
     SELECT remove_spaces('no  space') = 'no space' AS result
     UNION
     SELECT remove_spaces(' spaces  ') = 'spaces' AS result
     UNION
     SELECT remove_spaces('  more  and more spaces!!  ') = 'more and more spaces!!' AS result
     UNION
     SELECT remove_spaces('no_space') = 'no_space' AS result
    ) tests
WHERE result = FALSE;
