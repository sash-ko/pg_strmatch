#include "postgres.h"
#include "fmgr.h"
#include <utfasciitable.h>

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

// Remove extra spaces: " remove  spaces " - > "remove spaces"
PG_FUNCTION_INFO_V1( remove_spaces );
Datum remove_spaces( PG_FUNCTION_ARGS )
{
}

// Sort words in phrase: "first and second" -> "and first second"
PG_FUNCTION_INFO_V1( sort_words );
Datum sort_words( PG_FUNCTION_ARGS )
{
}

// Apply abbriviations: "east main street" -> "e main st"
PG_FUNCTION_INFO_V1( apply_abbr );
Datum apply_abbr( PG_FUNCTION_ARGS )
{
}

// "The United States Of America" -> "United States America"
PG_FUNCTION_INFO_V1( remove_stopwords );
Datum remove_stopwords( PG_FUNCTION_ARGS )
{
}

PG_FUNCTION_INFO_V1( transliterate );
Datum transliterate( PG_FUNCTION_ARGS )
{
}
