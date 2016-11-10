/********************************************************
 * find -- look for a data item in the list             *
 *                                                      *
 * Parameters                                           *
 *      name -- name to look for in the list            *
 *                                                      *
 * Returns                                              *
 *      1 if name is found                              *
 *      0 if name is not found                          *
 ********************************************************/
int file(char *name)
{
    /* current structure we are looking at */
    struct linked_list *current_ptr;

    current_ptr = first_ptr;

    while ((strcmp(current_ptr->data, name) != 0) &&
           (current_ptr != NULL))
        current_ptr = current_ptr->next_ptr;

    /*
     * If current_ptr is null, we fell off the end of the list and
     * didn't find the name
     */
    return (current_ptr != NULL);
}
