#define _MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <gbpLib.h>
#include <gbpMath.h>
#include <gbpHalos.h>
#include <gbpTrees.h>

int main(int argc, char *argv[]){
  char        filename_halo_root_in[256];
  char        filename_cat_root_in[256];
  char        filename_root_out[256];
  char        filename_snap_list_in[256];
  char        filename_snap_list_out[256];
  char        filename_output_file_root[256];
  int         i_read_start;
  int         i_read_stop;
  int         i_read_step;
  int         n_search_forests;
  int         n_files_groups;
  int         n_files_subgroups;
  int         n_k_match=2;
  int         flag_clean=FALSE;
  FILE       *fp_in;
  FILE       *fp_out;
  char       *line=NULL;
  size_t      line_length=0;
  int         n_snaps,i_read,i_next,i_write,n_keep;
  double     *a_list_in;
  double     *a_list_out;

  SID_init(&argc,&argv,NULL);

  // Fetch user inputs
  strcpy(filename_halo_root_in,argv[1]);
  strcpy(filename_cat_root_in, argv[2]);
  strcpy(filename_root_out,    argv[3]);
  strcpy(filename_snap_list_in,argv[4]);
  n_search_forests =atoi(argv[5]);
  n_files_groups   =atoi(argv[6]);
  n_files_subgroups=atoi(argv[7]);

  SID_log("Constructing vertical merger trees...",SID_LOG_OPEN|SID_LOG_TIMER);
  compute_trees_vertical(filename_root_out,
                         filename_cat_root_in,
                         filename_snap_list_in,
                         n_files_groups,
                         n_files_subgroups,
                         n_search_forests,
                         &flag_clean);
  SID_log("Done.",SID_LOG_CLOSE);

  SID_exit(ERROR_NONE);
}

