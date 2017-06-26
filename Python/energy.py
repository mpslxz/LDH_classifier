import numpy as np
from hadamard import walsh


def energy_features(img, bands=np.array([0.4, 0.3, 0.3])):
    assert img.shape[0] == img.shape[1]
    assert np.log2(img.shape[0]) % 1 == 0
    assert np.sum(bands) == 1
    H = walsh(img.shape[0])
    transformed = np.mat(H) * np.mat(img) * np.mat(H)
    transformed[0, 0] = 0
    energies = []
    sum_bands = 0
    energy_sums = 0
    for band in bands:
        bandwidth = int((band + sum_bands) * transformed.shape[0])
        mask = np.zeros_like(transformed)
        mask[0:bandwidth, 0:bandwidth] = 1
        area = bandwidth**2 - int(sum_bands * transformed.shape[0])**2
        band_energy = np.sum(np.abs(np.multiply(mask, transformed)))
        energies.append((1./np.sqrt(area)) * np.abs(band_energy - energy_sums))
        energy_sums += band_energy
        sum_bands += band
    return np.array(energies)

if __name__ == "__main__":
    test = np.zeros((256, 256))
    print energy_features(test)