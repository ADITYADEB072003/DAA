def selection_sort(arr):
    for i in range(len(arr)-1):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        if i != min_index:
            temp = arr[i]
            arr[i] = arr[min_index]
            arr[min_index] = temp
    return arr


import random
import pandas as pd
# Generate 50,000 random numbers
arr = [random.randint(0, 1000000) for _ in range(50000)]

# Sort the array using selection_sort
sorted_arr = selection_sort(arr)
df=pd.DataFrame(sorted_arr)
# Print the first 10 elements to verify
print(df)
