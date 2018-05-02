#/bin/sh

valgrind \
--tool=callgrind \
--trace-children=yes \
--track-fds=yes \
--time-stamp=yes \
--num-callers=30 \
--show-below-main=yes \
--branch-sim=yes \
--dump-instr=yes \
--collect-bus=yes \
--cache-sim=yes \
--branch-sim=yes \
--verbose \
${1}
