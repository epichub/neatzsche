#define ROWS 1024 
#define COLS 1024
#define AT(x,y) ((y)*ROWS+(x))
#define AT2(x,y,mx) ((y)*mx+(x))

int read_image ( double *& data , const char * filename, int * sizes);
int write_image ( double *data );
int write_image_coords ( char * filename , double * image , int mx , int my );
