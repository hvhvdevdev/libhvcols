#include <string.h>
#include <stdio.h>
#include "vendor/bdd-for-c.h"
#include "hvLinkedList.h"

#define Item float

#include "hvLinkedList.h"

#undef Item

spec("LinkedList") {
    static hvLinkedListOfint *my_list;
    static hvLinkedListOffloat *my_float_list;

    context("my_list is empty") {
        describe("Append item to list") {
            before() {
                my_list = NULL;
            }

            it("should append 1 successfully") check(hvLinkedList_push_back_int(&my_list, 1))
            it("should have 1 as the first item") check(my_list->item == 1)
            it("should not have second item") check(my_list->next == NULL)
        }

        describe("Prepend item to list") {
            before() {
                my_list = NULL;
            }

            it("should prepend 1 successfully") check(hvLinkedList_push_front_int(&my_list, 1))
            it("should have 1 as the first item") check(my_list->item == 1)
            it("should not have second item") check(my_list->next == NULL)
        }
    }

    context("my_list have 1 as its only item") {
        before() {
            my_list = NULL;
            hvLinkedList_push_back_int(&my_list, 1);
        }
        it("should append 2 successfully") check(hvLinkedList_push_back_int(&my_list, 2))
        it("should still have 1 as the first item") check(my_list->item == 1)
        it("should have 2 as the second item") check(my_list->next->item == 2)
        it("should not have third item") check(my_list->next->next == NULL)
        it("should prepend 3 successfully") check(hvLinkedList_push_front_int(&my_list, 3))
        it("should have 3 as first item") check(my_list->item == 3)
        it("should have 1 as second item") check(my_list->next->item == 1)
    }

    context("my_float_list have 1.0f as its only item") {
        before() {
            my_float_list = NULL;
            hvLinkedList_push_back_float(&my_float_list, 1.0f);
        }
        it("should append 2.5f successfully") check(hvLinkedList_push_back_float(&my_float_list, 2.5f))
        it("should still have 1.0f as the first item") check(my_float_list->item == 1.0f)
        it("should have 2.5f as the second item") check(my_float_list->next->item == 2.5f)
        it("should not have third item") check(my_float_list->next->next == NULL)
    }
}