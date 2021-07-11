/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef Item
#define Item int
#endif

#define _CONCAT(id1, id2) id1##id2
#define CONCAT(id1, id2) _CONCAT(id1,id2)

#define hvLinkedListOfItem CONCAT(hvLinkedListOf,Item)
#define hvLinkedList_push_back_Item CONCAT(hvLinkedList_push_back_,Item)

/** \brief Linked List Data Structure.
 *
 */
typedef struct hvLinkedListOfItem {
    Item item;
    struct hvLinkedListOfItem *next;
} hvLinkedListOfItem;

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


#undef hvLinkedListOfItem
#undef hvLinkedList_push_back_Item