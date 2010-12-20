#include "postgres.h"
#include "fmgr.h"
#include "strmatch_impl.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

// Remove extra spaces: " remove  spaces " - > "remove spaces"
PG_FUNCTION_INFO_V1(remove_spaces);
Datum remove_spaces(PG_FUNCTION_ARGS)
{
    if(PG_ARGISNULL(0))
        PG_RETURN_NULL();

    text *t = PG_GETARG_TEXT_P(0);

    int len = VARSIZE(t) - VARHDRSZ;
    char *buf = (char *)palloc(len + 1);
    memset(buf, 0, len + 1);    
    memcpy(buf, VARDATA(t), len);

    remove_spaces_impl(buf);

    len = strlen(buf);
    text *result = (text *)palloc(len + VARHDRSZ);
    SET_VARSIZE(result, len + VARHDRSZ);

    memcpy(VARDATA(result), buf, len);

    pfree(buf);
    PG_RETURN_TEXT_P(result);
}

// "The United States Of America" -> "United States America"
PG_FUNCTION_INFO_V1(remove_stop_words);
Datum remove_stop_words(PG_FUNCTION_ARGS)
{    
    if(PG_ARGISNULL(0))
        PG_RETURN_NULL();

    text *t = PG_GETARG_TEXT_P(0);    
    
    int len = VARSIZE(t) - VARHDRSZ;
    char *buf = (char *)palloc(len + 1);
    memset(buf, 0, len + 1);    
    memcpy(buf, VARDATA(t), len);

    remove_stop_words_impl(buf);

    len = strlen(buf);
    text *result = (text *)palloc(len + VARHDRSZ);
    SET_VARSIZE(result, len + VARHDRSZ);

    memcpy(VARDATA(result), buf, len);

    pfree(buf);
    PG_RETURN_TEXT_P(result);
}

// Sort words in phrase: "first and second" -> "and first second"
//UNCTION_INFO_V1(remove_sort_words);
//Datum sort_words(PG_FUNCTION_ARGS)
//{    
//    if(PG_ARGISNULL(0))
//        PG_RETURN_NULL();
//
//    text *t = PG_GETARG_TEXT_P(0);
//    PG_RETURN_TEXT_P(t);
//}

//// Apply abbriviations: "east main street" -> "e main st"
//PG_FUNCTION_INFO_V1(apply_abbr);
//Datum apply_abbr(PG_FUNCTION_ARGS)
//{}

//PG_FUNCTION_INFO_V1(transliterate);
//Datum transliterate(PG_FUNCTION_ARGS)
//{}
