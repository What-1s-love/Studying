def count_zeros(epsilon):
  """Count the number of trailing zeros in a floating-point number."""
  epsilon_str = f'{epsilon:.16f}'.split('.')[1]
  return len(epsilon_str) - len(epsilon_str.lstrip('0')) + 1


def display_results(y_values, step_size, initial_value):
  """Display formatted results in a table."""
  zeros = count_zeros(step_size)
  current_value = initial_value
  for index, y_value in enumerate(y_values):
      print(f"{index}) {current_value:.{zeros + 2}f}\t{y_value:.{zeros + 1}f}")
      current_value += step_size


def calculate_coefficients(x, step_size, p_function, q_function, f_function):
  """Calculate coefficients a[i], b[i], c[i], d[i]."""
  a_i = 1 - (step_size * p_function(x) / 2)
  b_i = step_size ** 2 * q_function(x) - 2
  c_i = 1 + (step_size * p_function(x) / 2)
  d_i = step_size ** 2 * f_function(x)
  return a_i, b_i, c_i, d_i


def solve_system(n, step_size, initial_value, alpha1, alpha2, beta1, beta2, A, B, p_function, q_function, f_function):
  """Solve the system of linear equations using the finite difference method."""
  x_values = [initial_value + i * step_size for i in range(n + 1)]
  y_values, pp_values, qq_values = [0] * (n + 1), [0] * (n + 1), [0] * (n + 1)

  b0, c0, d0 = (step_size * alpha1 - alpha2), alpha2, step_size * A
  an, bn, dn = -beta2, (step_size * beta1 + beta2), step_size * B

  pp_values[0], qq_values[0] = -c0 / b0, d0 / b0
  for i in range(1, n):
      a_i, b_i, c_i, d_i = calculate_coefficients(x_values[i], step_size, p_function, q_function, f_function)
      pp_values[i] = -c_i / (b_i + a_i * pp_values[i - 1])
      qq_values[i] = (d_i - a_i * qq_values[i - 1]) / (b_i + a_i * pp_values[i - 1])

  y_values[n] = (dn - an * qq_values[n - 1]) / (bn + an * pp_values[n - 1])
  for i in range(n - 1, -1, -1):
      y_values[i] = pp_values[i] * y_values[i + 1] + qq_values[i]

  return y_values


def p_function(x: float) -> float:
  return -x


def q_function(x: float) -> float:
  return 2


def f_function(x: float) -> float:
  return x + 1


def main():
  iteration_count = 0
  epsilon = 0.001
  alpha1, alpha2, beta1, beta2, A, B = 1, -1, 1, 0, 1, 3
  print("\nSolving a second-order ODE using the finite difference method\n")

  start_value, end_value = 1.3, 1.6
  step_size = 0.025
  num_intervals = 12

  if input("Run tests? (1-yes, 2-no): ").lower() == '2':
      alpha1 = float(input("Enter alpha1: "))
      alpha2 = float(input("Enter alpha2: "))
      beta1 = float(input("Enter beta1: "))
      beta2 = float(input("Enter beta2: "))
      A = float(input("Enter A: "))
      B = float(input("Enter B: "))
      print("\nEnter interval values (a;b):")
      start_value = float(input("a: "))
      end_value = float(input("b: "))
      num_intervals = int(input("Enter the initial number of intervals n: "))
      epsilon = float(input("Enter epsilon: "))

  max_difference = 0
  while True:
      iteration_count += 1
      step_size = (end_value - start_value) / num_intervals
      y_values, y_values_double = (
          solve_system(num_intervals, step_size, start_value, alpha1, alpha2, beta1, beta2, A, B,
                       p_function, q_function, f_function),
          solve_system(num_intervals * 2 - 1, step_size / 2, start_value, alpha1, alpha2, beta1, beta2, A, B,
                       p_function, q_function, f_function)
      )

      max_difference = max(abs(y_values_double[i * 2] - y_values[i]) for i in range(num_intervals))

      if max_difference < epsilon:
          print(f"\nNumber of intervals = {num_intervals}   Step size = {step_size:.{count_zeros(epsilon) + 4}f}")
          display_results(y_values, step_size, start_value)
          print(f"\nMethod called: {iteration_count} times")
          print(f"Approximation error: {max_difference:.{count_zeros(epsilon) + 4}f}")
          print(f"Step size: {step_size:.{count_zeros(epsilon) + 3}f}")
          break

      num_intervals *= 2


if __name__ == "__main__":
  main()