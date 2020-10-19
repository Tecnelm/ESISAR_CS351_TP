LANGAGE = C
EXEC = exe
DEBUG = yes
TEST = no

CFLAGS = -Wall -ansi -pedantic -std=c99
OUT = out
OBJDIR = obj
SRCDIR = src
MAINDIR = src
INCDIR = includes
LIBDIR = lib
DATADIR= data
lib = SDL2


MAIN = main

ifeq ($(LANGAGE),C)
	CC = gcc
	EXTP =c 
	EXTS =h
endif

ifeq ($(LANGAGE),C++)
	CC = g++
	EXTP =cpp 
	EXTS =h
endif

SRCS= $(filter-out $(MAINDIR)/$(MAIN).$(EXTP),$(wildcard $(SRCDIR)/*.$(EXTP)))
OBJS= $(SRCS:$(SRCDIR)/%.c=$(OUT)/$(OBJDIR)/%.o) $(OUT)/$(OBJDIR)/$(MAIN).o
HEADER =$(wildcard $(INCDIR)/*.$(EXTS))

CFLAGS := $(CFLAGS) -I$(INCDIR) 
CFLAGS += $(foreach librarydir,$(LIBDIR),-L$(librarydir))
CFLAGS += $(foreach library,$(lib),-l$(library))

ifeq ($(DEBUG),yes)
	CFLAGS := $(CFLAGS) -g
endif
ifeq ($(TEST),yes)
	CFLAGS := $(CFLAGS) -DTEST
endif

$(OUT)/$(EXEC):$(OBJS) $(HEADER)
	@mkdir -p $(OUT)
	@mkdir -p $(OUT)/$(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OUT)/$(OBJDIR)/$(MAIN).o: $(MAINDIR)/$(MAIN).$(EXTP)
	@mkdir -p $(OUT)
	@mkdir -p $(OUT)/$(OBJDIR)
	$(CC) -o $@ -c $^ $(CFLAGS)

$(OUT)/$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.$(EXTS)
	@mkdir -p $(OUT)
	@mkdir -p $(OUT)/$(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean mrproper run create

clean:
	@rm -rf $(OUT)/$(OBJDIR)/*.o

mrproper: clean
	@rm -rf $(OUT)

run: $(OUT)/$(EXEC)
	@./$(OUT)/$(EXEC)
create:
	mkdir -p $(DATADIR)
	mkdir -p $(SRCDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(LIBDIR)

