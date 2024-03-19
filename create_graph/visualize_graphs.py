# This file is used to visualize the data generated using viz() function

from graphviz import Source, ExecutableNotFound

dot_file_path = 'path/to/your/.dot/file.dot'

try:
    # Create a Source object
    src = Source.from_file(dot_file_path)

    # Display the graph
    src.view()
except ExecutableNotFound:
    print("Graphviz executable not found. Please install Graphviz (https://graphviz.gitlab.io/download/) and ensure it's in your PATH.")
