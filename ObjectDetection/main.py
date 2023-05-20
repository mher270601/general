# # import pandas as pd
# # import numpy as np
# # from tensorflow.keras.datasets import mnist
# # from sklearn.model_selection import train_test_split
# # from tensorflow.keras.preprocessing.image import ImageDataGenerator
# import cv2
# import numpy as np
# from tensorflow.keras.models import Sequential
# from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense
#
#
# image = cv2.imread("train/class1/image1.jpg")
# expected_image = cv2.imread("train/class1/image2.jpg")
# # If the image is non type of RGB, convert to RGB
# if len(image.shape) == 3 and image.shape[-1] == 3 and image[..., 0].mean() < image[..., 1].mean():
#     image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
#
# image = image.astype(np.float32) / 255
# # Convert the image to a numpy array
# image = np.array(image)
# # Convert the numpy array to a tensor
# image = np.expand_dims(image, axis=0)
# # X_train = image
#
# model = Sequential([
#     Dense(128, activation='relu', name='Input'),
#     Conv2D(32, (3, 3), activation='relu', input_shape=image.shape[1:]),
#     MaxPooling2D(pool_size=(2, 2)),
#     Conv2D(64, (3, 3), activation='relu'),
#     Dense(10, activation='softmax', name='Output')
# ])
#
# # Pass the normalized image as input to the CNN
# output = model.predict(image)
#
# # Compare the output image to the expected image
# diff = np.abs(output[0] - expected_image)
# print("Max difference:", np.max(diff))

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
# from tensorflow.keras.models import Model
from tensorflow.keras import backend as K

# tf.enable_eager_execution()

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
# loss=losses.CategoricalCrossentropy()
autoencoder.build(input_shape=(None, 1275000))
autoencoder.summary()
# ------
# print("by passed1")
# print("Shape of x_train:", x_train.shape)
# print("Shape of y_train:", y_train.shape)
autoencoder.fit(x_train, y_train,
                epochs=10,
                batch_size=8,
                shuffle=True,
                validation_data=(x_train, y_train))
# print("by passed2")
# ------

loss, accuracy = autoencoder.evaluate(x_train, y_train, batch_size=8)

print("Test Loss:", loss)
print("Test Accuracy:", accuracy)

#encoded_imgs = autoencoder.encoder(y_train).numpy()
#decoded_imgs = autoencoder.decoder(encoded_imgs).numpy()

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

# encoded_imgs = autoencoder.encoder(y_train).numpy()
# decoded_imgs = autoencoder.decoder(encoded_imgs).numpy()

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

# (x_train, _), (x_test, _) = fashion_mnist.load_data()
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
    #plt.imshow(tf.squeeze(x_test_noisy[i]))
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



# Download the dataset
# dataframe = pd.read_csv('http://storage.googleapis.com/download.tensorflow.org/data/ecg.csv', header=None)
# raw_data = dataframe.values
# dataframe.head()
#
# # The last element contains the labels
# labels = raw_data[:, -1]
#
# # The other data points are the electrocadriogram data
# data = raw_data[:, 0:-1]
#
# train_data, test_data, train_labels, test_labels = train_test_split(
#     data, labels, test_size=0.2, random_state=21
# )
#
# min_val = tf.reduce_min(train_data)
# max_val = tf.reduce_max(train_data)
#
# train_data = (train_data - min_val) / (max_val - min_val)
# test_data = (test_data - min_val) / (max_val - min_val)
#
# train_data = tf.cast(train_data, tf.float32)
# test_data = tf.cast(test_data, tf.float32)
#
#
# train_labels = train_labels.astype(bool)
# test_labels = test_labels.astype(bool)
#
# normal_train_data = train_data[train_labels]
# normal_test_data = test_data[test_labels]
#
# anomalous_train_data = train_data[~train_labels]
# anomalous_test_data = test_data[~test_labels]

# plt.grid()
# plt.plot(np.arange(140), normal_train_data[0])
# plt.title("A Normal ECG")
# plt.show()
#
# plt.grid()
# plt.plot(np.arange(140), anomalous_train_data[0])
# plt.title("An Anomalous ECG")
# plt.show()

# autoencoder = AnomalyDetector()
#
# autoencoder.compile(optimizer='adam', loss='mae')
#
# history = autoencoder.fit(normal_train_data, normal_train_data,
#           epochs=20,
#           batch_size=512,
#           validation_data=(test_data, test_data),
#           shuffle=True)

# plt.plot(history.history["loss"], label="Training Loss")
# plt.plot(history.history["val_loss"], label="Validation Loss")
# plt.legend()

# encoded_imgs = autoencoder.encoder(normal_test_data).numpy()
# decoded_imgs = autoencoder.decoder(encoded_imgs).numpy()
#
# plt.plot(normal_test_data[0],'b')
# plt.plot(decoded_imgs[0],'r')
# plt.fill_between(np.arange(140), decoded_imgs[0], normal_test_data[0], color='lightcoral' )
# plt.legend(labels=["Input", "Reconstruction", "Error"])
# plt.show()

# encoded_imgs = autoencoder.encoder(anomalous_test_data).numpy()
# decoded_imgs = autoencoder.decoder(encoded_imgs).numpy()
#
# plt.plot(anomalous_test_data[0], 'b')
# plt.plot(decoded_imgs[0], 'r')
# plt.fill_between(np.arange(140), decoded_imgs[0], anomalous_test_data[0], color='lightcoral' )
# plt.legend(labels=["Input", "Reconstruction", "Error"])
# plt.show()

# reconstructions = autoencoder.predict(normal_train_data)
# train_loss = tf.keras.losses.mae(reconstructions, normal_train_data)

# plt.hist(train_loss, bins=50)
# plt.xlabel("Train loss")
# plt.ylabel("No of examples")
# plt.show()

# threshold = np.mean(train_loss) + np.std(train_loss)
# print("Threshold: ", threshold)

# reconstructions = autoencoder.predict(anomalous_test_data)
# test_loss = tf.keras.losses.mae(reconstructions, anomalous_test_data)

# plt.hist(test_loss, bins=50)
# plt.xlabel("Test loss")
# plt.ylabel("No of examples")
# plt.show()

# def predict(model, data, threshold):
#     reconstructions = model(data)
#     loss = tf.keras.losses.mae(reconstructions, data)
#     return tf.math.less(loss, threshold)
#
# def print_stats(predictions, labels):
#     print("Accuracy = {}".format(accuracy_score(labels, preds)))
#     print("Precision = {}".format(precision_score(labels, preds)))
#     print("Recall = {}".format(recall_score(labels, preds)))

# preds = predict(autoencoder, x_train, threshold)
# print_stats(preds, test_labels)