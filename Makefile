CC=gcc
FLAGS=-g -Wall

TESTDIR=test
SRCDIR=src
LIBDIR=lib
OBJDIR=obj

LIB=memorion.so
LIB_S=memorion.a

INC := $(wildcard $(SRCDIR)/*.h)
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TESTS := $(wildcard $(TESTDIR)/*.c)
TESTS_BIN := $(TESTS:$(TESTDIR)/%.c=$(TESTDIR)/bin/%)

all: mkdir $(LIB) $(LIB_S) test

%.so: $(SRC)
	$(CC) $(FLAGS) -fPIC -shared -o $@ $^ -lc

%.a: $(OBJ)
	ar rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(FLAGS) -c $^
	mv *.o $(OBJDIR)/

test: $(TESTS_BIN)
	for test in $(TESTS_BIN) ; do ./$$test --verbose ; done

$(TESTDIR)/bin/%: $(TESTDIR)/%.c $(LIB_S)
	$(CC) $(FLAGS) -o $@ $^ -L -lmemorion -lcriterion

mkdir:
	mkdir -p $(OBJDIR) $(TESTDIR)/bin/
clean:
	$(RM) -r $(OBJDIR) $(TESTDIR)/bin/ */*.pch */*.gch
