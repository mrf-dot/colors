#ifndef COLORS_H

#define COLORS_H

#define FG 38
#define BG 48
#define ANSI 8
#define COLORS 256
#define RLEN 6
#define MAGIC 4
#define STYLES "\\[0m\t\033[0mReset/Normal\n\
\\[1m\t\033[1mBold\033[0m\n\
\\[2m\t\033[2mDim\033[0m\n\
\\[3m\t\033[3mItalic\033[0m\n\
\\[4m\t\033[4mUnderline\033[0m\n\
\\[5m\t\033[5mSlow blink\033[0m\n\
\\[6m\t\033[6mRapid blink\033[0m\n\
\\[7m\t\033[7mReverse/Invert\033[0m\n\
\\[8m\t\033[8mConceal\033[0m\n\
\\[9m\t\033[9mStrike\033[0m\n"
#define HELP "COLORS: Authored by Mitch Feigenbaum\n\
Options:\n\
\t-b\t\tPrint the original ANSI colors (8)\n\
\t-c\t\tPrint the 8 Bit display colors (256)\n\
\t-h\t\tPrint this help message\n\
\t-l\t\tPrint each color on a separate line\n\
\t-s\t\tShow text styling settings\n"

// print the colors in a verbose format
void colors(int, int);

// print the foreground colors
void fg(int);

// print the background colors
void bg(int);

// print the foreground colors with one color on each line
void longfg(int);

// print the background colors with one color on each line
void longbg(int);

#endif

