from setuptools import setup, Extension
import os


# Define the extension module for QuickSort
quicksort_module = Extension(
    "apollolib.sorting.quicksort",
    sources=[
        os.path.join("bindings", "quicksort.c"),
        os.path.join("src", "sorting", "quicksort.c"),
    ],
    include_dirs=[os.path.join("src", "sorting")]
)

# Setup function to build the module
setup(
    name="apollolib",
    version="0.1",
    description="Library of algorithms implemented in Python C API",
    ext_modules=[quicksort_module],
)
