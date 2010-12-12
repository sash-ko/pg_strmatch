#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "strmatch_impl.h"

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

int main(int argc, const char* argv[])
{
    test_remove_spaces();

    return 0;
}
