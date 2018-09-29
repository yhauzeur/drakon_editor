// Autogenerated with DRAKON Editor 1.32
import java.util.List;

public class Sorter {

    public static void quicksort(Comparer comparer, List<Object> collection, int begin, int end) {
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
                if (compare(comparer, collection, begin, last) <= 0) {
                    
                } else {
                    // item 31
                    swap(collection, begin, last);
                }
            } else {
                // item 34
                pivotIndex = begin + length / 2;
                // item 42
                swap(collection, pivotIndex, last);
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
                    if (compare(comparer, collection, i, last) < 0) {
                        // item 44
                        swap(collection, i, storeIndex);
                        storeIndex++;
                    }
                    // item 350003
                    i++;
                }
                // item 47
                swap(collection, storeIndex, last);
                // item 48
                quicksort(comparer, collection, begin, storeIndex);
                // item 49
                quicksort(comparer, collection, storeIndex + 1, end);
            }
        }
    }

    private static int compare(Comparer comparer, List<Object> array, int leftIndex, int rightIndex) {
        // item 64
        Object left = array.get(leftIndex);
        Object right = array.get(rightIndex);
        // item 56
        return comparer.compare(left, right);
    }

    private static void swap(List<Object> array, int leftIndex, int rightIndex) {
        // item 65
        Object left = array.get(leftIndex);
        Object right = array.get(rightIndex);
        // item 63
        array.set(leftIndex, right);
        array.set(rightIndex, left);
    }
}
