all: linuxxdoom

linuxxdoom:
	make -C linuxdoom-1.10

.PHONY: deps
deps:
	make -C linuxdoom-1.10 deps

.PHONY: clean
clean:
	make -C linuxdoom-1.10 clean
	rm linuxxdoom
