
import numpy as np
import matplotlib.pyplot as plt

def bit_min(nbits: int):
    return -2**(nbits - 1)

def bit_max(nbits: int):
    return 2**(nbits - 1) - 1

def cal_default_zero_point(vector: np.ndarray, scale_factor: float, nbits: int=2):
    
    print("Use min: ", np.round(bit_min(nbits) - (np.min(vector) / scale_factor)))
    print("Use max: ", np.round(bit_max(nbits) - (np.max(vector) / scale_factor)))
    
    return np.round(bit_min(nbits) - (np.min(vector) / scale_factor))

def cal_default_scale_factor(vector: np.ndarray, nbits: int=2):
    return (np.max(vector) - np.min(vector)) / (bit_max(nbits) - bit_min(nbits))

def cal_symmetric_zero_point(vector: np.ndarray, scale_factor: float, nbits: int=2, full_range=True):
    return 0.

def cal_symmetric_scale_factor(vector: np.ndarray, nbits: int=2, full_range=True):
    scale_factor = 0.
    print("Min: ", np.abs(np.min(vector)), end=" ")
    print( ">" , end=" ") if np.abs(np.min(vector)) > np.abs(np.max(vector)) else print( "<" , end=" ")
    print(" Max: ", np.abs(np.max(vector)))
    if full_range:
        scale_factor = np.abs(np.min(vector) / bit_min(nbits)) if np.abs(np.min(vector)) > np.abs(np.max(vector)) \
                else np.abs(np.max(vector)) / bit_max(nbits)
    else:
        scale_factor = np.abs(np.min(vector) / bit_max(nbits)) if np.abs(np.min(vector)) > np.abs(np.max(vector)) \
                else np.abs(np.max(vector)) / bit_min(nbits)
    return scale_factor


def quanziation_range(scale_factor: float, zero_point: int, nbits: int=2):
    print(f"bit range: {np.arange(bit_min(nbits), bit_max(nbits)+1)}")
    return (np.arange(bit_min(nbits), bit_max(nbits)+1) - zero_point) * scale_factor

if __name__=="__main__":
    print("Hello, Quantization World!")
    vector = np.array([2.09, -0.98, 1.48, 0.09, 0.05, 
                       -0.14, -1.08, 2.12, -0.91, 1.92, 
                       0., -1.03, 1.87, 0., 1.53, 
                       1.49])
    
    mode = "symmetric_full_range"

    if mode == "default":
        scale_factor = cal_default_scale_factor(vector)
        zero_point = cal_default_zero_point(vector, scale_factor)
    elif mode == "symmetric_full_range":
        scale_factor = cal_symmetric_scale_factor(vector, full_range=True)
        zero_point = cal_symmetric_zero_point(vector, scale_factor, full_range=True)
    elif mode == "symmetric_restricted_range":
        scale_factor = cal_symmetric_scale_factor(vector, full_range=False)
        zero_point = cal_symmetric_zero_point(vector, scale_factor, full_range=False)

    print(f"Scale factor: {scale_factor} and Zero point: {zero_point}")

    # 2. Calculate quantization range
    quantization_range = quanziation_range(scale_factor, zero_point)
    print(f"Quantization range: {quantization_range}")
    print(f"Data range: {np.sort(vector)}")

    # 3. Quantize, dequantize and quantization error
    quantized_vector = np.round(vector / scale_factor) + zero_point
    print(f"Quantized vector: {quantized_vector}")
    dequantized_vector = (quantized_vector - zero_point) * scale_factor
    print(f"Dequantized vector: {dequantized_vector}")
    quantization_error = vector - dequantized_vector
    print(f"Quantization error: {quantization_error}")
    
    # 4. Plot
    fig, axes = plt.subplots(nrows=5, ncols=1)
    axes[0].plot(vector, "*", label="Original")
    axes[1].plot(dequantized_vector, "*", label="Dequantized")
    axes[2].plot(quantized_vector, "*", label="Quantized")
    axes[3].plot(vector, "*", label="Original")
    axes[3].plot(dequantized_vector, "*", label="Dequantized")
    axes[4].plot(quantization_error, "*", label="Error")
    # plt.show()
