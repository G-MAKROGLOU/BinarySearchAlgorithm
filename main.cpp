#include <iostream>

using namespace std;

//Variables needed for the program
int arraySize;
int choice;
int element;
int position = 0;
int minValue;
int maxValue;
int midValue;
int searchValue;
int searchIndex;

//Function declaration: Bubble sort algorithm to sort the array in ascending order
int sortAscending(int arr[0], int sizeOfArray){
    for(int i = 0; i <= sizeOfArray-2; i++){
        for(int j = i+1; j <= sizeOfArray-1; j++){
            int temp;
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

//Function declaration: Bubble sort algorithm to sort the array in descending order
int sortDescending(int arr[0], int sizeOfArray){
    for(int i = 0; i <= sizeOfArray-2; i++){
        for(int j = i+1; j <= sizeOfArray-1; j++){
            int temp;
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}


//Function declaration: Print the inserted array in a relative format.
void printArray(int arr[], int sizeOfArray){
    for(int j = 0; j < sizeOfArray; j++){
        if(position == 0){
            cout<<"[ ";
        }
        cout<<arr[j];
        position++;
        if(position == sizeOfArray){
            cout<<" ]";
        }
        if(position != sizeOfArray){
            cout<<", ";
        }
    }
    position = 0;
}



//Function declaration: Function that implements the binary search algorithm for ascending ordered arrays.
int binarySearchAlgorithmAscending(int value, int arr[], int sizeOfArray){
    minValue = 0;
    maxValue = sizeOfArray - 1;
    while(minValue <= maxValue){
        midValue = minValue +(maxValue - minValue)/2;
        if(arr[midValue] == value)return midValue;
        if(arr[midValue] < value) minValue = midValue + 1;
        else maxValue = midValue - 1;
    }
    return -1;
}

//Function declaration: Function that implements the binary search algorithm for descending ordered arrays.
int binarySearchAlgorithmDescending(int value, int arr[], int sizeOfArray){
    minValue = 0;
    maxValue = sizeOfArray - 1;
    while(minValue <= maxValue){
        midValue = minValue +(maxValue - minValue)/2;
        if(arr[midValue] == value)return midValue;
        if(arr[midValue] < value) maxValue = midValue - 1;
        else minValue = midValue + 1;
    }
    return -1;
}

//Function declaration: Function that recursively calls itself in case the number the user want to find is not found in the array.
//Because the binary search algorithm depends on the way the array is sorted, there is a function for both cases. This one, calls
// binarySearchAlgorithmAscending(int value, int arr[], int sizeOfArray)
void inCaseOfNotFoundAscending(int arr[], int arraySize){
    cout<<"\nEnter the value you want to binary search for: ";
    cin>>searchValue;
    searchIndex = binarySearchAlgorithmAscending(searchValue, arr, arraySize);
    if(searchIndex != -1) cout<<"The value "<<arr[searchIndex]<<" was found at index "<<searchIndex;
    else{
        cout<<"The number "<<searchValue<<" was not found in the array";
        inCaseOfNotFoundAscending(arr, arraySize);
    }
}

//Function declaration: Function that recursively calls itself in case the number the user want to find is not found in the array.
//Because the binary search algorithm depends on the way the array is sorted, there is a function for both cases. This one, calls
// binarySearchAlgorithmDescending(int value, int arr[], int sizeOfArray)
void inCaseOfNotFoundDescending(int arr[], int arraySize){
    cout<<"\nEnter the value you want to binary search for: ";
    cin>>searchValue;
    searchIndex = binarySearchAlgorithmDescending(searchValue, arr, arraySize);
    if(searchIndex != -1) cout<<"The value "<<arr[searchIndex]<<" was found at index "<<searchIndex;
    else{
        cout<<"The number "<<searchValue<<" was not found in the array";
        inCaseOfNotFoundDescending(arr, arraySize);
    }
}

//Function declaration: Function that lets the user decide the way the array will be sorted. Depending the choice, either
//inCaseNotFoundAscending(int arr[], int arraySize) or inCaseNotFoundDescending(int arr[], int arraySize) are called.
void wayToSort(int arr[], int sizeOfArray){
    cout<<"\nThe array has to be sorted in order for the binary search algorithm to be used!\nWould you like to sort it in ascending or descending order?\n";
    cout<<"1)Ascending 2)Descending:";
    cin>>choice;
    if(choice == 1){
        sortAscending(arr, sizeOfArray);
        cout<<"The array sorted in ascending order is: ";
        printArray(arr, arraySize);
        inCaseOfNotFoundAscending(arr, sizeOfArray);
    }
    else if(choice == 2){
        sortDescending(arr, sizeOfArray);
        cout<<"The array sorted in descending order is: ";
        printArray(arr, arraySize);
        inCaseOfNotFoundDescending(arr, sizeOfArray);
    }
    else{
        cout<<"Option not available. Choose one of the available options!";
        wayToSort(arr, sizeOfArray);
    }
}


//Main function of the program.
int main() {
    //User input for the size of the array
    cout<<"Enter the size of the array:";
    cin>>arraySize;
    int integerArray[arraySize];

    //User input for the values
    for(int i = 0; i < arraySize; i++){
        cout<<"Enter the value for array position number "<<i<<":";
        cin>>element;
        integerArray[i] = element;
        cout<<endl;
    }

    //Formatted output of the user input
    cout<<"The array inserted is: ";
    printArray(integerArray, arraySize);


    //Function call: wayToSort(int arr[], int sizeOfArray) -> This function calls triggers the corresponding to the user's choice
    //functionality of the program. If the user chooses to sort the array in ascending order the binarySearchAlgorithmAscending(int arr[], int arraySize)
    //method will be called alongside inCaseOfNotFoundAscending(int arr[], int arraySize) as a "safety" measure. If the user chooses to sort the array in
    //descending order the binarySearchAlgorithmDescending(int arr[], int arraySize)
    //method will be called alongside inCaseOfNotFoundDescending(int arr[], int arraySize) as a "safety" measure.
    wayToSort(integerArray, arraySize);

    return 0;
}
