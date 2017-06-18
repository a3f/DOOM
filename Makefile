all: doom

doom:
	make -C linuxdoom-1.10

.PHONY: deps
deps:
	make -C linuxdoom-1.10 deps

.PHONY: clean
clean:
	make -C linuxdoom-1.10 clean
	rm -f doom
