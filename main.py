from time import time, sleep
from random import randint
from tqdm import tqdm
from sort_module import cpp_sort, py_sort

def main():
    print("Generating random list to sort...")
    random_list = []
    for i in tqdm(range(1_000_000)):
        random_list.append(0.001 * randint(-10_000, 10_000))

    print("")
    print("Sorting in python...")
    print("")

    start = time()
    _ = py_sort.quicksort(random_list)
    pyqs_time = time() - start
    print("Quicksort Calculationtime (s): ", pyqs_time)

    start = time()
    _ = py_sort.mergesort(random_list)
    pyms_time = time() - start
    print("Mergesort Calculationtime (s): ", pyms_time)
    print("")

    print("Sorting in C++...")
    print("")

    start = time()
    _ = cpp_sort.quicksort(random_list)
    cppqs_time = time() - start
    print("Quicksort Calculationtime (s): ", cppqs_time)

    start = time()
    _ = cpp_sort.mergesort(random_list)
    cppms_time = time() - start
    print("Mergesort Calculationtime (s): ", cppms_time)
    print("")
    
    absdiff_qs = pyqs_time - cppqs_time
    reldiff_qs = pyqs_time / cppqs_time
    absdiff_ms = pyms_time - cppqs_time
    reldiff_ms = pyms_time / cppms_time
    print("Results for sorting 1,000,000 elements.")
    print("")
    print("Quicksort")
    print(f" C++ was {absdiff_qs:.4f} (s) faster than Python.")
    print(f" C++ was {reldiff_qs:.4f} times faster than Python.")
    print("")
    print("Mergesort")
    print(f" C++ was {absdiff_ms:.4f} (s) faster than Python.")
    print(f" C++ was {reldiff_qs:.4f} times faster than Python.")

if __name__ == "__main__":
    main()
