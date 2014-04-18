/* Autogenerated with DRAKON Editor 1.23 */
#ifndef INDEXED2_H58189
#define INDEXED2_H58189

#include "lib.h"

typedef struct indexed2 indexed2;
typedef struct employee employee;
typedef int (*employee_fun)(employee* item, void* user_data /* null */);


indexed2* /* own */
indexed2_create(void);


void
indexed2_destroy(indexed2* me /* own. null */);


int
indexed2_error(const indexed2* db);


int
employee_id(const employee* me);


employee* /* null */
indexed2_get_employee(indexed2* db,
    int rec_id);


const string8* /* null */
employee_cget_name(const employee* me);


int
employee_birthday(const employee* me);


int
indexed2_set_employee_name(indexed2* db,
    employee* _record_,
    string8* new_value /* own. null */);


int
indexed2_set_employee_birthday(indexed2* db,
    employee* _record_,
    int new_value);


employee* /* null */
indexed2_insert_employee(indexed2* db,
    string8* name /* own. null */,
    int birthday);


int
indexed2_delete_employee(indexed2* db,
    employee* record /* null */);


int
indexed2_employee_count(const indexed2* db);


int
indexed2_foreach_employee(indexed2* db,
    employee_fun visitor,
    void* user_data /* null */);


employee* /* null */
indexed2_employee_by_name_birthday(indexed2* db,
    const string8* name /* null */,
    int birthday);






int main(
    int argc,
    char** argv
);


#endif
