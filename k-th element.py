user_input_1 = input("Enter the elements of the array separated by spaces: ")

array1 = [int(x) for x in user_input_1.split()]
    
user_input_2 = input("Enter the elements of the array separated by spaces: ")

array2 = [int(x) for x in user_input_2.split()]    

arr = array1 + array2 #Concatenate the two arrays



while True:
    k_input = int(input("Enter the k-th element of the array (1-based index): "))
    if k_input > 0 and k_input <= len(arr):
        break  # Exit the loop if k_input is valid
    else:
        print(f"Invalid input! Please enter a value between 1 and {len(arr)}.")

# Adjust k to 0-based index
k = k_input - 1


def insertion(array):
    for i in range(1,len(array)): #1---> 2---> 3---> 4---> 5 -- > len(array)
        key = array[i] 
        j = i-1 
        
        while j>=0 and array[j]>key: 
            array[j+1] = array[j]  
            j -= 1
            
        array[j+1] = key  
    return array


def find_k(array, key):
    final_arr = insertion(array)
    output = final_arr[k]
    print(f"\nThe sorted array {final_arr} // output of k({k + 1}):{output}")
    

    
find_k(arr, k)

