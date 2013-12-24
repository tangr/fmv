all:
	cc -o dmv dmv.c

test:all
	strace -tt -T ./dmv a b c

clean:
	rm -f dmv
