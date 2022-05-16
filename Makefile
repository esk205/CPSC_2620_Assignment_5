# For Makefiles, lines preceded with # are comment lines
# Remember, Makefiles are your friends. You do not want to be compiling
# files individually.
#
# Makefile for fraction project
#
# Author: Arie
# June 7, 2007
#

# some settings...
# use the gnu C++ compiler
CCC= g++11
# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11

# all is called a target, fracTest is called a dependency
# ie. "the target all is dependent on the executable fracTest
all : bankTest

# the target fracTest is dependent on fraction.o and fracTest.o
# the line following  is the required executable
# Note: executables always begin with a tab.
# $^ = this target
# $@ = this/these dependencies
bankTest : bankTest.o bank.o config.o result.o customer.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
# $< = the corresponding .cc file
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# Don't need next lines b/c of the above default rule but no harm including them
# In the following lines, make knows that the .cc file is required in the
# current dependency so you can leave it out.  You can also leave out the
# corresponding executable line
bankTest.o : bank.h result.h customer.h config.h
result.o : result.h
customer.o : customer.h
config.o : config.h
bank.o : bank.h customer.h result.h config.h
clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f bankTest
