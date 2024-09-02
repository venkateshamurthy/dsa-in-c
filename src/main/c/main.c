#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include "name.h"
#include "node.h"
#include "iterator.h"
#include "address.h"
#define node_names(count, args...) node_data((data_creator)&name_make, count, args)
#define node_addresses(count, args...) node_data((data_creator)&address_make, count, args)

void check_loop_in_list(node * root, data_to_string ds) {
    // Create a Loop from last node to say 3rd node.
    node * last_node = node_last(root);
    last_node -> next = root -> next -> next;

    // Detect loop and break free
    bool break_free_loop = true;
    node * meeting_node = detect_loop_in_linkedlist(root, break_free_loop);
    node_display(meeting_node, "Meeting/Intersection Node", ds);

    // Now you can display as the loop has been broken free
    node_display_recursive(root, ds);
}

void test_loops_in_int_list() {
    printf ("\nDetect Loop in Integer list\n");
    node * root = node_ints(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    check_loop_in_list(root, (data_to_string)&itos);
    node_free(root, (free_up)&free_int);
}

void test_loops_in_string_list() {
    printf ("\nDetect Loop in String list\n");
    node * root = node_strings(8, "VNP",  "YNP",  "TSV",  "IVK", "TRS", "TSP", "TKV", "PNP");
    check_loop_in_list(root, (data_to_string)&string_to_string);
    node_free(root, (free_up)&free_string);
}

void test_names() {
    printf ("\nPrinting names list\n");
    node * root = node_names(4, "V", "N", 19, "Y", "N", 24, "V", "M", 54, "I", "K", 49);
    node_display_recursive(root, (data_to_string)&name_to_string);
    check_loop_in_list(root, (data_to_string)&name_to_string);
    node_free(root, (free_up)&name_free);
}

void test_addresses() {
    printf ("\nPrinting addresses list\n");
    node * root = node_addresses(8, "581, 2nd Main, BSK-3rd Stage", "080-26721581", "a@b.com",
                                    "Saptarshi layout, Mysore", "9986380372", "a@b.com",
                                    "RR3 Apartments, RR Nagar", "9986380372", "a@b.com",
                                    "EUC castle, Murugesh palya", "9986380372", "a@b.com",
                                    "LIC layout, RR nagar", "9986026076", "a@b.com",
                                    "Adde vishwanatha pura","9986026076", "a@b.com",
                                    "Channapatna Thota","9986026076", "a@b.com",
                                    "Biginen Halli Thota","9986026076", "a@b.com"
                                 );
    node_display_recursive(root, (data_to_string)&address_to_string);
    check_loop_in_list(root, (data_to_string)&address_to_string);
    node_free(root, (free_up)&address_free);
}

int main () {
    printf ("Hellow World!\n");
    test_loops_in_string_list();
    test_loops_in_int_list();
    test_names();
    test_addresses();
}