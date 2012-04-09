#ifndef GBPPARSE_AWAKE
#define GBPPARSE_AWAKE

#define MAX_LINE_LENGTH      7500
#define ERROR_LINE_TOO_LONG  102
#define ERROR_LINE_TOO_SHORT 103
#define ERROR_FILE_TOO_SHORT 104

// Function declarations
#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_GETLINE
int getline(char **string,size_t *n,FILE *fp);
#endif

int count_lines(FILE *fp);
int count_lines_data(FILE *fp);
int count_words(char   *line);
int check_comment(char *line);
int grab_word(char *line,
	      int   n, 
	      char *return_value);
int grab_tail(char *line,
	      int   n, 
              char *return_value);
int grab_double(char   *line,
		int     n, 
		double *return_value);
int grab_float(char   *line,
		int     n, 
		float *return_value);
int grab_int(char   *line,
		int     n, 
		int *return_value);
int grab_long(char   *line,
		int     n, 
		long *return_value);
int grab_next_line(FILE *fp,char **line, size_t *n);
int grab_next_line_data(FILE *fp,char **line, size_t *n);
int grab_nth_line(FILE *fp,int n,char *line);
int grab_size_t(char   *line,
	   	int     n, 
		size_t *return_value);
int parse_line(char *line,
	       int   n_return, ...);
int search_and_replace(char *string,char *search,char *replace);

#ifdef __cplusplus
}
#endif

#endif

