
#define STD_STREAM 0

extern int read_int();
extern int read_str(char*);
extern int read_line(char*);
extern float read_float();

extern int fread_int(int fd);
extern int fread_str(int fd, char*);
extern int fread_line(int fd, char*);
extern float fread_float(int fd);
