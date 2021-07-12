#include <string.h>
#include <stdio.h>
#include "vendor/bdd-for-c.h"
#include "hvLinkedList.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmacro-redefined"

#define Item float

#include "hvLinkedList.h"

#define Item char

#include "hvLinkedList.h"

#undef Item


spec("LinkedList") {
    static hvLinkedListOffloat *my_float_list;
    static hvLinkedListOfchar *my_char_list;
    static float output;

    context("List of float is empty") {
        before_each() {
            my_float_list = NULL;
        }

        describe("push_back") {
            it("should insert item to head") {
                check(hvLinkedList_push_back_float(&my_float_list, 1.0f))
                check(my_float_list->item == 1.0f)
            }

            it("should insert 2 items in right order") {
                check(hvLinkedList_push_back_float(&my_float_list, 1.0f))
                check(hvLinkedList_push_back_float(&my_float_list, 2.0f))
                check(my_float_list->item == 1.0f)
                check(my_float_list->next->item == 2.0f)
            }
        }

        describe("push_front") {
            it("should insert item to head") {
                check(hvLinkedList_push_front_float(&my_float_list, 1.0f))
                check(my_float_list->item == 1.0f)
            }

            it("should insert 2 items in reverse order") {
                check(hvLinkedList_push_front_float(&my_float_list, 1.0f))
                check(hvLinkedList_push_front_float(&my_float_list, 2.0f))
                check(my_float_list->item == 2.0f)
                check(my_float_list->next->item == 1.0f)
            }
        }

        describe("pop_front") {
            it("should fail") check(!hvLinkedList_pop_front_float(&my_float_list, &output))
        }

        describe("nth") {
            it("should fail with index 0") {
                check(!hvLinkedList_nth_float(my_float_list, 0, &output))
            }

            it("should fail with index 1") {
                check(!hvLinkedList_nth_float(my_float_list, 1, &output))
            }
        }
    }
}

#pragma clang diagnostic pop