CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Isrc
OPTFLAGS = -O3
DEBUGFLAGS = -g -O0

SRCDIR = src
BINDIR = bin
OBJDIR = obj

SRCS = $(shell find $(SRCDIR) -name '*.c')
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
DEBUG_OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.debug.o,$(SRCS))

TARGET = $(BINDIR)/bce

all: $(TARGET)

$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OPTFLAGS) -o $@ $(OBJS)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(BINDIR)/bce_debug

$(BINDIR)/bce_debug: $(DEBUG_OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ $(DEBUG_OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

$(OBJDIR)/%.debug.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

run: all
	./$(TARGET)

clean:
	rm -rf $(BINDIR) $(OBJDIR)

rebuild: clean all

.PHONY: all debug run clean rebuild
