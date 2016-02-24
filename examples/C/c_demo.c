/* Autogenerated with DRAKON Editor 1.27 */
#include "c_demo.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif

struct String
{
	char* Buffer;
	int Length;
};


struct ObjectArray
{
	void** Buffer;
	int Count;
	ObjectDestructor ElementDestructor;
};

struct IntArray
{
	int* Buffer;
	int Count;
};

static int Compare(
    struct ObjectArray* collection,
    int firstIndex,
    int secondIndex,
    ObjectComparer comparer
);

static void Fill(
    struct ObjectArray* output,
    const char* strings[]
);

static void IterationDemo(void);

static void Print(
    struct ObjectArray* array
);

static void PrintHello(void);

static void PrintIntsArrow(
    const struct IntArray* collection
);

static void PrintIntsBackward(
    const struct IntArray* collection,
    int n
);

static void PrintIntsFor(
    const struct IntArray* collection
);

static void Put(
    struct ObjectArray* array,
    int index,
    const char* text
);

static void QuickSortDemo(void);

static void SortStrings(
    struct ObjectArray* strings
);

static void StringsAreSorted(
    struct ObjectArray* array
);

static void Swap(
    struct ObjectArray* collection,
    int firstIndex,
    int secondIndex
);

static void alt_select_test(void);

static void alternative_select(
    int value,
    int expected
);







static int Compare(
    struct ObjectArray* collection,
    int firstIndex,
    int secondIndex,
    ObjectComparer comparer
) {
    // item 648
    void* first = ObjectArray_Get(collection, firstIndex);
    void* second = ObjectArray_Get(collection, secondIndex);
    /* item 649 */
    return comparer(first, second);
    
}

static void Fill(
    struct ObjectArray* output,
    const char* strings[]
) {
    // item 557
    int i = 0;
    const char** current = strings;
    
    item_559 :
    if (*current == 0) {
        return;
    } else {
    }
    
    // item 558
    Put(output, i, *current);
    /* item 560 */
    i++;
    current++;
    goto item_559;
    
}

static void IterationDemo(void) {
    // item 529
    int n = 15;
    /* item 504 */
    /* own */
    struct IntArray* sequence = 0;
    /* item 447 */
    printf("iteration demo\n");
    /* item 505 */
    sequence = Fibonacci(n);
    /* item 507 */
    PrintIntsArrow(sequence);
    PrintIntsBackward(sequence, n);
    PrintIntsFor(sequence);
    /* item 506 */
    printf("\n");
    /* item 508 */
    IntArray_Delete(sequence);
    return;
    
}

static void Print(
    struct ObjectArray* array
) {
    // item 571
    int i;
    struct String* item;
    int length = ObjectArray_Count(array);
    /* item 5720001 */
    i = 0;
    
    item_5720002 :
    if (i < length) {
        /* item 573 */
        item = ObjectArray_Get(array, i);
        printf("%s ", String_GetBuffer(item));
        /* item 5720003 */
        i++;
        goto item_5720002;
    } else {
        /* item 575 */
        printf("\n");
        return;
    }
    
}

static void PrintHello(void) {
    // item 722
    printf("DRAKON-C demo\n");
    printf("=============\n");
    return;
    
}

static void PrintIntsArrow(
    const struct IntArray* collection
) {
    // item 497
    int i, length, item;
    /* item 484 */
    printf("using if and arrow:\n");
    /* item 479 */
    length = IntArray_Count(collection);
    i = 0;
    
    item_480 :
    if (i < length) {
    } else {
        /* item 485 */
        printf("\n");
        return;
    }
    
    // item 478
    item = IntArray_Get(collection, i);
    printf("%d ", item);
    /* item 482 */
    i++;
    goto item_480;
    
}

static void PrintIntsBackward(
    const struct IntArray* collection,
    int n
) {
    item_522 :
    if (n >= 0) {
    } else {
        /* item 528 */
        printf("\n");
        return;
    }
    
    // item 520
    printf("%d ", IntArray_Get(collection, n));
    /* item 524 */
    n--;
    goto item_522;
    
}

static void PrintIntsFor(
    const struct IntArray* collection
) {
    // item 500
    int i, length, item;
    /* item 499 */
    printf("using for:\n");
    /* item 498 */
    length = IntArray_Count(collection);
    /* item 4920001 */
    i = 0;
    
    item_4920002 :
    if (i < length) {
        /* item 502 */
        item = IntArray_Get(collection, i);
        printf("%d ", item);
        /* item 4920003 */
        i++;
        goto item_4920002;
    } else {
        /* item 501 */
        printf("\n");
        return;
    }
    
}

static void Put(
    struct ObjectArray* array,
    int index,
    const char* text
) {
    // item 535
    /* Transient ownership. */
    struct String* item;
    /* item 536 */
    item = String_FromCString(text);
    ObjectArray_Put(array, index, item);
    return;
    
}

static void QuickSortDemo(void) {
    // item 541
    /* own */
    struct ObjectArray* unsorted = 0;
    struct ObjectArray* sorted = 0;
    struct ObjectArray* reverse = 0;
    struct ObjectArray* empty = 0;
    struct ObjectArray* flat = 0;
    /* item 540 */
    const char* unsortedA[] = { "the", "sooner", "we", "start", "this", "the", "better", 0 };
    const char* sortedA[] = { "aa", "bb", "cc", "dd", "ee", "ff", 0 };
    const char* reverseA[] = { "ff", "ee", "dd", "cc", "bb", "aa", 0 };
    const char* emptyA[] = { 0 };
    const char* flatA[] = { "flat", "flat", "flat", "flat", "flat", 0};
    /* item 577 */
    printf("quick sort demo\n");
    /* item 547 */
    unsorted = ObjectArray_Create(7, (ObjectDestructor)&String_Delete);
    sorted = ObjectArray_Create(6, (ObjectDestructor)&String_Delete);
    reverse = ObjectArray_Create(6, (ObjectDestructor)&String_Delete);
    empty = ObjectArray_Create(0, (ObjectDestructor)&String_Delete);
    flat = ObjectArray_Create(5, (ObjectDestructor)&String_Delete);
    /* item 563 */
    Fill(unsorted, unsortedA);
    Fill(sorted, sortedA);
    Fill(reverse, reverseA);
    Fill(empty, emptyA);
    Fill(flat, flatA);
    /* item 669 */
    SortStrings(unsorted);
    SortStrings(sorted);
    SortStrings(reverse);
    SortStrings(empty);
    SortStrings(flat);
    /* item 576 */
    Print(unsorted);
    Print(sorted);
    Print(reverse);
    Print(empty);
    Print(flat);
    /* item 711 */
    StringsAreSorted(unsorted);
    StringsAreSorted(sorted);
    StringsAreSorted(reverse);
    StringsAreSorted(empty);
    StringsAreSorted(flat);
    /* item 544 */
    ObjectArray_Delete(unsorted);
    ObjectArray_Delete(sorted);
    ObjectArray_Delete(reverse);
    ObjectArray_Delete(empty);
    ObjectArray_Delete(flat);
    return;
    
}

static void SortStrings(
    struct ObjectArray* strings
) {
    // item 675
    ObjectComparer comparer = (ObjectComparer)&String_Compare;
    int length = ObjectArray_Count(strings);
    /* item 676 */
    QuickSort(strings, 0, length, comparer);
    return;
    
}

static void StringsAreSorted(
    struct ObjectArray* array
) {
    int _sw6930000_ = 0;
    // item 692
    int i, j;
    struct String* current;
    struct String* after;
    int length = ObjectArray_Count(array);
    /* item 6830001 */
    i = 0;
    
    item_6830002 :
    if (i < length) {
        /* item 685 */
        current = ObjectArray_Get(array, i);
        /* item 6860001 */
        j = i + 1;
    } else {
        return;
    }
    
    item_6860002 :
    if (j < length) {
        /* item 688 */
        after = ObjectArray_Get(array, j);
        /* item 6930000 */
        _sw6930000_ = String_Compare(current, after);
    } else {
        /* item 6830003 */
        i += 1;
        goto item_6830002;
    }
    
    // item 6930001
    if (_sw6930000_ == -1) {
        /* item 700 */
        goto item_6860003;
    } else {
    }
    
    // item 6930002
    if (_sw6930000_ == 0) {
        /* item 701 */
    } else {
        goto item_6930003;
    }
    
    item_6860003 :
    j += 1;
    goto item_6860002;
    
    item_6930003 :
    if (_sw6930000_ == 1) {
    } else {
        /* item 6930004 */
        UnexpectedBranch(_sw6930000_);
    }
    
    // item 702
    /* item 689 */
    printf("Collection is not sorted.\n");
    abort();
    return;
    
}

static void Swap(
    struct ObjectArray* collection,
    int firstIndex,
    int secondIndex
) {
    // item 658
    if (firstIndex == secondIndex) {
        return;
    } else {
        /* item 641 */
        void* first = ObjectArray_Get(collection, firstIndex);
        void* second = ObjectArray_Get(collection, secondIndex);
        /* item 642 */
        ObjectArray_Put(collection, firstIndex, second);
        ObjectArray_Put(collection, secondIndex, first);
        return;
    }
    
}

static void alt_select_test(void) {
    // item 730
    alternative_select(-100, -1);
    alternative_select(100, 1);
    alternative_select(0, 0);
    return;
    
}

static void alternative_select(
    int value,
    int expected
) {
    // item 736
    int actual;
    
    // item 7370001
    if (value < 0) {
        /* item 745 */
        actual = -1;
        goto item_748;
    } else {
    }
    
    // item 7370002
    if (value == 0) {
        /* item 746 */
        actual = 0;
    } else {
        /* item 747 */
        actual = 1;
    }
    
    item_748 :
    if (actual == expected) {
        goto item_7580001;
    } else {
    }
    
    // item 754
    printf("alt select failure!\n");
    /* item 774 */
    abort();
    
    item_7580001 :
    if (value < 0) {
        /* item 766 */
        actual = -1;
        goto item_769;
    } else {
    }
    
    // item 7580002
    if (value == 0) {
        /* item 767 */
        actual = 0;
        goto item_769;
    } else {
    }
    
    // item 7580003
    if (value > 0) {
    } else {
        /* item 7580004 */
        UnexpectedBranch(0);
    }
    
    // item 768
    actual = 1;
    
    item_769 :
    if (actual == expected) {
        return;
    } else {
    }
    
    // item 771
    printf("alt select failure!\n");
    /* item 775 */
    abort();
    return;
    
}

struct IntArray* Fibonacci(
    int n
) {
    // item 470
    int i, f1, f2, fib;
    /* item 469 */
    /* own */
    struct IntArray* result = 0;
    
    // item 4530001
    if (n == 0) {
        /* item 457 */
        result = IntArray_Create(1);
        IntArray_Put(result, 0, 0);
        goto item_468;
    } else {
    }
    
    // item 4530002
    if (n == 1) {
        /* item 471 */
        result = IntArray_Create(2);
        IntArray_Put(result, 0, 0);
        IntArray_Put(result, 1, 1);
        goto item_468;
    } else {
        /* item 472 */
        result = IntArray_Create(n + 1);
        IntArray_Put(result, 0, 0);
        IntArray_Put(result, 1, 1);
        /* item 4630001 */
        i = 2;
    }
    
    item_4630002 :
    if (i <= n) {
        /* item 464 */
        f2 = IntArray_Get(result, i - 2);
        f1 = IntArray_Get(result, i - 1);
        fib = f1 + f2;
        /* item 465 */
        IntArray_Put(result, i, fib);
        /* item 4630003 */
        i += 1;
        goto item_4630002;
    } else {
    }
    
    item_468 :
    return result;
    
}

int IntArray_Count(
    const struct IntArray* object
) {
    // item 337
    if (object == 0) {
    } else {
        goto item_341;
    }
    
    // item 338
    printf("IntArray_Count: object is null.\n");
    abort();
    
    item_341 :
    return object->Count;
    
}

struct IntArray* IntArray_Create(
    int size
) {
    // item 279
    /* own */
    
    struct IntArray* object = 0;
    
    // item 282
    if (size < 0) {
    } else {
        goto item_286;
    }
    
    // item 283
    printf("IntArray_Create: size is negative.\n");
    abort();
    
    item_286 :
    object = Memory_Allocate(1, sizeof(struct IntArray));
    object->Count = size;
    
    // item 288
    if (size == 0) {
    } else {
        /* item 289 */
        object->Buffer = Memory_Allocate(size, sizeof(int));
        goto item_287;
    }
    
    // item 290
    object->Buffer = 0;
    
    item_287 :
    return object;
    
}

void IntArray_Delete(
    struct IntArray* object
) {
    // item 298
    if (object == 0) {
        return;
    } else {
        /* item 301 */
        Memory_Free(object->Buffer);
        Memory_Free(object);
        return;
    }
    
}

int IntArray_Get(
    const struct IntArray* object,
    int index
) {
    // item 307
    if (object == 0) {
    } else {
        goto item_311;
    }
    
    // item 308
    printf("IntArray_Get: object is null.\n");
    abort();
    
    item_311 :
    if ((index < 0) || (index >= object->Count)) {
    } else {
        goto item_315;
    }
    
    // item 316
    printf("IntArray_Get: index out of range. Index=%d\n", index);
    abort();
    
    item_315 :
    return object->Buffer[index];
    
}

void IntArray_Put(
    struct IntArray* object,
    int index,
    int value
) {
    // item 322
    if (object == 0) {
    } else {
        goto item_326;
    }
    
    // item 323
    printf("IntArray_Put: object is null.\n");
    abort();
    
    item_326 :
    if ((index < 0) || (index >= object->Count)) {
    } else {
        goto item_330;
    }
    
    // item 331
    printf("IntArray_Put: index out of range. Index=%d\n", index);
    abort();
    
    item_330 :
    object->Buffer[index] = value;
    return;
    
}

void* Memory_Allocate(
    int numOfObjects,
    int objectSize
) {
    // item 347
    /* own */
    void* buffer = 0;
    
    // item 350
    if (objectSize <= 0) {
    } else {
        goto item_354;
    }
    
    // item 349
    printf("Memory_Allocated: non-positive objectSize: %d\n", objectSize);
    abort();
    
    item_354 :
    if (numOfObjects <= 0) {
    } else {
        goto item_357;
    }
    
    // item 351
    printf("Memory_Allocated: non-positive numOfObjects: %d\n", numOfObjects);
    abort();
    
    item_357 :
    buffer = calloc(
    	(size_t)numOfObjects,
    	(size_t)objectSize);
    
    // item 358
    if (buffer == 0) {
    } else {
        goto item_346;
    }
    
    // item 359
    printf(
    "Memory_Allocated: could not allocate memory: numOfObjects=%d, objectSize=%d\n", 
    numOfObjects, objectSize);
    abort();
    
    item_346 :
    return buffer;
    
}

void Memory_Free(
    void* buffer
) {
    // item 367
    if (buffer == 0) {
        return;
    } else {
        /* item 366 */
        free(buffer);
        return;
    }
    
}

int ObjectArray_Count(
    const struct ObjectArray* object
) {
    // item 432
    if (object == 0) {
    } else {
        goto item_436;
    }
    
    // item 433
    printf("ObjectArray_Count: object is null.\n");
    abort();
    
    item_436 :
    return object->Count;
    
}

struct ObjectArray* ObjectArray_Create(
    int size,
    ObjectDestructor elementDestructor
) {
    // item 374
    /* own */
    
    struct ObjectArray* object = 0;
    
    // item 377
    if (size < 0) {
    } else {
        goto item_381;
    }
    
    // item 378
    printf("ObjectArray_Create: size is negative.\n");
    abort();
    
    item_381 :
    object = Memory_Allocate(1, sizeof(struct ObjectArray));
    object->Count = size;
    object->ElementDestructor = elementDestructor;
    
    // item 383
    if (size == 0) {
    } else {
        /* item 384 */
        object->Buffer = Memory_Allocate(size, sizeof(void*));
        goto item_382;
    }
    
    // item 385
    object->Buffer = 0;
    
    item_382 :
    return object;
    
}

void ObjectArray_Delete(
    struct ObjectArray* object
) {
    // item 438
    int i;
    
    // item 393
    if (object == 0) {
        return;
    } else {
    }
    
    // item 441
    if (object->ElementDestructor == 0) {
        goto item_396;
    } else {
        /* item 4370001 */
        i = 0;
    }
    
    item_4370002 :
    if (i < object->Count) {
        /* item 440 */
        object->ElementDestructor(object->Buffer[i]);
        /* item 4370003 */
        i++;
        goto item_4370002;
    } else {
    }
    
    item_396 :
    Memory_Free(object->Buffer);
    Memory_Free(object);
    return;
    
}

void* ObjectArray_Get(
    struct ObjectArray* object,
    int index
) {
    // item 402
    if (object == 0) {
    } else {
        goto item_406;
    }
    
    // item 403
    printf("ObjectArray_Get: object is null.\n");
    abort();
    
    item_406 :
    if ((index < 0) || (index >= object->Count)) {
    } else {
        goto item_410;
    }
    
    // item 411
    printf("ObjectArray_Get: index out of range. Index=%d\n", index);
    abort();
    
    item_410 :
    return object->Buffer[index];
    
}

void ObjectArray_Put(
    struct ObjectArray* object,
    int index,
    void* value
) {
    // item 417
    if (object == 0) {
    } else {
        goto item_421;
    }
    
    // item 418
    printf("ObjectArray_Put: object is null.\n");
    abort();
    
    item_421 :
    if ((index < 0) || (index >= object->Count)) {
    } else {
        goto item_425;
    }
    
    // item 426
    printf("ObjectArray_Put: index out of range. Index=%d\n", index);
    abort();
    
    item_425 :
    object->Buffer[index] = value;
    return;
    
}

void QuickSort(
    struct ObjectArray* collection,
    int begin,
    int end,
    ObjectComparer comparer
) {
    // item 633
    int i;
    int pivotIndex;
    int storeIndex;
    /* item 592 */
    int length = end - begin;
    int last = end - 1;
    
    // item 5930001
    if ((length == 0) || (length == 1)) {
        return;
    } else {
    }
    
    // item 5930003
    if (length == 2) {
    } else {
        /* item 614 */
        pivotIndex = begin + length / 2;
        /* item 650 */
        Swap(collection, pivotIndex, last);
        storeIndex = begin;
        /* item 6150001 */
        i = begin;
        goto item_6150002;
    }
    
    // item 610
    if (Compare(collection, begin, last, comparer) <= 0) {
        return;
    } else {
    }
    
    // item 611
    Swap(collection, begin, last);
    return;
    
    item_6150002 :
    if (i < last) {
    } else {
        /* item 655 */
        Swap(collection, storeIndex, last);
        /* item 656 */
        QuickSort(collection, begin, storeIndex, comparer);
        /* item 657 */
        QuickSort(collection, storeIndex + 1, end, comparer);
        return;
    }
    
    // item 651
    if (Compare(collection, i, last, comparer) < 0) {
        /* item 652 */
        Swap(collection, i, storeIndex);
        storeIndex++;
    } else {
    }
    
    // item 6150003
    i++;
    goto item_6150002;
    
}

int String_Compare(
    const struct String* left,
    const struct String* right
) {
    // item 237
    int i;
    int leftChar, rightChar;
    int result = 200;
    
    // item 229
    if (left == 0) {
    } else {
        goto item_233;
    }
    
    // item 230
    printf("String_Compare: left is null.\n");
    abort();
    
    item_233 :
    if (right == 0) {
    } else {
        goto item_665;
    }
    
    // item 234
    printf("String_Compare: right is null.\n");
    abort();
    
    item_665 :
    if (left == right) {
    } else {
        /* item 238 */
        i = 0;
        goto item_239;
    }
    
    // item 666
    result = 0;
    goto item_677;
    
    item_239 :
    if (i < left->Length) {
    } else {
        goto item_259;
    }
    
    // item 240
    if (i < right->Length) {
    } else {
        goto item_259;
    }
    
    // item 244
    leftChar = left->Buffer[i];
    rightChar = right->Buffer[i];
    
    // item 245
    if (leftChar < rightChar) {
        goto item_249;
    } else {
    }
    
    // item 246
    if (leftChar > rightChar) {
        /* item 248 */
        result = 1;
        goto item_677;
    } else {
    }
    
    // item 251
    i++;
    goto item_239;
    
    item_259 :
    
    // item 253
    if (left->Length < right->Length) {
    } else {
        goto item_254;
    }
    
    item_249 :
    result = -1;
    goto item_677;
    
    item_254 :
    if (left->Length > right->Length) {
    } else {
        /* item 257 */
        result = 0;
        goto item_677;
    }
    
    // item 256
    result = 1;
    
    item_677 :
    return result;
    
}

void String_Delete(
    struct String* object
) {
    // item 220
    if (object == 0) {
        return;
    } else {
        /* item 223 */
        Memory_Free(object->Buffer);
        Memory_Free(object);
        return;
    }
    
}

struct String* String_FromCString(
    const char* text
) {
    // item 211
    int length;
    /* item 203 */
    /* own */
    
    struct String* string = 0;
    
    // item 207
    if (text == 0) {
    } else {
        goto item_204;
    }
    
    // item 208
    printf("String_FromCString: text argument is null.\n");
    abort();
    
    item_204 :
    length = (int)strlen(text);
    /* item 212 */
    string = Memory_Allocate(1, sizeof(struct String));
    string->Buffer = Memory_Allocate(length + 1, sizeof(char));
    string->Length = length;
    /* item 213 */
    strncpy(string->Buffer, text, length);
    /* item 214 */
    return string;
    
}

const char* String_GetBuffer(
    const struct String* object
) {
    // item 271
    if (object == 0) {
    } else {
        goto item_275;
    }
    
    // item 272
    printf("String_Buffer: object is null.\n");
    abort();
    
    item_275 :
    return object->Buffer;
    
}

void UnexpectedBranch(
    int switchValue
) {
    // item 710
    printf("An unexpected value in the 'select' ('switch') construct: %d\n", switchValue);
    abort();
    return;
    
}

int main(
    int argc,
    char** argv
) {
    // item 725
    int result = 0;
    /* item 6 */
    PrintHello();
    /* item 773 */
    alt_select_test();
    /* item 724 */
    IterationDemo();
    QuickSortDemo();
    /* item 13 */
    return result;
    
}

/* End of C file. */

