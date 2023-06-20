package Sorting;
import java.util.*;

public class Quick {

    public static int partition(int[] a, int lb, int ub) {
        int pivot, start, end, temp;
        pivot = a[lb];
        start = lb;
        end = ub;
        while(start < end) {
            while(a[start] <= pivot) {
                start++;
            }
            while(a[end] > pivot) {
                end--;
            }
            if(start < end) {
                temp = a[start];
                a[start] = a[end];
                a[end] = temp;
            }
        }
        temp = a[lb];
        a[lb] = a[end];
        a[end] = temp;
        return end;
}

    public static void sort(int[] a, int lb, int ub) {
        int i;
    if(lb < ub) {
        i = partition(a, lb, ub);
        sort(a, lb, i-1);
        sort(a, i+1, ub);
    }
}
    

    public static void main(String args[]) {
        int n, i;
        int a[] = new int[10];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the no of elements: \n");
        n = sc.nextInt();
        for(i=0; i<n; i++) {
            System.out.print("Enter value: ");
            a[i] = sc.nextInt();
        } 
        sort(a, 0, n-1);
        System.out.println("After Sorting...");
        for(i=0; i<n; i++) {
            System.out.print(a[i] + "   ");
        }
    }
}
