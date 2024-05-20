// File: python/algo_module.c
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "quicksort.h"

static PyObject* py_quicksort(PyObject* self, PyObject* args) {
    PyObject* listObj;
    
    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &listObj))
        return NULL;

    int len = PyList_Size(listObj);
    int* arr = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        PyObject* temp = PyList_GetItem(listObj, i);
        if (!PyLong_Check(temp)) {
            free(arr);
            PyErr_SetString(PyExc_TypeError, "List items must be integers.");
            return NULL;
        }
        arr[i] = PyLong_AsLong(temp);
    }

    quickSort(arr, 0, len - 1);

    PyObject* resultList = PyList_New(len);
    for (int i = 0; i < len; i++) {
        PyList_SetItem(resultList, i, PyLong_FromLong(arr[i]));
    }

    free(arr);
    return resultList;
}

static PyMethodDef QuickSortMethods[] = {
    {"quicksort",  py_quicksort, METH_VARARGS, "Sorts a list of integers using QuickSort."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef quicksortmodule = {
    PyModuleDef_HEAD_INIT,
    "quicksort",   /* name of module */
    NULL,          /* module documentation, may be NULL */
    -1,            /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    QuickSortMethods
};

PyMODINIT_FUNC PyInit_quicksort(void) {
    return PyModule_Create(&quicksortmodule);
}
