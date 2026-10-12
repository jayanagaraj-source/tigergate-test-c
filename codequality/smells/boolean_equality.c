/* RULE: custom:boolean-equality | redundant comparison to a boolean literal */
#include <stdbool.h>
int check(int ready, int done, int active) {
    if (ready == true) return 1;
    if (done != false) return 2;
    while (active == false) active = 1;
    return ready != true;
}
