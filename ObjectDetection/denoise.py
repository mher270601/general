import tensorflow as tf

from tensorflow.keras import layers
from tensorflow.keras.models import Model

# ------ Sigmoidy hatuk funkciayov sexmum a mutqayin arjeqnery 0-ic 1 mijakayqum
# ------ ReLun hatuk funkciaya` f(x) = max(0,x) veradarcnuma x ete ayn drakan a, myus depqum 0
# nkarneri axmuknery maqrelu hamar
## Denoise classy nuynpes yndlaynum e kerasi model dasy
## Denoise classi constructory sahmanum a erku modelner` voronq en encodery u decodery
## Denoise-i encodery modely mer depqum vercnum a tvyalner vorpes argument` 850, 500, 1, aysinqn 850 piqsel
# laynutyamb, 500 pixel erkarutyamb patker
## MER encodery tvyal pahin ogtagorcum a erku convolutional shert` hamapatasxanabar 512 ev 256 ztichnerov` voroncic
# yuraqanchyury uni 3x3 kernel size
## Decodery semxvac tvyalnery vercnum a encoderic, kirarum e erku transpozicion sherter` voronq unen
# hamapatasxanabar 256 ev 512 filtrner, 3x3 kernel size
## Aynuhetev decodery ogtagorcum a verjnakan conv2d layer 1 filtrov, ev 3x3 kernel size-ov
## Call funkcian vercnuma x mutqayin tensory, talis a im encoderin vorpeszi sexmi tvyalnery, apa poxancuma/
# decoderin vorpeszi verakaruci mer nkary skzbnakan chapserov, u verjinis ardyunqy veradarcnum a
class Denoise(Model):
    def __init__(self):
        super(Denoise, self).__init__()
        self.encoder = tf.keras.Sequential([
            layers.Conv2D(filters=32, kernel_size=(3, 3), input_shape=(500, 850, 3)),

            layers.Conv2D(16, (3, 3), activation='relu', padding='same', strides=2),
            layers.Conv2D(8, (3, 3), activation='relu', padding='same', strides=2)])

        self.decoder = tf.keras.Sequential([
            layers.Conv2DTranspose(8, kernel_size=3, strides=2, activation='relu', padding='same'),
            layers.Conv2DTranspose(16, kernel_size=3, strides=2, activation='relu', padding='same'),
            layers.Conv2D(1, kernel_size=(3, 3), activation='sigmoid', padding='same')])

    def call(self, x):
        encoded = self.encoder(x)
        decoded = self.decoder(encoded)
        return decoded