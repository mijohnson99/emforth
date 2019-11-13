CFLAGS = -Os -g -Wall -Wextra

WORD_LOCS = main.c

a.out: main.c fthdef.h dict.c cfas.c
	$(CC) $(CFLAGS) $< -o $@

labeled: main.c fthdef.h dict.c cfas.c
	$(CC) $(CFLAGS) -DUSE_ASMLABELS $<

cfas.c:
dict.c: phase1.pl $(WORD_LOCS)
	./$< $(WORD_LOCS)

.PHONY: clean cleaner cleanest
clean:
	rm -f dict.c cfas.c
cleaner: clean
	rm -f a.out
cleanest: cleaner
	rm -f .*~ *~
