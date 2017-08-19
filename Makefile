all: doom

ifeq ($(BARE), 1)
    CPPFLAGS = -isystem libbaredoom
    LIBS = -Llibbaredoom -lbaredoom
endif

export

.PHONY: all
all: libbaredoom-build doom

.PHONY: doom
doom:
	make -C linuxdoom-1.10

.PHONY: deps
deps:
	make -C linuxdoom-1.10 deps

relink:
	rm -f doom
	make -C linuxdoom-1.10

libbaredoom-build:
	make -C libbaredoom

.PHONY: clean
clean:
	make -C linuxdoom-1.10 clean
	make -C libbaredoom clean
	rm -f doom
