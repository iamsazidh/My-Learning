def binarySearch(A, n, x):
    left = 0; right = n -1; mid = 0
    while(left <= right):
        mid = left + (right - left) // 2
        if A[mid] == x:
            return mid
        if A[mid] > x:
            right = mid - 1
        else:
            left = mid + 1
    return -1
    
arr = [1, 2, 5, 8, 10, 15, 18, 20, 24, 26, 27, 29, 30]
l = len(arr)
x = int(input("Enter the number: "))
result = binarySearch(arr, l, x)
if result != -1:
    print("The number's index is " + str(result) + "\n")
else:
    print("Error 404\n")