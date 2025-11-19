#include<stdio.h>
void binarySearch(int arr[], int n , int key){
    int low = 1,  mid, found = 0;
    int high  = n-1;
    printf("\n the array is : ");
    for(int i = 0; i<n; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
    while(low<=high){
        mid = (low+high)/2;
        printf("\n Index of the start array is : %d", low);
        printf("\n Index of the end of the array is %d", high);
        printf("\n The array is ");
        for(int i=low; i<=high; i++){
            printf("%d ", arr[i])
;        }
printf("\n");
if(arr[mid] == key){
    printf("\n Element found at index %d", mid);
    found =1;
    break;
}else if(arr[mid]<key){
    low = mid+1;
}else{
    high = mid-1;
}if(!found){
    printf("\n Element not found ");
}

    }
}
int main(){
        int n , key, arr[100];
        printf("ENter the number of elements of array: ");
        scanf("%d", &n);
        printf("Enter the %d  sorted elements of array ", n);
for(int i =0; i<n; i++){
    scanf("%d", &arr[i]);
}   
printf("Enter the element to search : ");
scanf("%d", &key);
binarySearch(arr, n , key);
return 0;
}


