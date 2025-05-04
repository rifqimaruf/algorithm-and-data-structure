import numpy as np

def step_function(x):
    return 1 if x >= 0 else 0

class Perceptron:
    def __init__(self, input_size, learning_rate = 0.01):
        self.weights = np.zeros(input_size + 1)
        self.lr = learning_rate

    def predict(self, x):
        x = np.insert(x, 0, 1)
        weighted_sum = np.dot(self.weights, x)
        return step_function(weighted_sum)
    
    def train(self, x, y, epochs=10):
        for _ in range(epochs):
            for xi, target in zip(X, y):
                x_input = np.insert(xi, 0, 1)
                prediction = self.predict(xi)
                error = target - prediction
                self.weights += self.lr * error * x_input
                print(_, prediction, error, self.weights)

X = np.array([[0,0], [0, 1], [1, 0], [1, 1]])
y = np.array([0, 0, 0, 1])  

p = Perceptron(input_size = 2)
p.train(X, y, epochs=5) 

print("final weight (bias, x1, x2): ", p.weights)
for x in X:
    print(f"{x} => {p.predict(x)}")