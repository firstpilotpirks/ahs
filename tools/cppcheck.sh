#/bin/sh

cppcheck \
--project=${1} \
--enable=warning,style,performance,portability,information,unusedFunction \
--language=c++ \
--platform=unix64 \
--std=c++14 \
-j8 \
--max-configs=100 \
--verbose
