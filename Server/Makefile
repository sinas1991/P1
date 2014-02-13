
CXX=gcc -std=gnu99
LDFLAGS = -I. -lm -O2

OBJDIR=.obj

SRCS = $(wildcard *.c)
OBJS = $(foreach OBJ,$(SRCS:.c=.o),$(OBJDIR)/$(OBJ))
DEPS = $(wildcard *.h)

UTILDIR = ../Utils/
UTILFLAG = -lutil
UTILLIB=$(UTILDIR)libutil.a
UTILC=$(UTILDIR)io_utils.c $(UTILDIR)str_utils.c
UTILH=$(UTILC:.c=.h)

$(OBJDIR):
	if [ ! -d .obj ]; then mkdir .obj; fi

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CXX) -c $(LDFLAGS) -o $@ $<

all: $(OBJDIR) $(UTILLIB) Server

Server: $(OBJS) $(UTILLIB)
	$(CXX) -o $@ $^ $(LDFLAGS) -L$(UTILDIR) $(UTILFLAG)

$(UTILLIB): $(UTILC) $(UTILH)
	cd $(UTILDIR); make;

.PHONY: clean
.PHONY: all
.PHONY: archive

clean:
	rm -f *~ $(OBJDIR)/*.o Server

archive: clean
