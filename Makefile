.PHONY: all build install clean

all: build

build:
	$(MAKE) -C build all

install:
	$(MAKE) -C build install

clean:
	rm -rf build
