#/bin.sh

valgrind \
--tool=memcheck \
--leak-check=full \
--undef-value-errors=yes \
--trace-children=yes \
--track-fds=yes \
--time-stamp=yes \
--num-callers=30 \
--show-below-main=yes \
--show-leak-kinds=all \
--show-reachable=yes \
--show-possibly-lost=yes \
--expensive-definedness-checks=yes \
--verbose \
${1}
