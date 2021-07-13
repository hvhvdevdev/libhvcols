/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <stdint.h>

#ifndef Item
#define Item int
#endif

#define _CONCAT(id1, id2, id3) id1##id2##id3
#define CONCAT(id1, id2, id3) _CONCAT(id1,id2,id3)

#define LinkedList CONCAT(LinkedList_,Item,)
#define LinkedList_push_back CONCAT(LinkedList_,Item,_push_back)
#define LinkedList_push_front CONCAT(LinkedList_,Item,_push_front)
#define LinkedList_nth CONCAT(LinkedList_,Item,_nth)
#define LinkedList_pop_front CONCAT(LinkedList_,Item,_pop_front)

/**
 * Linked List Data Structure
 */
typedef struct LinkedList {
    Item item;
    struct LinkedList *next;
} LinkedList;

/**
 * Append an item.
 * @param head Head of the list.
 * @param item Item to insert.
 * @return true if success. False otherwise.
 */
bool LinkedList_push_back(LinkedList **head, Item item) {
    LinkedList *node = malloc(sizeof(LinkedList));

    // Allocation failed?
    if (!node) {
        return false;
    }

    // Initialize node
    node->next = NULL;
    node->item = item;

    LinkedList *ptr = *head;

    // Is empty?
    if (!ptr) {
        *head = node;
        return true;
    }

    while (ptr) {
        // Insert node at back.
        if (!ptr->next) {
            ptr->next = node;
            return true;
        }

        ptr = ptr->next;
    }

    // Should not happen
    return false;
}

/**
 * Prepend an item.
 * @param head Head of the list.
 * @param item Item to insert.
 * @return true if success. False otherwise.
 */
bool LinkedList_push_front(LinkedList **head, Item item) {
    LinkedList *node = malloc(sizeof(LinkedList));

    // Allocation failed?
    if (!node) {
        return false;
    }

    // Initialize node
    node->next = *head;
    node->item = item;

    *head = node;

    return true;
}

/**
 * Get nth item
 * @param head Head of the list
 * @param n Index
 * @param output Where to save result?
 * @return true if success. False otherwise
 */
bool LinkedList_nth(LinkedList *head, uintptr_t n, Item *output) {
    LinkedList *ptr = head;

// Is empty?
    if (!head) {
        return false;
    }

    while (n--) {
        ptr = ptr->next;

// Out of range?
        if (ptr == NULL) {
            return false;
        }
    }

    *
            output = ptr->item;

    return true;
}

/**
 * Pop first item and return it
 * @param head Head of the list
 * @param output Where to save result?
 * @return true if success. False otherwise.
 */
bool LinkedList_pop_front(LinkedList **head, Item *output) {
    // Is empty?
    if (!*head) {
        return false;
    }

    *output = (*head)->item;
    *head = (*head)->next;

    return true;
}

#undef LinkedList
#undef LinkedList_push_back
#undef LinkedList_push_front
#undef LinkedList_nth
#undef LinkedList_pop_front