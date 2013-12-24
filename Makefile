all:
	cc -o fmv fmv.c

test:all
	strace -tt -T ./fmv a b c

clean:
	rm -f fmv
