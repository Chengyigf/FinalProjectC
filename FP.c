#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void showArray(int arr[], int length){
    printf("[");
    for (int i = 0; i < length-1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[length-1]);
}


void bubbleSort(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
        // showArray(arr, length);
    }
}

void selectionSort(int arr[], int length){
    for (int i = 0; i < length-1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if(arr[j] < arr[min]) min = j; 
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        // showArray(arr, length);
    }
}

void insertionSort(int arr[], int length){
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(key < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        // showArray(arr, length);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int tempLow = low;
    int tempHigh = high;
    while(tempLow < tempHigh){
        
        // cari element lebih besar dari pivot
        while(arr[tempLow] <= pivot && tempLow <= high - 1){
            tempLow++;
        }

        // cari element lebih kecil dari pivot dari belakang
        while(arr[tempHigh] > pivot && tempHigh >= low + 1){
            tempHigh--;
        }
        if(tempLow < tempHigh) swap(&arr[tempLow], &arr[tempHigh]);
    }
    swap(&arr[low], &arr[tempHigh]);
    return tempHigh;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

int linearSearch(int search, int arr[], int length){
    for(int x = 0; x < length; x++){
        if(arr[x] == search) return x;
    }
    return -1;
}

int binarySearch(int search, int arr[], int length){
    int left = 0, right = length - 1;
    int middle;
    while(right >= left){
        middle = (left + right) / 2;
        if(arr[middle] == search)
            return middle;
        else{
            if(search < arr[middle]) // SISI KIRI
                right = middle - 1;
            else // SISI KANAN
                left = middle + 1;
        }
    }
    return -1;
}

int main(){
    int angka;
    int algo = -1;;
    int arr1[6000];
    int arr2[16000];
    int arr3[64000];

    while( algo != 0){
        printf("\nPROGRAM PENGURUTAN DAN PENCARIAN\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Quicksort\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("0. Keluar\n");
        
        printf("Masukkan pilihan anda : ");
        scanf("%d", &algo);

        if(algo == 0){
            break;
        }

        printf("Data yang disajikan\n");
        printf("1. 6000\n");
        printf("2. 16000\n");
        printf("3. 64000\n");

        printf("Masukkan pilihan anda : ");
        scanf("%d", &angka);

        if(angka == 1){
            srand(time(0));
            for(int i = 0; i < 6000; i++){
                arr1[i] = rand();
            }

            if(algo == 1){
                clock_t start, end;
                start = clock();
                insertionSort(arr1, 6000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 2){
                clock_t start, end;
                start = clock();
                bubbleSort(arr1, 6000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 3){
                clock_t start, end;
                start = clock();
                quickSort(arr1, 0, 6000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 4){
                int a = rand();
                clock_t start, end;
                start = clock();
                int res = linearSearch(a, arr1, 6000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Angka %d ditemukan di index %d\n", a, res);
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 5){
                int a = rand();
                quickSort(arr1, 0, 6000);
                clock_t start, end;
                start = clock();
                int res = binarySearch(a, arr1, 6000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Angka %d ditemukan di index %d\n", a, res);
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            }
                
        } else if(angka == 2){
            srand(time(0));
            for(int i = 0; i < 16000; i++){
                arr2[i] = rand();
                // printf("%d", arr1[i]);
            }

            if(algo == 1){
                clock_t start, end;
                start = clock();
                insertionSort(arr2, 16000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 2){
                clock_t start, end;
                start = clock();
                bubbleSort(arr2, 16000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 3){
                clock_t start, end;
                start = clock();
                quickSort(arr2, 0, 16000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 4){
                int a = rand();
                clock_t start, end;
                start = clock();
                int res = linearSearch(a, arr2, 16000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Angka %d ditemukan di index %d\n", a, res);
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 5){
                int a = rand();
                quickSort(arr2, 0, 16000);
                clock_t start, end;
                start = clock();
                int res = binarySearch(a, arr2, 16000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Angka %d ditemukan di index %d\n", a, res);
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            }

        } else if(angka == 3){
            srand(time(0));
            for(int i = 0; i < 64000; i++){
                arr3[i] = rand();
            }

            if(algo == 1){
                clock_t start, end;
                start = clock();
                insertionSort(arr3, 64000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 2){
                clock_t start, end;
                start = clock();
                bubbleSort(arr3, 64000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 3){
                clock_t start, end;
                start = clock();
                quickSort(arr3, 0, 64000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 4){
                int a = rand();
                clock_t start, end;
                start = clock();
                int res = linearSearch(a, arr3, 64000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Angka %d ditemukan di index %d\n", a, res);
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            } else if(algo == 5){
                int a = rand();
                quickSort(arr3, 0, 64000);
                clock_t start, end;
                start = clock();
                int res = binarySearch(a, arr3, 64000);
                end = clock();
                double total_time = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Angka %d ditemukan di index %d\n", a, res);
                printf("Waktu yang dibutuhkan = %lf detik\n", total_time);
            }
        }
    }
}

