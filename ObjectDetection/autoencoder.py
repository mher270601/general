import tensorflow as tf

from tensorflow.keras import layers
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Input, Flatten, Dense, Conv2D, MaxPooling2D, Reshape, UpSampling2D

# nerkayacnuma chartarapetutyan neyronayin canc
##AUTOENCODERY neyronayin canci mi tesak a vory yndlaynum e neyronayin canci model dasy,
##AUTOENCODER dasi constructory vercnum e mek argument ` latent_dim, vory sahmanum e taqnvac taracutyan chapsery
# vorum semxvac en mutqayin tvyalnery
##ENCODERI ev Decoderi modelnery sahmnavum en konstruktorum
##ENCODERY vercnum e mutqayin tvyalnery` hartecnum dranq 1d tensori mej, aynuhetev kirarum e amboxjutyamb miacvac
# shert Relu aktivacman funkciayov, vory nvazecnum e tvyalneri chapsery minchev latent_dim
##APAKODAVORICHI modely vercnum e sexmvac tvyalnery encoderic ev kirarum e amboxjutyamb miacvac shert sigmoid
# aktivacman funkciayov` verakarecelu skzbnakan mutqayin dzevy (850, 500)
## CALL funkcian vercnum e stacvoc x mutqayin tensory, ayn poxancum a encoderin vor sexmi tvyalnery latent_dim-i
# chapov, u sexmvac tvyalnery poxancuma decoderin vory skzbnakan dzevy verakaruci
## VERAKARUCVAC elqy veradardznum a call andam funkciayov
class Autoencoder(Model):
    def __init__(self, latent_dim):
        super(Autoencoder, self).__init__()
        self.latent_dim = latent_dim
        self.encoder = tf.keras.Sequential([
            # Input layer with shape (500, 850, 3)
            # Input(None, 1275000),
            # Conv2D layer with 32 filters, 3x3 kernel, and 'relu' activation
            # Conv2D(32, (3, 3), activation='relu', padding='same'),
            # MaxPooling2D layer with 2x2 pool size
            layers.Reshape((500, 850, 3)),
            # layers.MaxPooling2D(pool_size=(2, 2), padding='same'),
            # Conv2D layer with 64 filters, 3x3 kernel, and 'relu' activation
            # layers.Conv2D(128, (3, 3), activation='relu', padding='same'),
            # # MaxPooling2D layer with 2x2 pool size
            # layers.MaxPooling2D(pool_size=(2, 2), padding='same'),
            # layers.Conv2D(64, (3, 3), activation='relu', padding='same'),
            # # MaxPooling2D layer with 2x2 pool size
            # layers.MaxPooling2D(pool_size=(2, 2), padding='same'),
            layers.Flatten(),
            #layers.Dense(256, activation='relu'),
            layers.Dense(128, activation='relu'),
            layers.Dense(64, activation='relu'),
            layers.Dense(32, activation='relu'),
            #layers.Dense(128, activation='relu'),
            # layers.Dense(256, activation='relu'),
            # layers.Dense(128, activation='relu'),
            # layers.Dense(256, activation='relu'),
            layers.Dense(latent_dim, activation='relu'),
            # layers.Flatten(),
            # layers.Dense(latent_dim, activation='relu'),
        ])
        self.decoder = tf.keras.Sequential([
            # layers.UpSampling2D((2, 2)),
            # layers.Conv2DTranspose(64, (3, 3), activation='relu', padding='same'),
            # layers.UpSampling2D((2, 2)),
            # layers.Conv2DTranspose(128, (3, 3), activation='relu', padding='same'),
            # layers.Conv2DTranspose(64, (3, 3), activation='relu', padding='same'),
            # layers.Conv2DTranspose(128, (3, 3), activation='relu', padding='same'),
            layers.Dense(32, activation='relu'),
            layers.Dense(64, activation='relu'),
            layers.Dense(128, activation='relu'),
            # layers.Dense(256, activation='relu'),
            # layers.Dense(256, activation='relu'),
            # layers.Dense(512, activation='relu'),
            layers.Dense(1275000, activation='sigmoid'),
            layers.Reshape((500, 850, 3))
            # layers.Dense(1275000, activation='sigmoid'),
            # layers.Reshape((500, 850, 3))
        ])

    def call(self, x):
        encoded = self.encoder(x)
        decoded = self.decoder(encoded)
        return decoded

#from tensorflow.keras.models import Model
#from tensorflow.keras.layers import Input, Flatten, Dense, Conv2D, MaxPooling2D, Reshape, UpSampling2D

# class Autoencoder(Model):
#     def __init__(self, latent_dim):
#         super(Autoencoder, self).__init__()
#         self.latent_dim = latent_dim
#         self.encoder = tf.keras.Sequential([
#             # Input layer with shape (500, 850, 3)
#             Input(shape=(500, 850, 3)),
#             # Conv2D layer with 32 filters, 3x3 kernel, and 'relu' activation
#             Conv2D(32, (3, 3), activation='relu', padding='same'),
#             # MaxPooling2D layer with 2x2 pool size
#             MaxPooling2D(pool_size=(2, 2), padding='same'),
#             # Conv2D layer with 64 filters, 3x3 kernel, and 'relu' activation
#             Conv2D(64, (3, 3), activation='relu', padding='same'),
#             # MaxPooling2D layer with 2x2 pool size
#             MaxPooling2D(pool_size=(2, 2), padding='same'),
#             # Flatten layer
#             Flatten(),
#             # Dense layer with 128 units and 'relu' activation
#             Dense(128, activation='relu'),
#             # Dense layer with 64 units and 'relu' activation
#             Dense(64, activation='relu'),
#             # Dense layer with latent_dim units and 'relu' activation
#             Dense(latent_dim, activation='relu')
#         ])
#         self.decoder = tf.keras.Sequential([
#             # Dense layer with 64 units and 'relu' activation
#             Dense(64, activation='relu'),
#             # Dense layer with 128 units and 'relu' activation
#             Dense(128, activation='relu'),
#             # Dense layer with 256 units and 'relu' activation
#             Dense(256, activation='relu'),
#             # Reshape layer to (500, 850, 3) shape
#             Reshape((500, 850, 3)),
#             # Conv2D layer with 64 filters, 3x3 kernel, and 'relu' activation
#             Conv2D(64, (3, 3), activation='relu', padding='same'),
#             # UpSampling2D layer with 2x2 upsampling
#             UpSampling2D((2, 2)),
#             # Conv2D layer with 32 filters, 3x3 kernel, and 'relu' activation
#             Conv2D(32, (3, 3), activation='relu', padding='same'),
#             # UpSampling2D layer with 2x2 upsampling
#             UpSampling2D((2, 2)),
#             # Conv2D layer with 3 filters, 3x3 kernel, and 'sigmoid' activation
#             Conv2D(3, (3, 3), activation='sigmoid', padding='same')
#         ])
#
#     def call(self, x):
#         encoded = self.encoder(x)
#         decoded = self.decoder(encoded)
#         return decoded
