/********************************************************
 * infinite-array -- routines to handle infinite arrays *
 *                                                      *
 * An infinite array is an array that grows as needed.  *
 * There is no index too large for an infinite array    *
 * (unless we run out of memory).                       *
 ********************************************************/
#include "ia.h"                 /* get common definitions */
#include <stdio.h>
#include <stdlib.h>     /* ANSI Standard only */

/*
 * the following three variables implement
 * a very simple pointer cache
 *
 * They store information on the last infinite array used,
 *       the last bucket we had and the last index used
 *
 * They are initialized to values we know will never
 * be used by any real array.
 */
static struct infinite_array *cache_array_ptr = NULL;
static struct infinite_array *cache_bucket_ptr = NULL;
static int cache_index = -1;
/********************************************************
 * ia_store -- store an element into an infinite array. *
 *                                                      *
 * Parameters                                           *
 *      array_ptr -- pointer to the array to use        *
 *      index   -- index into the array                 *
 *      store_data -- data to store                     *
 ********************************************************/
void  ia_store(struct infinite_array * array_ptr, 
    int index, float store_data)
{
    /* pointer to the current bucket */
    struct infinite_array *current_ptr;
    int   current_index;        /* index into the current bucket */

    /* get the location in an infinite array cell */
    struct infinite_array *ia_locate(
       struct infinite_array *, int, int *);

    current_ptr = ia_locate(array_ptr, index, &current_index);
    current_ptr->data[current_index] = store_data;
}
/********************************************************
 * ia_get -- get an element from an infinite array.     *
 *                                                      *
 * Parameters                                           *
 *      array_ptr -- pointer to the array to use        *
 *      index   -- index into the array                 *
 *                                                      *
 * Returns                                              *
 *      the value of the element                        *
 ********************************************************/
float ia_get(struct infinite_array *array_ptr, int index)
{
    /* pointer to the current bucket */
    struct infinite_array *current_ptr;
    int   current_index;        /* index into the current bucket */

    /* get the location an infinite array cell */
    struct infinite_array *ia_locate();

    current_ptr = ia_locate(array_ptr, index, &current_index);
    return (current_ptr->data[current_index]);
}
/********************************************************
 * ia_locate -- get the location of an infinite array   *
 *              element.                                *
 *                                                      *
 * Parameters                                           *
 *      array_ptr -- pointer to the array to use        *
 *      index   -- index into the array                 *
 *      current_index -- pointer to the index into this *
 *              bucket (returned)                       *
 *                                                      *
 * Returns                                              *
 *      pointer to the current bucket                   *
 ********************************************************/
static struct infinite_array ia_locate(
        struct infinite_array *array_ptr, int index
        int *current_index_ptr)
{
    /* pointer to the current bucket */
    struct infinite_array *current_ptr;

    /* see if the cache will do us any good */
    if ((cache_array_ptr == array_ptr) && (index >= cache_index)) {
        current_ptr = cache_bucket_ptr;
        *current_index_ptr = index - cache_index;
    } else {
        current_ptr = array_ptr;
        *current_index_ptr = index;
    }

    while (*current_index_ptr > BLOCK_SIZE) {
        if (current_ptr->next == NULL) {
            current_ptr->next =
                (struct infinite_array *)
                malloc(sizeof(struct infinite_array));
            if (current_ptr->next == NULL) {
                (void) fprintf(stderr, "Error:Out of memory\n");
                exit(8);
            }
        }
        current_ptr = current_ptr->next;
        *current_index_ptr -= BLOCK_SIZE;
    }

    cache_index = index - (index % BLOCK_SIZE);
    cache_array_ptr = array_ptr;
    cache_bucket_ptr = current_ptr;

    return (current_ptr);
}
