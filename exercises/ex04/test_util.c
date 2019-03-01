/* MinUnite test for impcode_v4 in util.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "trout/util.c"

int tests_run = 0;

// tests impcode(0) which should return "network unreachable"
static char *test0() {
  char *res = icmpcode_v4(0);
  char *message = "Test0 failed: icmpcode(0) should return 'network unreachable'";
  mu_assert(message, res == "network unreachable");
  return NULL;
}

// tests impcode(1) which should return "host unreachable"
static char *test1() {
  char *res = icmpcode_v4(1);
  char *message = "Test0 failed: icmpcode(1) should return 'host unreachable'";
  mu_assert(message, res == "host unreachable");
  return NULL;
}

// tests impcode(2) which should return "protocol unreachable"
static char *test2() {
  char *res = icmpcode_v4(2);
  char *message = "Test0 failed: icmpcode(2) should return 'protocol unreachable'";
  mu_assert(message, res == "protocol unreachable");
  return NULL;
}

// tests impcode(3) which should return port unreachable"
static char *test3() {
  char *res = icmpcode_v4(3);
  char *message = "Test0 failed: icmpcode(3) should return 'port unreachable'";
  mu_assert(message, res == "port unreachable");
  return NULL;
}

static char * all_tests() {
    mu_run_test(test0);
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
