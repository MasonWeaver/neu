from math import exp

# SIGMOID
def sigmoid(x):
	return 1 / (1 + exp(-x))

def dsigmoid(x):
	return x * (1-x)

# TANH
def tanh(x):
	try:
		a = (exp(x) - exp(-x))
		b = (exp(x) + exp(-x))
		return a / b
	except OverflowError:
		print(x)

def dtanh(x):
	return 1 - pow(tanh(x), 2)

def relu(x):
	if (x > 0):
		return x
	else:
		return 0.0

def drelu(x):
	if (x > 0):
		return 1.0
	else:
		return 0.0