def main():
    print("This file contains function definitions written in Python")

def quicksort(arr):
    if len(arr) <= 1:
        return arr

    p = arr[len(arr) // 2]
    l = [x for x in arr if x < p]
    m = [x for x in arr if x == p]
    r = [x for x in arr if x > p]

    return quicksort(l) + m + quicksort(r)

def merge(left, right):
    sorted_array = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            sorted_array.append(left[i])
            i += 1
        else:
            sorted_array.append(right[j])
            j += 1

    sorted_array.extend(left[i:])
    sorted_array.extend(right[j:])

    return sorted_array

def mergesort(array : list) -> list:
    if len(array) == 1:
        return array

    center = len(array) // 2
    left = mergesort(array[:center])
    right = mergesort(array[center:])

    return merge(left, right)

if __name__ == "__main__":
    main()
