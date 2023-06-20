package Sorting;
import java.util.*;

public class Insertion {
    public static void main(String args[]) {
        int i, temp, j, n;
        int arr[] = new int[10];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the no of elements: \n");
        n = sc.nextInt();
        for(i=0; i<n; i++) {
            System.out.print("Enter value: ");
            arr[i] = sc.nextInt();
        } 
        for(i=1; i<n; i++) {
            temp = arr[i];
            j = i - 1;
            while(j>=0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        System.out.println("After Sorting...");
        for(i=0; i<n; i++) {
            System.out.print(arr[i] + "   ");
        }
    }
}
