import tensorflow as tf

from tensorflow.keras import layers
from tensorflow.keras.models import Model

# anomalyaner (ankap keter) gtnelu hamar, // anomal arjeqnery shtkelu hamar
## ANOMALYDETECTOR dasy jarangum e kerasi model dasic
## Dasi constructory sahmanum e nuynpes erku model` encoder u decoder
## Encodery baxkacac e ereq xit (dense) shertic, isk decodery baxkacac e ereq xit(dense) shertic ev mek xit (dense)
# sigmoid aktivacmamb shertic
## Call funkcian vercnuma x mutqayin tensory, talis a im encoderin vorpeszi stana kodavorvac semvac tvylanery,
# apa poxancuma decoderin vorpeszi verakaruci, u verjinis ardyunqy veradarcnum a
class AnomalyDetector(Model):
    def __init__(self):
        super(AnomalyDetector, self).__init__()
        self.encoder = tf.keras.Sequential([
            layers.Dense(32, activation="relu"),
            layers.Dense(16, activation="relu"),
            layers.Dense(8, activation="relu")])

        self.decoder = tf.keras.Sequential([
            layers.Dense(16, activation="relu"),
            layers.Dense(32, activation="relu"),
            layers.Dense(140, activation="sigmoid")])

    def call(self, x):
        encoded = self.encoder(x)
        decoded = self.decoder(encoded)
        return decoded