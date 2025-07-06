from setuptools import setup, Extension

cpp_sort = Extension(
    "cpp_sort",
    sources=["cpp_sort.cpp"]
)
setup(
    name="cpp_sort",
    version="1.0.0",
    description="Sorting functions for arrays",
    ext_modules=[cpp_sort],
)
