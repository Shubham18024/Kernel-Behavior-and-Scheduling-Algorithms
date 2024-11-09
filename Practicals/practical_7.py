import shutil

source_file = 'source.txt'
dest_file = 'destination.txt'

# Copy the source file to destination
shutil.copyfile(source_file, dest_file)

print("File copied successfully.")
