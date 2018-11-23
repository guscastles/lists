#!/bin/bash
find .|grep ".*list.*\.c"|xargs grep -nH "create"|\
       gawk '{file=$0;sub(":.+", "", file); \
	      print "# "file; \
	      sub(".+:", ""); \
	      print NR"c"NR; \
	      print "< "$0; \
	      sub("create", "make"); \
	      print "---"; \
	      print "> "$0}'

