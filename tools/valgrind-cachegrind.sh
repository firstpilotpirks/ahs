#/bin/sh

valgrind \
--tool=cachegrind  \
--trace-children=yes \
--track-fds=yes \
--time-stamp=yes \
--num-callers=30 \
--show-below-main=yes \
--branch-sim=yes  \
--verbose  \
${1}
