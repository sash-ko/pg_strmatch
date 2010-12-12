#include "strmatch_impl.h"

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
