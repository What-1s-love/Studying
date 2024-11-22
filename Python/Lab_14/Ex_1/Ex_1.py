import numpy as np
import matplotlib.pyplot as plt

# Визначення функції
x = np.linspace(-2, 5, 500)
y = x * np.sin(5 * x)

# Побудова графіка
plt.plot(x, y, label="Y(x) = x*sin(5x)", color="green", linewidth=2)

# Налаштування графіка
plt.title("Графік функції Y(x) = x*sin(5x)", fontsize=14)
plt.xlabel("x", fontsize=12, color="blue")
plt.ylabel("Y(x)", fontsize=12, color="blue")
plt.legend()
plt.grid(True)

# Відображення графіка
plt.show()

