#include <Python.h>
#include <gmpxx.h>
#include <string>

void factorial(unsigned int n, mpz_class &fact) {
    fact = 1;
    while (n > 1) {
        fact *= n;
        n--;
    }
}

static PyObject *say_hello(PyObject *self, PyObject *args)
{
    unsigned int n;

    if (!PyArg_ParseTuple(args, "I", &n)) {
        return NULL;
    }
    mpz_class fact;
    factorial(n, fact);

    return PyUnicode_FromString(fact.get_str().c_str());
}

static PyMethodDef HelloMethods[] =
{
     {"factorial", say_hello, METH_VARARGS, "Compute factorial"},
     {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef cModPyDem =
{
    PyModuleDef_HEAD_INIT,
    "hello", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    HelloMethods
};

PyMODINIT_FUNC PyInit_hello(void)
{
    return PyModule_Create(&cModPyDem);
}