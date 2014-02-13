
#define STD_STREAM 0

extern int write_int(int);
extern int write_str(char*);
extern int write_line(char*);
extern int write_float(float);

extern int fwrite_int(int fd, int);
extern int fwrite_str(int fd, char*);
extern int fwrite_line(int fd, char*);
extern int fwrite_float(int fd, float);
