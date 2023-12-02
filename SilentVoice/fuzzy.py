import matplotlib.pyplot as plt
import numpy as np

# Membership function
def mem(x, gamma):
    factor = gamma * abs(5 / max(x, 5) - x / max(x, 5))
    if factor == 0:
        return 1
    elif 0 < factor < 1:
        return 1 - factor
    else:
        return 0

x = [1, 2, 3, 4, 5, 6, 7, 8]
gamma_values = [1, 4]

# Calculate membership from 1 to 8 for gamma = 1, 4
membership_values = []

for gamma in gamma_values:
    mu = [mem(value, gamma) for value in x]
    membership_values.append(mu)

# Check for normality and convexity
for i, gamma in enumerate(gamma_values):
    is_normal = any(mu == 1 for mu in membership_values[i])
    # A fuzzy set µ ∈ F(IR) (i.e on real number) is convex if and only if µ(λx1 + (1 − λ)x2) ≥ min{µ(x1), µ(x2)} for all x1, x2 ∈ IR and all λ ∈ [0, 1].
    is_convex = all(mem((lambda_val * x1 + (1 - lambda_val) * x2), gamma) >= min(mem(x1, gamma), mem(x2, gamma)) 
                   for x1 in x for x2 in x for lambda_val in [0, 1])

    print(f'For γ = {gamma}:')
    for j, value in enumerate(x):
        print(f'µ({value}) = {membership_values[i][j]}')
    
    if is_normal:
        print('The fuzzy set is normal.')
    else:
        print('The fuzzy set is not normal.')
    
    if is_convex:
        print('The fuzzy set is convex.')
    else:
        print('The fuzzy set is not convex.')
    
    #print()

# Plot membership functions for both cases
for i, gamma in enumerate(gamma_values):
    plt.plot(x, membership_values[i], label=f'γ={gamma}')

plt.xlabel('x(Number)')
plt.ylabel('µ(x)(Membership)')
plt.legend()
plt.title('Membership vs x graph for Numbers Close to 5')
plt.grid(True)
plt.show()
