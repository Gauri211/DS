package Sorting;
import java.util.*;

public class Bubble {
    public static void main(String args[]) {
        int i, n, temp;
        int arr[] = new int[10];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the no of elements: \n");
        n = sc.nextInt();
        for(i=0; i<n; i++) {
            System.out.print("Enter value: ");
            arr[i] = sc.nextInt();
        } 
        for(i=0; i<n; i++) {
            for(int j=0; j<n-i; j++) {
                if(arr[j] > arr[j+i]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        
        System.out.println("After Sorting...");
        for(i=0; i<n; i++) {
            System.out.print(arr[i] + "   ");
        }
    }
}