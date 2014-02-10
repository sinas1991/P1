
CXX=gcc -std=gnu99
LDFLAGS = -I. -lm -O2

OBJDIR=.obj

SRCS = $(wildcard *.c)
OBJS = $(foreach OBJ,$(SRCS:.c=.o),$(OBJDIR)/$(OBJ))
DEPS = $(wildcard *.h)

$(OBJDIR):
	if [ ! -d .obj ]; then mkdir .obj; fi

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CXX) -c $(LDFLAGS) -o $@ $<

all: $(OBJDIR) libutil

libutil: $(OBJS)
	ar -cvq libutil.a $(OBJDIR)/*.o

.PHONY: clean
.PHONY: all
.PHONY: archive

clean:
	rm -f *~ $(OBJDIR)/*.o libutil.a

archive: clean
