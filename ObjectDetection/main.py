# ----------------------------------------------------------

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import tensorflow as tf

from autoencoder import Autoencoder
from denoise import Denoise
from anomalyDetector import AnomalyDetector
from getData import load_images
from sklearn.metrics import accuracy_score, precision_score, recall_score
from sklearn.model_selection import train_test_split
from tensorflow.keras import layers, losses
from tensorflow.keras.datasets import fashion_mnist
from tensorflow.keras import backend as K


(x_train, y_train) = load_images("Input", "Output") # fashion_mnist.load_data()
x_train = np.array(x_train)
x_train = x_train.astype('float32') / 255.
y_train = np.array(y_train)
y_train = y_train.astype('float32') / 255.

print(x_train.shape)
print(y_train.shape)

# ---

latent_dim = 64

autoencoder = Autoencoder(latent_dim)

autoencoder.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
autoencoder.build(input_shape=(None, 1275000))
autoencoder.summary()
# ------
autoencoder.fit(x_train, y_train,
                epochs=10,
                batch_size=8,
                shuffle=True,
                validation_data=(x_train, y_train))
# ------

loss, accuracy = autoencoder.evaluate(x_train, y_train, batch_size=8)

print("Test Loss:", loss)
print("Test Accuracy:", accuracy)

decoded_imgs = autoencoder.decoder(encoded_imgs).numpy()

encoded_imgs = tf.keras.backend.get_value(autoencoder.encoder(y_train))
decoded_imgs = tf.keras.backend.get_value(autoencoder.decoder(encoded_imgs))

# ------

n = 3
plt.figure(figsize=(20, 4))
for i in range(n):
    ax = plt.subplot(2, n, i+1)
    plt.imshow(y_train[i])
    plt.title("Original Input Images")
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)


# ------

n = 3
plt.figure(figsize=(20, 4))
for i in range(n):
    ax = plt.subplot(2, n, i + 1 + n)
    plt.imshow(decoded_imgs[i])
    plt.title("Predicted image")
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

plt.show()

# ------

encoded_imgs = tf.keras.backend.get_value(autoencoder.encoder(y_train))
decoded_imgs = tf.keras.backend.get_value(autoencoder.decoder(encoded_imgs))

# ------

n = 3
plt.figure(figsize=(20, 4))
for i in range(n):
    # display original
    ax = plt.subplot(2, n, i + 1)
    plt.imshow(y_train[i])
    plt.title("original")
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

    # display reconstruction
    ax = plt.subplot(2, n, i + 1 + n)
    plt.imshow(decoded_imgs[i])
    plt.title("reconstructed")
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

plt.show()

# -------

(x_train, y_train) = load_images("Input", "Output")
x_train = x_train.astype('float32') / 255.
y_train = y_train.astype('float32') / 255.

x_train = x_train[..., tf.newaxis]
y_train = y_train[..., tf.newaxis]

print(x_train.shape)

# -------

noise_factor = 0.2
x_train_noisy = x_train + noise_factor * tf.random.normal(shape=x_train.shape)
x_test_noisy = y_train + noise_factor * tf.random.normal(shape=y_train.shape)

x_train_noisy = tf.clip_by_value(x_train_noisy, clip_value_min=0., clip_value_max=1.)
x_test_noisy = tf.clip_by_value(x_test_noisy, clip_value_min=0., clip_value_max=1.)

# ------

n = 10
plt.figure(figsize=(10, 10)) # 20, 2
for i in range(n):
    ax = plt.subplot(1, n, i + 1)
    plt.title("original + noise")
    plt.imshow(K.get_value(tf.squeeze(x_test_noisy[i])))  # Convert to NumPy array using K.get_value()
    plt.gray()
plt.show()

autoencoder = Denoise()

autoencoder.compile(optimizer='adam', loss=losses.MeanSquaredError())


autoencoder.fit(tf.convert_to_tensor(x_train_noisy), tf.convert_to_tensor(x_train),
                epochs=10,
                batch_size=8,
                shuffle=True,
                validation_data=(x_test_noisy, y_train))
autoencoder.encoder.summary()

autoencoder.decoder.summary()

encoded_imgs = autoencoder.encoder(y_train).numpy()
decoded_imgs = autoencoder.decoder(encoded_imgs).numpy()

n = 10
plt.figure(figsize=(20, 4))
for i in range(n):

    # display original + noise
    ax = plt.subplot(2, n, i + 1)
    plt.title("original + noise")
    plt.imshow(tf.squeeze(x_test_noisy[i]))
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

    # display reconstruction
    bx = plt.subplot(2, n, i + n + 1)
    plt.title("reconstructed")
    plt.imshow(tf.squeeze(decoded_imgs[i]))
    plt.gray()
    bx.get_xaxis().set_visible(False)
    bx.get_yaxis().set_visible(False)
plt.show()

