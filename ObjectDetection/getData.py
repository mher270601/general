import os
import cv2
import numpy as np
from sklearn.model_selection import train_test_split

def load_images(input_folder, output_folder, test_size=0.2, random_state=42):
    """
    Load images from input and output folders and split into x_train and x_test.

    Args:
        input_folder (str): Path to the input folder.
        output_folder (str): Path to the output folder.
        test_size (float, optional): Test size for train-test split, default is 0.2.
        random_state (int, optional): Random seed for train-test split, default is 42.

    Returns:
        tuple: Tuple containing x_train and x_test arrays.
    """
    # Load input images
    input_images = []
    for file in os.listdir(input_folder):
        if file.endswith(".jpg"):
            img = cv2.imread(os.path.join(input_folder, file))
            print("Input", file, img.shape)
            # img = cv2.resize(img, (850, 500))
            input_images.append(img)
    # x_train, x_test = train_test_split(input_images, test_size=test_size, random_state=random_state)

    # Load output images
    output_images = []
    for file in os.listdir(output_folder):
        if file.endswith(".jpg"):
            img = cv2.imread(os.path.join(output_folder, file))
            print("Output", file, img.shape)
            # img = cv2.resize(img, (850, 500))
            output_images.append(img)

    return np.array(input_images), np.array(output_images)
# import cv2
# import os
# import numpy as np
#
# def load_train_data(input_folder, output_folder):
#     x_train = []
#     y_train = []
#
#     # Get list of input and output image file names
#     input_files = os.listdir(input_folder)
#     output_files = os.listdir(output_folder)
#
#     # Sort the file names to ensure consistent ordering
#     input_files.sort()
#     output_files.sort()
#
#     for input_file, output_file in zip(input_files, output_files):
#         # Load input image
#         input_path = os.path.join(input_folder, input_file)
#         input_image = cv2.imread(input_path)
#         # Load output image
#         output_path = os.path.join(output_folder, output_file)
#         output_image = cv2.imread(output_path)
#
#         # Append input and output images to training data
#         x_train.append(input_image)
#         y_train.append(output_image)
#
#     # Convert lists to numpy arrays
#     x_train = np.array(x_train)
#     y_train = np.array(y_train)
#
#     return (x_train, y_train)