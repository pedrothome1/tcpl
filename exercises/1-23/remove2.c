#include <stdio.h>

#define IN_CODE 		0
#define IN_BLOCK_COMMENT 	1
#define IN_DOUBLE_QUOTE 	2
#define IN_SINGLE_QUOTE 	3
#define IN_DQ_ESCAPE		4
#define IN_SQ_ESCAPE		5
#define IN_START_SLASH          6	
#define IN_END_SLASH            7	

char *states[] = {
	"IN_CODE",
	"IN_BLOCK_COMMENT",
	"IN_DOUBLE_QUOTE",
	"IN_SINGLE_QUOTE",
	"IN_DQ_ESCAPE",
	"IN_SQ_ESCAPE",
	"IN_START_SLASH",
	"IN_END_SLASH",
};

/*
 *
 * Testing
 * testing
 */

/***
 *
 * Testing
 * testing
 ***/

/* sadfsadfs */
/****/
/***sadfsd */
/***sadfsd *****/
/* **** */
/* // */
/* / */

int main() {
	int c;
	int prev;
	int state;

	prev = -1;
	state = IN_CODE;

	char *example = "/* this is not \"a comment */";
	char example2 = '/';
	char example3 = '\'';
	char example4 = '\"';

	while ((c = getchar(/*inner comment*/)) != EOF) {
		/* if (state == IN_END_SLASH) */
		/* 	state = IN_CODE; */

		if (state == IN_CODE) {
			if (c == '"')
				state = IN_DOUBLE_QUOTE;
				/* inner comment */
			else if (c == '\'')
				state = IN_SINGLE_QUOTE;
				/* inner comment */
			else if (c == '/')
				state = IN_START_SLASH;
				/* inner comment */
		} else if (state == IN_DOUBLE_QUOTE) {
			if (c == '"')
				state = IN_CODE;
				/* inner comment */
			else if (c == '\\')
				state = IN_DQ_ESCAPE;
				/* inner comment */
		} else if (state == IN_SINGLE_QUOTE) {
			if (c == '\'') /* inner comment */
				state = IN_CODE;
			else if (c == '\\')
				state = IN_SQ_ESCAPE;
				/* inner comment */
		} else if (state == IN_START_SLASH) {
			if (c == '*') {
				state = IN_BLOCK_COMMENT;
			} else {
				state = IN_CODE;
				putchar(prev);
			}
			/*another inner comment*/
		} else if (state == IN_END_SLASH) {
			if (c == '/')
				state = IN_START_SLASH;
			else
				state = IN_CODE;
		} else if (state == IN_BLOCK_COMMENT) {
			if (prev == '*' && c == '/')
				state = IN_END_SLASH;
		} else if (state == IN_DQ_ESCAPE) {
			state = IN_DOUBLE_QUOTE;
		} else if (state == IN_SQ_ESCAPE) {
			state = IN_SINGLE_QUOTE;
		}

		if (state != IN_START_SLASH && state != IN_END_SLASH && state != IN_BLOCK_COMMENT) {
			putchar(c);
			/* if (c == '/' || c == '*') */
			/* 	printf("\n\n'%c' ===> %s\n\n", c, states[state]); */
		}

		prev = c;
	}

	return 0;
}
