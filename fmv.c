#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h> 

#define FILENAME_SIZE 1024

int 
main(int argc, char *argv[])
{
    int debug = 0;
    char c;
    char live[FILENAME_SIZE+1], old[FILENAME_SIZE+1], new[FILENAME_SIZE+1];

    while ( (c = getopt(argc, argv, "hdl:o:n:") ) != -1) {
        switch (c) {
            case 'd':
                debug = 1;
                break;
            case 'l':
                snprintf(live, FILENAME_SIZE, "%s", optarg);
                break;
            case 'o':
                snprintf(old, FILENAME_SIZE, "%s", optarg);
                break;
            case 'n':
                snprintf(new, FILENAME_SIZE, "%s", optarg);
                break;
            case 'h':
                printf("Usage: fmv -l live_dir -o old_dir -n new_dir\n");
                return 0;
        }
    }

    if (debug == 1) {
        printf("live=%s, old=%s, new=%s\n", live, old, new);
    }

    if (rename(live, old) == -1) {
        printf("Failed: %s\n", strerror(errno));
        return 1;
    }

    if (rename(new, live) == -1) {
        printf("Failed: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}

