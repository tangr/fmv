fast mv
========

to avoid symbol link php realpath cache problem, we use fast mv

We used symbolic link when we deploy a new version, but because of php realpath cache
new code doesn't take effect till several minutes.

fmv is replacement for 'ln -sf'
