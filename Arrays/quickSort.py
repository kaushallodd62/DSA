import random

# using first element as pivot
def partition (self, arr, low, high):
    pivot = arr[low]
    i, j = low+1, high
    while i <= j:
        if arr[i] > pivot and arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
        if arr[i] <= pivot:
            i += 1
        if arr[j] >= pivot:
            j -= 1
        
    arr[low], arr[j] = arr[j], arr[low]
    return j

# using last element as pivot
def partition (self, arr, low, high):
    pi = low
    for i in range(low, high):
        if arr[i] < arr[high]:
            arr[i], arr[pi] = arr[pi], arr[i]
            pi += 1
        
    arr[pi], arr[high] = arr[high], arr[pi]
    return pi

# randomized partition
def random_partition(self, arr, low, high):
    n = high-low+1
    rand = int(random.random() * n)
    arr[low+rand], arr[high] = arr[high], arr[low+rand]
    return self.partition(arr, low, high)


# Divide and Conquer Classic Recursion Solution
def quickSort(self, arr, low, high):
    if low < high:
        pi = self.partition(arr, low, high)
        self.quickSort(arr, low, pi-1)
        self.quickSort(arr, pi+1, high)
    
# since quicksort uses tail recursion, we can apply tail-call optimization to reduce space
def quickSortTail (self, arr, low, high):
    while low < high:
        pi = self.partition(arr, low, high)
        left_subarray_size = pi-low+1
        right_subarray_size = high-pi+1

        # if left part is smaller than the right part, then recurse for the left part and handle right part iteratively
        if left_subarray_size < right_subarray_size:
            self.quickSortTail(arr, low, pi-1)
            low = pi+1
        else:
            self.quickSortTail(arr, pi+1, high)
            high = pi-1

