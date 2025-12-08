import math

def single_neuron_model(features: list[list[float]], labels: list[int], weights: list[float], bias: float) -> (list[float], float):
    probabilities = []

    # Forward pass: weighted sum + sigmoid
    for x in features:
        z = sum(w * xi for w, xi in zip(weights, x)) + bias
        y_hat = 1 / (1 + math.exp(-z))  # Sigmoid
        probabilities.append(round(y_hat, 4))

    # MSE
    mse = sum((p - y) ** 2 for p, y in zip(probabilities, labels)) / len(labels)
    mse = round(mse, 4)

    return probabilities, mse