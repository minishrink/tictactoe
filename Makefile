#######################
#   CONFIG SETTINGS   #
#######################

# directories
LIBDIR       = lib
TESTDIR      = test
BUILDDIR     = build

# include flags for library code
INCLUDE_SRC  = -I$(LIBDIR)/
INCLUDE_TEST = -I$(TESTDIR)/

# target executables
EXEC         = $(BUILDDIR)/main.exe
TEST_EXEC    = $(BUILDDIR)/ttt_test.exe

# flags and other config
LOGFILE      = tictactoe.log
OPTIONFLAGS  = -DDEBUG #-DLOG -DLOGFILE=\"$(LOGFILE)\"
WARNFLAGS    = -Wall -Werror --pedantic-errors
LDLIBS       = -lglib-2.0
CFLAGS       = -g $(WARNFLAGS) $(LDLIBS) $(INCLUDE_SRC)

# allow CLI override for log level, e.g. "make OPTIONFLAGS=-DLOG all"
export  LOGFILE
.PHONY: all build_test build_game run test clean default


########################
#     BUILD TARGETS    #
########################

build_game:
	$(CC) $(CFLAGS) $(OPTIONFLAGS) $(LIBDIR)/*.c main.c -o $(EXEC)

build_test:
	$(CC) $(CFLAGS) $(INCLUDE_TEST) $(OPTIONFLAGS) $(LIBDIR)/*.c $(TESTDIR)/test_*.c $(TESTDIR)/ttt_test.c -o $(TEST_EXEC)

test: build_test
	exec $(TEST_EXEC)

run: build_game
	exec $(EXEC)

default: run

# note this removes logs generated too
clean:
	rm -rf *.o *.exe *.gch $(BUILDDIR)/* $(LIBDIR)/*.o $(LIBDIR)/*.gch *.log

