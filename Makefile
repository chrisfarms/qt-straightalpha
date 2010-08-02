PREFIX=/usr/local

all:
	cc -o qt-straightalpha qt-straightalpha.c

install:
	install -m 0755 qt-straightalpha $(PREFIX)/bin

clean:
	rm qt-straightalpha

PHONY: install