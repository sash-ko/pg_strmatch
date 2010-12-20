#include <string.h>
#include <stddef.h>
#include "strmatch_impl.h"
#include "stop_words.h"

void remove_spaces_impl(char *str)
{
    if(str && *str)
    {
        char *buf = str;
        int next_word = -1; // -1, 0, 1

        do
        {
            if(*str != ' ' && *str != '\0')
            {
                if(next_word == 1)
                    *(buf++) = ' ';

                next_word = 0;
                *(buf++) = *str;
            }
            else
            {
                if(next_word != -1)
                    next_word = 1;
            }
        } while(*str++);
        *buf = 0;
    }
}

void remove_stop_words(char *str)
{
    if(str && *str)
    {
        const char delimiters[] = " ";
        char *token = NULL;
        char *cp = strdup(str);
        memset(str, ' ', strlen(str));
        int first = 0;

        token = strsep(&cp, delimiters);
        while(token)
        {
            if(!is_stop_word(token))
            {
                if(first != 0)
                    *++str;
                else
                    first = 1;

                int len = strlen(token);
                memcpy(str, token, len);
                str += len;
            }
            token = strsep(&cp, delimiters);
        }
        *str = 0;

        free((void *)cp);
    }
}
