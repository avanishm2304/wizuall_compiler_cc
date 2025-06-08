import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
# Clustering requires scikit-learn: pip install scikit-learn
try:
    from sklearn.cluster import KMeans
except ImportError:
    print('Warning: scikit-learn not found. Clustering features will not work.')
    KMeans = None

# Helper for WizuALL conditionals (non-zero scalar, non-empty/any non-zero vector)
def wz_truthy(val):
    if isinstance(val, (np.ndarray, list, tuple)):
        return len(val) > 0 and np.any(val)
    else:
        return val != 0

raw_xy_data = pd.read_csv("loop_plot_xy.csv", header=0).select_dtypes(include=np.number).to_numpy()
vectorX = raw_xy_data[:, int(0)]
vectorY = ((vectorX * 2) + 5)
plt.figure()
plt.plot(vectorX, vectorY)
plt.title('XY Plot')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)
plt.show()
raw_hist_data = pd.read_csv("loop_hist_data.csv", header=0).select_dtypes(include=np.number).to_numpy()
data = raw_hist_data[:, int(0)]
plt.figure()
plt.hist(data, bins=int(5))
plt.title('Histogram')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.show()
avg_data = np.mean(data)

# Native Python block
import numpy as np # Ensure numpy is available
import matplotlib.pyplot as plt # Ensure plt is available if needed later

print("\n--- test_csv_loops_plots.wiz Output ---")
if 'avg_data' in locals():
    print(f"Average calculated by WizuALL (printed by Python): {avg_data}")
else:
    print("Warning: avg_data not found.")

# Define native function
def native_printer(val):
  print(f"Printed from native_printer: {val}")
native_printer(avg_data)
threshold = 15
count = 0
index = 0
max_index = 10
while wz_truthy((index < max_index)):
    current_y = vectorY[int(index)]
    if wz_truthy((current_y > threshold)):
        count = (count + 1)
    index = (index + 1)

if 'count' in locals():
    print(f"Number of Y values > {threshold} (within first {max_index}): {count}")
else:
    print("Warning: loop count variable not found.")
revY = np.flip(vectorY)
sliceY = vectorY[int(2):int(5)]

if 'revY' in locals():
    print(f"Reversed vectorY (first 5, NumPy slice): {np.array(revY)[:5]}")
else:
    print("Warning: revY not found.")

if 'sliceY' in locals():
    print(f"Slice of vectorY (index 2 to 4, Wizuall): {np.array(sliceY)}")
else:
    print("Warning: sliceY not found.")

print("--- End of Loops/Plots Test ---")
