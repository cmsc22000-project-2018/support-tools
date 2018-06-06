#include "../include/testables.h"

etrie_t** return_etrie_list()
{
    etrie_t** etrie_list = malloc(3*sizeof(etrie_t*));
    etrie_list[0] = first_etrie();
    etrie_list[1] = second_etrie();
    etrie_list[2] = third_etrie();
    return etrie_list;
}

etrie_t* first_etrie()
{
    etrie_t* first = etrie_new('\0');
    etrie_insert_string(first, "and");
    etrie_insert_string(first, "would");
    etrie_insert_string(first, "wood");
    return first;
}

etrie_t* second_etrie()
{
    etrie_t* second = etrie_new('\0');
    etrie_insert_string(second, "test");
    etrie_insert_string(second, "something");
    etrie_insert_string(second, "wow");
    etrie_insert_string(second, "tea");
    return second;
}
etrie_t* third_etrie()
{
    etrie_t* third = etrie_new('\0');
    etrie_insert_string(third, "words");
    etrie_insert_string(third, "cat");
    etrie_insert_string(third, "catch");
    etrie_insert_string(third, "dog");
    etrie_insert_string(third, "borja");
    return third;
}
