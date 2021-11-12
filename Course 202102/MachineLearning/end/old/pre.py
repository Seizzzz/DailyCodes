import os
import shutil

train_filenames = os.listdir('./dataset/train')
train_cat = filter(lambda x:x[:3] == 'cat', train_filenames)
train_dog = filter(lambda x:x[:3] == 'dog', train_filenames)

os.mkdir('./dataset/train1/cat')
os.mkdir('./dataset/train1/dog')

for filename in train_cat:
    shutil.copy('./dataset/train/'+filename, './dataset/train1/cat')
for filename in train_dog:
    shutil.copy('./dataset/train/'+filename, './dataset/train1/dog')
