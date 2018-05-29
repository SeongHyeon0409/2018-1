package hw4;
import java.util.Random;

public class SortArray {

	public static void displae(int[] data)
	{
		for(int i=0; i<data.length; i++)
		{
			System.out.println(data[i]);
		}
	}
	
	 public static void selectionSort(int[] data){
	        int size = data.length;
	        int min; 
	        int temp;
	        
	        for(int i=0; i<size-1; i++){ 
	            min = i;
	            for(int j=i+1; j<size; j++){
	                if(data[min] > data[j]){
	                    min = j;
	                }
	            }
	            temp = data[min];
	            data[min] = data[i];
	            data[i] = temp;
	        }
	    }
	 
	 public static void insertionSort(int[] A){
	        int size = A.length;
	        int temp = 0;
	        int j = 0;
	        for(int i = 1; i < size; i++){
	            temp = A[i];
	            for(j=i-1; j>=0 && temp<A[j]; j--){
	                A[j+1] = A[j];
	            }
	            A[j+1] = temp;
	        }
	    }

	 public static void shellSort(int[] arr) {

			int interval = arr.length / 2;
		
			while (interval != 0) {

				for (int i = 0; i < interval; i++) {

					for (int p = i + interval; p < arr.length; p += interval) {
						int key = arr[p];
						int j = p - interval;
						while (j >= 0) {
							if (key < arr[j]) {
								arr[j + interval] = arr[j];
							} else 
								break;
							j -= interval;
						} 
						arr[j + interval] = key;
					} 
				}
				
				interval /= 2;
			}
	 	}
	 
	 public static void main( String[] args ) 
	 {
		 //size 100
		 System.out.println("====== size : 100 ======");
		 int N = 100;
		 int i;
		 int[] a = new int[N];

	     Random rr = new Random();
	     
	     for (i = 0; i < N; i++) {
	            a[i] = rr.nextInt(1000);
	        }
	     
		 long startTime = System.currentTimeMillis();
		 insertionSort(a);
		 
		 long endTime = System.currentTimeMillis();

		 long elaspedTime = endTime - startTime;
		 
		 System.out.println("insertionSrot : " + elaspedTime);
		 
		 
		 startTime = System.currentTimeMillis();
		 
		 
		 selectionSort(a);
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("selectionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 shellSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("shellSort : " + elaspedTime);
		 
		 System.out.println("====== size : 1000 ======");
		 
		 N = 1000;
		 a = new int[N];
		
		 for (i = 0; i < N; i++) {
	            a[i] = rr.nextInt(1000);
	        }
	     
		 
		 startTime = System.currentTimeMillis();
		 
		 insertionSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("insertionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 selectionSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("seletionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 shellSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("shellSort : " + elaspedTime);
		 
		 
		 
		 System.out.println("====== size : 10000 ======");
		 
		 N = 10000;
		 a = new int[N];
		
		 for (i = 0; i < N; i++) {
	            a[i] = rr.nextInt(1000);
	        }
		 
		 startTime = System.currentTimeMillis();
		 
		 insertionSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("insertionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 selectionSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("seletionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 shellSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("shellSort : " + elaspedTime);
		 
		 System.out.println("====== size : 100000 ======");
		 
		 N = 100000;
		 a = new int[N];
		
		 for (i = 0; i < N; i++) {
	            a[i] = rr.nextInt(1000);
	        }
	     
		 
		 
		 startTime = System.currentTimeMillis();
		 
		 insertionSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("insertionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 selectionSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("seletionSrot : " + elaspedTime);
		 
		 startTime = System.currentTimeMillis();
		 
		 shellSort(a);
		 
		 endTime = System.currentTimeMillis();

		 elaspedTime = endTime - startTime;
		 
		 System.out.println("shellSort : " + elaspedTime);
		 
	 }

}

