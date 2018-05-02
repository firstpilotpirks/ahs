#/bin/sh

valgrind \
--tool=helgrind \
--trace-children=yes \
--track-fds=yes \
--time-stamp=yes \
--num-callers=30 \
--show-below-main=yes \
--free-is-write=yes \
--verbose \
${1}
