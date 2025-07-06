# PythonC-API
A python module written in cpp containing sorting functions for arrays.

## Building the cpp module
To build the module:

0. Install PyPI packages 
    ```bash
    pip install -r requirements.txt
    ```
1. Ensure `g++` is installed:
   ```bash
   g++ --version
   ```
2. Verify necessary headers are in place with:
   ```bash
   dnf list --installed | grep python3-devel
   ```
3. Run setup script:
   ```bash
   cd sort_module/
   python setup.py build_ext --inplace
   cd ..
   ```
   If successful, a `.so` file will be compiled in the directory

## How to import 
```python
from sort_module import cpp_sort, py_sort
```

## How to example
```bash
python main.py
```

# Todo-section
---

-4057
