#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "strmatch_impl.h"
#include "stop_words.h"

void test_remove_spaces()
{
    const char *cases[8][2] = {{" test  str  ", "test str"},
                         {"", ""},
                         {" ", ""},
                         {"  ", ""},
                         {" test ", "test"},
                         {"  test s  tring  s", "test s tring s"},
                         {"te st ", "te st"},
                         {"testvalue", "testvalue"}
                        };

    int i;
    for(i = 0; i < sizeof(cases) / (2 * sizeof(char *)); i++)
    {
        char buf[256];
        strcpy(buf, cases[i][0]);
        remove_spaces_impl(buf);
        assert(strcmp(buf, cases[i][1]) == 0);
    }

    remove_spaces_impl(0);
}

void test_stop_words()
{
    assert(is_stop_word("non_stop") == 0); 
    assert(is_stop_word("the der") == 0); 
    assert(is_stop_word("the") == 1); 
    assert(is_stop_word("der") == 1); 
    assert(is_stop_word("на") == 1); 
    assert(is_stop_word("") == 1); 
}

void test_remove_stop_words()
{
    const char *cases[9][2] = {{"test", "test"},
                               {"the test", "test"},
                               {"two tests", "two tests"},
                               {"test of the tests hoho", "test tests hoho"},
                               {"", ""},
                               {"the of", ""},
                               {"  ", ""},
                               {" word  ", "word"},
                               {" the word ", "word"}
                        };
                        
    int i;
    for(i = 0; i < sizeof(cases) / (2 * sizeof(char *)); i++)
    {
        char buf[256];
        strcpy(buf, cases[i][0]);
        remove_stop_words(buf);
        assert(strcmp(buf, cases[i][1]) == 0);
    }

    remove_stop_words(0);
}

int main(int argc, const char* argv[])
{
    test_remove_spaces();
    test_stop_words();
    test_remove_stop_words();

    return 0;
}
