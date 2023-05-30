#!/bin/sh

echo $OSTYPE | grep -q linux
if [ $? -eq 0 ]; then
    echo "We are on Linux (1 of 2)"
    echo "PKG_LIBS = -L${LIBDIR} -lharmonium -lasound"
fi

os=`uname -s`
if [ "$os" = "Linux" ]; then
    echo "We are on Linux (2 of 2)"
    echo "PKG_LIBS = -L${LIBDIR} -lharmonium -lasound"
fi
