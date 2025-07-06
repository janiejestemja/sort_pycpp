#include <Python.h>
#include <vector>

// Cpp function serving as example
double cpp_function(double x, double y) {
    return x + y;
}

// Quicksort algorithm for doubles
std::vector<double> quicksort(std::vector<double> arr) {
    if (arr.size() <= 1) return arr;

    double pivot = arr[arr.size() / 2];

    std::vector<double> left, middle, right;

    for (double num : arr) {
        if (num < pivot) left.push_back(num);
        else if (num == pivot) middle.push_back(num);
        else right.push_back(num);
    }

    std::vector<double> sorted_left = quicksort(left);
    std::vector<double> sorted_right = quicksort(right);

    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());

    return sorted_left;
}

// Wrapper for quicksort
static PyObject* py_quicksort(PyObject* self, PyObject* args) {
    PyObject* py_vec;
    if (!PyArg_ParseTuple(args, "O", &py_vec)) {
        return nullptr;
    }
    std::vector<double> vec;
    if (PyList_Check(py_vec)) {
        for (Py_ssize_t i = 0; i < PyList_Size(py_vec); ++i) {
            vec.push_back(PyFloat_AsDouble(PyList_GetItem(py_vec, i)));
        }
    }
    std::vector<double> return_vec;
    return_vec = quicksort(vec);

    PyObject* py_return_vec = PyList_New(return_vec.size());

    for (size_t i = 0; i < return_vec.size(); i++) {
        PyList_SetItem(py_return_vec, i, Py_BuildValue("d", return_vec[i]));
    }

    return py_return_vec;
}
// Mergesort algorithm helperfunction
std::vector<double> merge(std::vector<double> left, std::vector<double> right) {
    std::vector<double> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) result.push_back(left[i++]);
        else result.push_back(right[j++]);
    }

    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);

    return result;
}

// Mergesort algorithm
std::vector<double> mergesort(std::vector<double> arr) {
    if (arr.size() <= 1) return arr;

    size_t middle = arr.size() / 2;
    std::vector<double> left(arr.begin(), arr.begin() + middle);
    std::vector<double> right(arr.begin() + middle, arr.end());

    return merge(mergesort(left), mergesort(right));
}

// Wrapper for mergesort
static PyObject* py_mergesort(PyObject* self, PyObject* args) {
    PyObject* py_vec;
    if (!PyArg_ParseTuple(args, "O", &py_vec)) {
        return nullptr;
    }
    std::vector<double> vec;
    if (PyList_Check(py_vec)) {
        for (Py_ssize_t i = 0; i < PyList_Size(py_vec); ++i) {
            vec.push_back(PyFloat_AsDouble(PyList_GetItem(py_vec, i)));
        }
    }
    std::vector<double> return_vec;
    return_vec = mergesort(vec);

    PyObject* py_return_vec = PyList_New(return_vec.size());

    for (size_t i = 0; i < return_vec.size(); i++) {
        PyList_SetItem(py_return_vec, i, Py_BuildValue("d", return_vec[i]));
    }

    return py_return_vec;
}

// Method definitions for the module
static PyMethodDef CppMethods[] = {
    {"quicksort", py_quicksort, METH_VARARGS, "Quicksort for arrays"},
    {"mergesort", py_mergesort, METH_VARARGS, "Mergesort for arrays"},
    {nullptr, nullptr, 0, nullptr}, // Sentinel
};

// Module definition
static struct PyModuleDef cpp_sort= {
    PyModuleDef_HEAD_INIT,
    "cpp_sort", // Module name
    nullptr, // Module documentation
    -1, // Size of per-interpreter state of the module
    CppMethods //Methods defined in the module
};

// Module initialisation function
PyMODINIT_FUNC PyInit_cpp_sort(void) {
    return PyModule_Create(&cpp_sort);
}
