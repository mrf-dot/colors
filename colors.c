#include <stdio.h>
#include <unistd.h>
#include "colors.h"

void longfg(int colors)
{
    for (int i = 0; i < colors; i++) {
        if (i < ANSI) {
            printf("\\[%dm\t\t", FG - ANSI + i);
        } else {
            printf("\\[%d;5;%d\t", FG, i);
        }
        printf("\033[%d;5;%dm%4d\033[0m\n", FG, i, i);
    }
}

void longbg(int colors)
{
    for (int i = 0; i < colors; i++) {
        if (i < ANSI) {
            printf("\\[%dm\t\t", BG - ANSI + i );
        } else {
            printf("\\[%d;5;%d\t", BG, i);
        }
        printf("\033[%d;5;%dm%4d\033[0m\n", BG, i, i);
    }
}

void fg(int colors)
{
    for (int i = 0; i < colors; i++) {
        printf("\033[%d;5;%dm%4d\033[0m", FG, i, i);
        if ((i + 1) % RLEN == MAGIC) {
            putchar('\n');
        }
    }
}

void bg(int colors)
{
    for (int i = 0; i < colors; i++) {
        printf("\033[%d;5;%dm%4d\033[0m", BG, i, i);
        if ((i + 1) % RLEN == MAGIC) {
            putchar('\n');
        }
    }
}

void colors(int colors, int verbose)
{
    puts("Foreground Colors\n");
    if (verbose) {
        longfg(colors);
        puts("\nBackground Colors\n");
        longbg(colors);
    } else {
        fg(colors);
        puts("\nBackground Colors\n");
        bg(colors);
    }
}

int
main(int argc, char **argv)
{
    if (argc == 1) {
        fputs(HELP, stderr);
        return 1;
    }
    int c;
    while ((c = getopt(argc, argv, "hbcls")) != -1)
        switch(c) {
            case 'h':
                fputs(HELP, stdout);
                break;
            case 'b':
                colors(ANSI, 1);
                break;
            case 'c':
                colors(COLORS, 0);
                break;
            case 'l':
                colors(COLORS, 1);
                break;
            case 's':
                fputs(STYLES, stdout);
                break;
            case '?':
            default:
                return 1;
        }
    for (int i = optind; i < argc; i++) {
        fprintf(stderr, "non-option argument: %s\n", argv[i]);
    }
    return 0;
}

