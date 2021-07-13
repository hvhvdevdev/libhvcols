#include <string.h>
#include <stdio.h>
#include "vendor/bdd-for-c.h"
#include "hvLinkedList.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmacro-redefined"
#pragma clang diagnostic ignored "-Wshadow"

#define Item float

#include "hvLinkedList.h"

#define Item char

#include "hvLinkedList.h"

#undef Item


spec("LinkedList") {
    static LinkedList_float *my_float_list;
    static LinkedList_char *my_char_list;
    static float output_f;
    static char output_c;

    context("List of float is empty") {
        before_each() {
            my_float_list = NULL;
        }

        describe("push_back") {
            it("should insert item to head") {
                check(LinkedList_float_push_back(&my_float_list, 1.0f))
                check(my_float_list->item == 1.0f)
            }

            it("should insert 2 items in right order") {
                check(LinkedList_float_push_back(&my_float_list, 1.0f))
                check(LinkedList_float_push_back(&my_float_list, 2.0f))
                check(my_float_list->item == 1.0f)
                check(my_float_list->next->item == 2.0f)
            }
        }

        describe("push_front") {
            it("should insert item to head") {
                check(LinkedList_float_push_front(&my_float_list, 1.0f))
                check(my_float_list->item == 1.0f)
            }

            it("should insert 2 items in reverse order") {
                check(LinkedList_float_push_front(&my_float_list, 1.0f))
                check(LinkedList_float_push_front(&my_float_list, 2.0f))
                check(my_float_list->item == 2.0f)
                check(my_float_list->next->item == 1.0f)
            }
        }

        describe("pop_front") {
            it("should fail") check(!LinkedList_float_pop_front(&my_float_list, &output_f))
        }

        describe("pop_back") {
            it("should fail") check(!LinkedList_float_pop_back(&my_float_list, &output_f))
        }

        describe("nth") {
            it("should fail with index 0") {
                check(!LinkedList_float_nth(my_float_list, 0, &output_f))
            }

            it("should fail with index 1") {
                check(!LinkedList_float_nth(my_float_list, 1, &output_f))
            }
        }
    }

    context("List of char has 1 element") {
        before_each() {
            my_char_list = NULL;
            LinkedList_char_push_front(&my_char_list, 'a');
        }

        describe("nth") {
            it("should get first item") {
                check(LinkedList_char_nth(my_char_list, 0, &output_c))
                check(output_c == 'a')
            }

            it("should fail to get second item") check(!LinkedList_char_nth(my_char_list, 1, &output_c))

        }

        describe("pop_front") {
            it("should get first item") {
                check(LinkedList_char_pop_front(&my_char_list, &output_c))
                check(output_c == 'a')
            }

            it("should fail if called twice") {
                check(LinkedList_char_pop_front(&my_char_list, &output_c))
                check(!LinkedList_char_pop_front(&my_char_list, &output_c))
            }
        }

        describe("pop_back") {
            it("should get first item") {
                check(LinkedList_char_pop_back(&my_char_list, &output_c))
                check(output_c == 'a')
            }

            it("should fail if called twice") {
                check(LinkedList_char_pop_back(&my_char_list, &output_c))
                check(!LinkedList_char_pop_back(&my_char_list, &output_c))
            }
        }
    }

    context("List of char has 3 elements") {
        before_each() {
            my_char_list = NULL;
            LinkedList_char_push_back(&my_char_list, 'a');
            LinkedList_char_push_back(&my_char_list, 'b');
            LinkedList_char_push_back(&my_char_list, 'c');
        }

        describe("nth") {
            it("should get first item") {
                check(LinkedList_char_nth(my_char_list, 0, &output_c))
                check(output_c == 'a')
            }

            it("should get second item") {
                check(LinkedList_char_nth(my_char_list, 1, &output_c))
                check(output_c == 'b')
            }

            it("should get first item") {
                check(LinkedList_char_nth(my_char_list, 2, &output_c))
                check(output_c == 'c')
            }

            it("should fail to get fourth item") {
                check(!LinkedList_char_nth(my_char_list, 3, &output_c))
            }
        }

        describe("pop_front") {
            it("should get three items in right order") {
                check(LinkedList_char_pop_front(&my_char_list, &output_c))
                check(output_c == 'a')
                check(LinkedList_char_pop_front(&my_char_list, &output_c))
                check(output_c == 'b')
                check(LinkedList_char_pop_front(&my_char_list, &output_c))
                check(output_c == 'c')
            }
        }
    }
}

#pragma clang diagnostic pop