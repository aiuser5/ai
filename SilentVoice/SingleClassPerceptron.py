import numpy as np
import matplotlib.pyplot as plt

# Signum function
def sgn(net):
    if net >= 0:
        return 1
    else:
        return -1

# Define the training data
d = np.array([1, -1, 1])
x = np.array([
    [1, -2, 1.5, 0],
    [1, -0.5, -2, -1.5],
    [0, 1, -1, 1.5]
])

# Initialize weight vector
I_Weight = np.array([1, -1.5, 1.5, 0.5])

# Array to store Errors
Error_Array = np.zeros((2, 6))

# Training Epochs
maxepochs = 7

for i in range(1, 3):
    # Initialize weight vector
    Weight = np.copy(I_Weight)
    print(Weight)

    # Initialize Learning rate
    LR = i
    epochs = 1
    Error = 1000

    while Error != 0 and epochs < maxepochs:
        # Initialize Error to zero
        Error = 0
        print(f"LR : {LR}")
        print(f"Epoch : {epochs}")
        for k in range(len(x)):
            net = 0
            # Calculate net
            net = np.dot(x[k], Weight)
            output = sgn(net)

            # Update Weight Vector
            for j in range(4):
                Weight[j] = Weight[j] + 0.5 * LR * (d[k] - output) * x[k][j]

            # Update error for Training set k
            Error = Error + 0.5 * (d[k] - output) * (d[k] - output)

            print(f"Training Set {x[k]} output = {output} desired = {d[k]}")

        print(f"Weight vector {Weight}")
        print(f"Error {Error}")
        Error_Array[LR - 1][epochs - 1] = Error
        print()
        epochs = epochs + 1

epochs_list = np.arange(1, 7)

plt.plot(epochs_list, Error_Array[0], label="C = 1", marker='o')
plt.plot(epochs_list, Error_Array[1], label="C = 2", marker='o')
plt.legend()
plt.xticks(epochs_list)
plt.xlabel("Epochs")
plt.ylabel("Errors")
plt.show()
