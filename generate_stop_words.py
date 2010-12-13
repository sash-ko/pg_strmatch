#!/usr/bin/python

import sys

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print 'Usage: ./generate_stop_words.py file template'

    try:
        f = open(sys.argv[1])
        templ = open(sys.argv[2])

        items = [i.strip() for i in f.readlines()]
        items.sort()
        items = ',\n'.join(['\t"%s"' % i for i in items])

        templ = templ.read()
        print templ % {'stop_words': items}
    except IOError, e:
        print 'Can not open file: ', e
