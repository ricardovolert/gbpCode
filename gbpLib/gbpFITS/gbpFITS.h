#ifndef GBPFITS_AWAKE
#define GBPFITS_AWAKE
#include <fitsio.h>

// Function declarations
#ifdef __cplusplus
extern "C" {
#endif
int  read_image_FITS(void **image, SID_Datatype *dtype,int *n_D,int **D,  const char *filename);
int  write_image_FITS(void *image, SID_Datatype  dtype,int  n_D,int *D,   const char *filename,const char *ext_name);
int  append_image_FITS(void *image,SID_Datatype  dtype,int  n_D,int *D_in,const char *filename,const char *ext_name);
void transpose_array(void *data,   SID_Datatype  dtype,int  n_d,int *d_i);
#ifdef __cplusplus
}
#endif
#endif

