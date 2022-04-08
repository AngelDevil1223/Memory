#include <stdio.h>
#include <stdlib.h>
#include <assert.h>   
#include <string.h>
#include <unistd.h>

#include "free_list.h"


/* Extern declarations: */
extern  int     optind;
extern  char    *optarg;
extern  int     mem_size;
extern  hole_t  *hole_head;

int main(int argc, char** argv)
{
    char input; /* argument identifier */
    char *filename;
    char *algorithm; /* algorithm for choosing hole */
    process_t *out; /* dequeue process */
    filename=argv[1];
    algorithm=argv[2];
    mem_size=atoi("1024");
    
    /* load process from file into queue */
    load_into_queue(filename);
    /* initialize the free list with empty memory of given size */
    hole_head = make_hole_node(0, mem_size);
    float avg=0;
    int count=0;
    int prc=0;
    int hc=0;
    while(1)
    {
        /* dequeue process, break from loop if queue is empty */
        if((out = process_dequeue()) == NULL) 
            break;

        /* load process into memory by using free holes, evict older process
            and create larger/more holes if necessary */
        use_hole(out, algorithm);
        avg=(avg*count+(give_memusage()-1))/(count+1);
        /* print memory status */
        count=count+1;
        hc=hc+give_numholes();
        prc=prc+give_numprocesses();
        printf("%d pid loaded, processes=%d, holes=%d, memusage=%.0f%%, cumulative_mem=%.0f%%\n",
            out->pid, give_numprocesses(), give_numholes(), give_memusage()-1,avg);
    }  
    printf("Total loads=%d, average processes=%f, average #holes = %f, cumulative_mem = %.0f%%\n", count,prc/(float)count, hc/(float)count,avg);

    /* free dynamically allocated memory */
    free_free_list();
    free_memory();


    return 0;
}
