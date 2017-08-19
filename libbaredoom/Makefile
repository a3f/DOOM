CFLAGS += -fno-builtin -Wno-implicit-fallthrough -Wno-return-type -Wall -Wextra  -m32 -g3
LDFLAGS += -m32

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

WAD ?= ../doom1.wad

CPPFLAGS += -DWAD_NAME="\"$(notdir $(WAD))\""

ifeq ($(SYSTEM_STDIO), 1)
    CPPFLAGS += -D__SYSTEM_STDIO=1
endif
ifeq ($(SYSTEM_X11), 1)
    CPPFLAGS += -D__SYSTEM_X11=1
endif
ifeq ($(SYSTEM_UNISTD), 1)
    CPPFLAGS += -D__SYSTEM_UNISTD=1
endif

OBJCOPY ?= objcopy

libbaredoom.a: WAD.h $(OBJS) 
	ar rcs $@ $(OBJS)

test: libbaredoom.a
	$(CC) -m32 main.cc -isystem "." libbaredoom.a
	./a.out

WAD.h: WAD
	xxd -i WAD >$@

.INTERMEDIATE: WAD
WAD:
	cp $(WAD) WAD

WAD.o:
	$(OBJCOPY) -Ibinary -O elf32-i386 -B i386 $(WAD) $@

.PHONY: clean
clean:
	rm -f *.o libbaredoom.a ./a.out

.PHONY: distclean
distclean: clean
	rm -f WAD.h
