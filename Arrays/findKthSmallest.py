# can be done by:
# -> sorting and return arr[k-1] O(n*log(n))
# -> using set and iterating k-1 elements ahead O(n*log(n))
# -> using min heap or max heap and popping k-times (for min heap) and n-k times (for max heap) O(n + k*log(n))

# max heap (using -ve values in a min heap)
import heapq
def kthSmallest(arr, l, r, k):
        n = r-l+1
        lst = [x*-1 for x in arr]
        heapq.heapify(lst)
        for i in range(n-k+1):
            res = heapq.heappop(lst)
        return -res 

# -> modification of quick sort where you test for pivot_index == k-1 and only partition the part of the array which will contain k-1 (implemented below)
# -> using maps by storing freq of each element as value
# -> using binary search
class Solution:
    def kthSmallest(self, arr, l, r, k):
        while l < r:
            pi = self.partition(arr, l, r)
            if pi == k-1:
                return arr[pi]
            elif k-1 < pi:
                r = pi-1
            else:
                l = pi+1
    
    def partition(self, arr, l, r):
        pivot = arr[r]
        pi = l
        for i in range(l, r):
            if arr[i] < pivot:
                arr[i], arr[pi] = arr[pi], arr[i]
                pi += 1
        arr[r], arr[pi] = arr[pi], arr[r]
        return pi