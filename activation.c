#include <Python.h>
#include <math.h>

float sigmoid(float x){
	return 1 / (1 + (pow((float)M_E, (float)-x)));
}

static PyObject *activation_sigmoid(PyObject *self, PyObject *args) {
	float x;
	float result;
	if(!PyArg_ParseTuple(args, "f", &x)) {
		printf("sigmoid requires a float!\n");
		Py_INCREF(Py_None);
		return Py_None;
	}
	result = pow((float)M_E, (float)-x);
	result = 1 / (1 + result);

	return Py_BuildValue("f", result);
}

static PyObject *activation_dsigmoid(PyObject *self, PyObject *args) {
	float y;
	float result;
	if(!PyArg_ParseTuple(args,"f", &y)){
		printf("dsigmoid requires a float!\n");
		Py_INCREF(Py_None);
		return Py_None;
	}
	result = y * (1-y);
	return Py_BuildValue("f", result);
}

static PyMethodDef module_methods[] = {
	{"sigmoid",  (PyCFunction)activation_sigmoid,  METH_VARARGS, NULL},
	{"dsigmoid", (PyCFunction)activation_dsigmoid, METH_VARARGS, NULL},
	{NULL}
};

PyMODINIT_FUNC initactivation(void) {
	PyObject *m;

	m = Py_InitModule("activation", module_methods);
	if (m == NULL) {
		return;
	}
}