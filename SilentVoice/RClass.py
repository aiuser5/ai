import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#signum fuction
def sgn(net):
    if net>=0:
        return 1
    else:
        return -1


T = np.array([[0.1, 0.1, -1, 0],
              [0.2, 0.1, -1, 0],
              [0.5, 0.1, -1, 1],
              [0.6, 0.1, -1, 1],
              [0.3, 0.3, -1, 2],
              [0.4, 0.3, -1, 2]])

W = np.array([[-0.1, 0.15, 0.2],
              [-0.2, 0.11, 0.17],
              [0.17, 0.16, 0.11]])

D = np.array([[1, -1, -1],
              [-1, 1, -1],
              [-1, -1, 1]])

# Initialize Learning rates
learning_rates = [1, 2]

max_epochs = 20

# Initialize an array to store errors for each combination of LR (c) and epochs
error_array = np.zeros((len(learning_rates), max_epochs - 1))

for c_idx, c in enumerate(learning_rates):
    
    
    print(f"LR : {learning_rates}")
    # Initialization of weight vector
    weight = W.copy()
    epochs = 1
    error = 1000

    while (error != 0 and epochs < max_epochs):

        # Initialize Error to zero
        error = 0
        
        print(f"Learning Rate: {c}")
        print(f"Epoch : {epochs}")
        

        for k in range(len(T)):
            train = T[k, :-1]
            class_label = int(T[k, -1])

            net = np.zeros(3)

            # Calculate net
            for i in range(3):
                net_i = np.dot(train, weight[i])
                net[i] = sgn(net_i)

            # Update Weight Vector
            for i in range(3):
                for j in range(3):
                    weight[i][j] = weight[i][j] + (0.5 * c * (D[class_label][i] - net[i]) * train[j])

                # Update error for Training set k
                error = error + 0.5 * pow((D[class_label][i] - net[i]), 2)

                print(f"Training Set {train} output = {D[class_label]} Actual = {net}")

        print(f"Weight vector {weight}")
        print(f"Error {error}")
        error_array[c_idx][epochs - 1] = error
        print()
        epochs = epochs + 1

# Create an array of epochs for plotting
epochs_list = np.arange(1, max_epochs)

# Plot line graph
plt.figure(figsize=(12, 6))
for c_idx, c in enumerate(learning_rates):
    plt.plot(epochs_list, error_array[c_idx], label=f"C = {c}", marker='o')

plt.legend()
plt.xticks(epochs_list)
plt.xlabel("Epochs")
plt.ylabel("Errors")
plt.show()