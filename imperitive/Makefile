PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man

TITLE = phonebook
MANPAGE = ${TITLE}.1.gz

SRC = phonebook.c testing.c extra.c
OBJ = ${SRC:.c=.o}

all: ${OBJ} #${MANPAGE}

%.o: %.c
	$(CC) -o $@ $<

%.gz: %
	gzip $<

install: all
	mkdir -p  $(DESTDIR)$(PREFIX)/bin
	install ${OBJ} $(DESTDIR)$(PREFIX)/bin/${TITLE}
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	install -m 644 ${MANPAGE} $(DESTDIR)$(MANPREFIX)/man1/${MANPAGE}

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/${TITLE}
	rm -f $(DESTDIR)$(MANPREFIX)/man1/${MANPAGE}

clean:
	rm -f ${OBJ} ${MANPAGE}

push:
	git push origin --tags

test: testing.o
	./testing.o


.PHONY: all install uninstall clean push
