
CXX=gcc
LDFLAGS = -I. -lm -O2

OBJDIR=.obj

SRCS = $(wildcard *.c)
OBJS = $(foreach OBJ,$(SRCS:.c=.o),$(OBJDIR)/$(OBJ))
DEPS = $(wildcard *.h)

$(OBJDIR):
	if [ ! -d .obj ]; then mkdir .obj; fi

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CXX) -c $(LDFLAGS) -o $@ $<

all: $(OBJDIR) Server

Server: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
.PHONY: all
.PHONY: archive

clean:
	rm -f *~ $(OBJDIR)/*.o Server

archive: clean
