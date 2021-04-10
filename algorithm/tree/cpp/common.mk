CXX_FLAGS=-Wall
CXX=g++

HAS_CPP14=$(shell \
	echo > /tmp/dummy.cpp ; \
	if $(CXX) -std=c++14 -c -o /dev/null /tmp/dummy.cpp 2>/dev/null ; then \
		echo yes ; \
	else \
		echo no ; \
	fi)

HAS_CPP11=$(shell \
	echo > /tmp/dummy.cpp ; \
	if $(CXX) -std=c++11 -c -o /dev/null /tmp/dummy.cpp 2>/dev/null ; then \
		echo yes ; \
	else \
		echo no ; \
	fi)

ifeq ($(HAS_CPP14), yes)
	PREFER_STANDARD:=cpp14
else
ifeq ($(HAS_CPP11), yes)
	PREFER_STANDARD:=cpp11
endif
endif