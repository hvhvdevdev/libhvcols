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
#define LinkedList_pop_back CONCAT(LinkedList_,Item,_pop_back)
#define LinkedList_size CONCAT(LinkedList_,Item,_size)

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

    *output = ptr->item;

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

    LinkedList *next = (*head)->next;

    free(*head);
    *head = next;

    return true;
}

/**
 * Pop last item and return it
 * @param head Head of the list
 * @param output Where to save result?
 * @return true if success. False otherwise.
 */
bool LinkedList_pop_back(LinkedList **head, Item *output) {
    // Is empty?
    if (!*head) {
        return false;
    }

    // Single element?
    if (!(*head)->next) {
        return LinkedList_pop_front(head, output);
    }

    LinkedList *ptr = *head;

    while (ptr->next->next) {
        ptr = ptr->next;
    }

    *output = ptr->next->item;

    free(ptr->next);
    ptr->next = NULL;

    return true;
}

/**
 * Size of list
 * @param ptr
 * @return size of list.
 */
uintptr_t LinkedList_size(LinkedList *ptr) {
    uintptr_t size = 0;

    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    return size;
}

#undef LinkedList
#undef LinkedList_push_back
#undef LinkedList_push_front
#undef LinkedList_nth
#undef LinkedList_pop_front
#undef LinkedList_pop_back
#undef LinkedList_size