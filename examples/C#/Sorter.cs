// Autogenerated with DRAKON Editor 1.32
using System;
using System.Collections.Generic;

namespace Drakon.Editor.Example {

public class Sorter {


    public static void Quicksort(IComparer<Object> comparer, Object[] collection, int begin, int end) {
        // item 41
        int i;
        int pivotIndex;
        int storeIndex;
        // item 14
        int length = end - begin;
        int last = end - 1;
        // item 150001
        if ((length == 0) || (length == 1)) {
            
        } else {
            // item 150003
            if (length == 2) {
                // item 30
                if (Compare(comparer, collection, begin, last) <= 0) {
                    
                } else {
                    // item 31
                    Swap(collection, begin, last);
                }
            } else {
                // item 34
                pivotIndex = begin + length / 2;
                // item 42
                Swap(collection, pivotIndex, last);
                storeIndex = begin;
                // item 350001
                i = begin;
                while (true) {
                    // item 350002
                    if (i < last) {
                        
                    } else {
                        break;
                    }
                    // item 43
                    if (Compare(comparer, collection, i, last) < 0) {
                        // item 44
                        Swap(collection, i, storeIndex);
                        storeIndex++;
                    }
                    // item 350003
                    i++;
                }
                // item 47
                Swap(collection, storeIndex, last);
                // item 48
                Quicksort(comparer, collection, begin, storeIndex);
                // item 49
                Quicksort(comparer, collection, storeIndex + 1, end);
            }
        }
    }

    private static int Compare(IComparer<Object> comparer, Object[] array, int leftIndex, int rightIndex) {
        // item 64
        Object left = array[leftIndex];
        Object right = array[rightIndex];
        // item 56
        return comparer.Compare(left, right);
    }

    private static void Swap(Object[] array, int leftIndex, int rightIndex) {
        // item 66
        Object left = array[leftIndex];
        Object right = array[rightIndex];
        // item 63
        array[leftIndex] = right;
        array[rightIndex ] = left;
    }
}
}
