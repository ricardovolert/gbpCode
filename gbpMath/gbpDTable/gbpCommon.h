#ifndef COMMON_AWAKE
#define COMMON_AWAKE
#include <stdio.h> // Needed here for type FILE
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_spline.h> 

#define CALC_STAT_RETURN_DOUBLE    2
#define CALC_STAT_GLOBAL           4
#define CALC_STAT_SUM              8
#define CALC_STAT_MIN             16
#define CALC_STAT_MAX             32
#define CALC_STAT_MEAN            64
#define CALC_STAT_MEDIAN         128
#define CALC_STAT_STDDEV         256
#define CALC_STAT_DEFAULT          0

#define SORT_LOCAL               1
#define SORT_GLOBAL              0
#define SORT_COMPUTE_INPLACE     1
#define SORT_COMPUTE_NOT_INPLACE 0
#define SORT_COMPUTE_RANK        100
#define SORT_COMPUTE_INDEX       101
#define SORT_INPLACE_ONLY        102

#define IO_BUFFER_SIZE           4096

#define HUBBLE   0.71
#define RHO_CRIT 1.87992E-26*HUBBLE*HUBBLE

#define C_VACUUM       2.99792458E8   /* in m/s          */
#define G_NEWTON       6.67428E-11    /* in m^3/(kg*s^2) */
#define M_SOL          1.98892E30     /* in kilograms    */
#define M_HYDROGEN     1.6735E-27     /* in kilograms    */
#define M_PROTON       1.6726216E-27  /* in kilograms    */
#define M_ELECTRON     9.10938188E-31 /* in kilograms    */
#define SIGMA_THOMPSON 6.65245854E-29 /* in m^2          */
#define M_PER_PC       3.08568025E16  /* in meters       */
#define M_PER_KPC      3.08568025E19  /* in meters       */
#define M_PER_MPC      3.08568025E22  /* in meters       */
#define CM_PER_MPC     3.08568025E24  /* in cm           */
#define S_PER_GYR      3.155693e+16   /* in seconds      */
#define S_PER_MYR      3.155693e+13   /* in seconds      */
#define S_PER_YR       3.155693e+7    /* in seconds      */
#define K_BOLTZMANN    1.3806503E-23  /* in J per K      */
#define H_PLANK        6.62606876E-34 /* in J*s          */
#define LOG_M_P      -57.075256       /* in log(M_sol)   */
#define T_CMB          2.728          /* in Kelvin       */

#define FIVE_THIRDS    1.6666667
#define THREE_HALVES   1.5
#define TWO_THIRDS     0.6666667
#define ONE_THIRD      0.3333333
#define ONE_HALF       0.4999999
#define ONE_QUARTER    0.25

#define FOUR_THIRDS_PI     4.1887902
#define PI                 3.1415926
#define HALF_PI            1.5707963
#define THREE_QUARTERS_PI  2.3561944
#define TWO_PI             6.2831853
#define FOUR_PI           12.5663706
#define LN_OF_10           2.30288509
#define LOG10_OF_E         0.43429448
#define SQRT_OF_2          1.41421356

#define DEG_PER_RAD   5.72957795E+1
#define DEG_PER_AMIN  3.43774677E+3
#define DEG_PER_ASEC  4.84811331E-6
#define RAD_PER_DEG   1.74532925E-2
#define RAD_PER_AMIN  2.90888209E-4
#define RAD_PER_ASEC  4.84811331E-6
#define ASEC_PER_RAD  2.06265806E+5
#define ASEC_PER_DEG  3.60000000E+3

#define S_PER_YEAR     3.155693e+07
#define ERGS_PER_KEV   1.60217733000e-9
#define ERGS_PER_J     1e7
#define J_PER_KEV      1.60217646E-16
#define SI_TO_MJY      1E29

#define MU_MMW         0.597  /* Mean molecular weight      */
#define XI             1.0878 /* Xi=1+Y/(4*(1-Y)) w/ Y=0.26 */
#define XE             1.1756 /* Xe=1+Y/(2*(1-Y)) w/ Y=0.26 */

#define NE_PER_RHOGAS  XE/(MU_MMW*M_PROTON*(XI+XE))
#define NH_PER_RHOGAS  1.0/(MU_MMW*M_PROTON*(XI+XE))
#define MU_E_MMW       MU_MMW*(XI+XE)/XE 

#define GAMMA_ICM      FIVE_THIRDS

#define MSOL_KPCQU_PER_KG_MQU M_PER_KPC*M_PER_KPC*M_PER_KPC/M_SOL

#define MAX_FILE_LENGTH 256

#define LOG_ZERO  -1000.0
#define K_PER_KEV  1.1604447e7

#define LOG_BIN    0
#define LINEAR_BIN 1

#define AVG_MEAN   0
#define AVG_WEIGHT 1
#define AVG_SUM    2

#define X_PROJECTION 0
#define Y_PROJECTION 1
#define Z_PROJECTION 2

// Storage sizes
#define SIZE_OF_KILOBYTE  1024
#define SIZE_OF_MEGABYTE  1048576
#define SIZE_OF_GIGIBYTE  1073741824
#define SIZE_OF_TERABYTE  1099511627776

#define mode_int int

#define TRUE  1
#define FALSE 0
#define MIN(A,B)  ((A) < (B) ?  (A) : (B))
#define MAX(A,B)  ((A) > (B) ?  (A) : (B))
#define IABS(A)   ((A) <  0  ? -(A) : (A))
#define SIGN(A,B) ((B) <  0  ? -(A) : (A))
#define INDEX_2D(A,B,C) (A*B+C)

/********************************************/
/* Compile flags to control large variables */
/********************************************/
#ifdef USE_DOUBLE
#define REAL double
#else
#define REAL float
#endif

#define big_int long long
#define id_int  size_t

/*****************************/
/* Other common header files */
/*****************************/

// MPI
#ifdef USE_MPI
#ifndef MPI_DEFINED
#include <mpi.h>
#else
#define MPI_DEFINED 1
#endif
#ifdef USE_DOUBLE
#define MPI_MY_REAL MPI_DOUBLE
#else
#define MPI_MY_REAL MPI_FLOAT
#endif
#define MPI_SIZE_T MPI_LONG_LONG
#endif

/************/
/* Typedefs */
/************/
typedef struct interp_struct interp_info;
struct interp_struct{
  gsl_interp            *interp;
  gsl_interp_accel      *accel;
  size_t                 n;
  const gsl_interp_type *T;
  double                *x;
  double                *y;
};


// Error messages
#define ERROR_NONE      0
#define ERROR_SYNTAX    1
#define ERROR_LOGIC     2
#define ERROR_IO_OPEN   4
#define ERROR_IO_READ   8
#define ERROR_IO_WRITE  16
#define ERROR_3RD_PARTY 32
#define ERROR_MEMORY    64



/********************/
/* Data table stuff */
/********************/
#define DCOLUMN_NAME_LENGTH 100
typedef struct dcolumn_struct dcolumn;
struct dcolumn_struct{
  char     name[DCOLUMN_NAME_LENGTH];
  int      type;
  long     n_data;
  void    *data;
  dcolumn *next;
};
typedef struct dremark_struct dremark;
struct dremark_struct{
  char    *text;
  dremark *next;
};
typedef struct dtable_struct dtable;
struct dtable_struct{
  int      n_columns;
  int      n_data;
  dremark *remarks;
  dcolumn *columns;
};
void init_dtable(dtable *table);
void free_dtable(dtable *table);
void read_dtable_2part(char   *filename_defn,
                       char   *filename_data,
                       dtable *table);
int exist_dcolumn(dtable *table,
                  char    name[DCOLUMN_NAME_LENGTH]);
int add_dcolumn(dtable  *table,
                char    *name,
                int      type,
                void    *data,
                int      n_data);
int remove_dcolumn(dtable *table, 
                   char    name[DCOLUMN_NAME_LENGTH]);
int free_dcolumn(dcolumn **remove);
int add_dremark(dtable  *table,
                char    *text);
void match_dtable_ids(dtable *table1,
                      dtable *table2,
                      char    var1[DCOLUMN_NAME_LENGTH],
                      char    var2[DCOLUMN_NAME_LENGTH],
                      char   *match_name,
                      int    *n_matches);
void write_dtable(dtable *table,
                  char   *filename,
                  char   *match_name);
void write_dtables_matched(dtable *table1,
                           dtable *table2,
                           char   *filename,
                           char   *match_name);
int dcolumn_exist(dtable *table,
                  char    name[DCOLUMN_NAME_LENGTH]);
void *fetch_dcolumn(dtable *table,
                    char    name[DCOLUMN_NAME_LENGTH]);

#endif
