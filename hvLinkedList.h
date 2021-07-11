/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <stdint.h>

#ifndef Item
#define Item int
#endif

#define _CONCAT(id1, id2) id1##id2
#define CONCAT(id1, id2) _CONCAT(id1,id2)

#define hvLinkedListOfItem CONCAT(hvLinkedListOf,Item)
#define hvLinkedList_push_back_Item CONCAT(hvLinkedList_push_back_,Item)
#define hvLinkedList_push_front_Item CONCAT(hvLinkedList_push_front_,Item)
#define hvLinkedList_nth_Item CONCAT(hvLinkedList_nth_,Item)
#define hvLinkedList_pop_front_Item CONCAT(hvLinkedList_pop_front_,Item)

/**
 * Linked List Data Structure
 */
typedef struct hvLinkedListOfItem {
    Item item;
    struct hvLinkedListOfItem *next;
} hvLinkedListOfItem;

/**
 * Append an item.
 * @param head Head of the list.
 * @param item Item to insert.
 * @return true if success. False otherwise.
 */
bool hvLinkedList_push_back_Item(hvLinkedListOfItem **head, Item item) {
    hvLinkedListOfItem *node = malloc(sizeof(hvLinkedListOfItem));

    // Allocation failed?
    if (!node) {
        return false;
    }

    // Initialize node
    node->next = NULL;
    node->item = item;

    hvLinkedListOfItem *ptr = *head;

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
bool hvLinkedList_push_front_Item(hvLinkedListOfItem **head, Item item) {
    hvLinkedListOfItem *node = malloc(sizeof(hvLinkedListOfItem));

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
bool hvLinkedList_nth_Item(hvLinkedListOfItem *head, uintptr_t n, Item *output) {
    hvLinkedListOfItem *ptr = head;

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
 * @return first item in the list
 */
bool hvLinkedList_pop_front_Item(hvLinkedListOfItem **head, Item *output) {
    // Is empty?
    if (!*head) {
        return false;
    }

    *output = (*head)->item;
    *head = (*head)->next;

    return true;
}

#undef hvLinkedListOfItem
#undef hvLinkedList_push_back_Item
#undef hvLinkedList_push_front_Item
#undef hvLinkedList_nth_Item
#undef hvLinkedList_pop_front_Item