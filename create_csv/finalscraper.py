"""
This file reads data from the CSV file, processes each line to extract song and 
artist information, and writes the extracted information to a new CSV file
"""

import csv 
import re

# Specify the output file path
out_path ='cleaned.csv'

# Open the input and output files
with open('output.csv', 'r') as csv_file, open(out_path, 'w',newline='') as dictfile:
    csv_reader = csv.reader(csv_file)
    csv_writer = csv.writer(dictfile, quoting = csv.QUOTE_NONE, escapechar='\\')
    
    # Define the fields for the output CSV file
    fields = ['Song', 'Artist 1', 'Artist 2', 'Artist 3','Artist 4', 'Artist 5' ] 
    
    # Write the field names as the first row in the output CSV file
    csv_writer.writerow(fields)

    for line in csv_reader:

        if (len(line)>1):
            # Use regex to search for patterns that indicate multiple artists
            m = re.search(r'\n\n(.+ · .+|.+ · .+ · .+|.+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+ · .+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+ · .+ · .+ · .+ · .+ · .+|.+ · .+ · .+ · .+ · .+ · .+ · .+ · .+ · .+ · .+ · .+)\n\n', line[1])

            if m != None:
                # Split the matched string by ' · ' to extract artist names
                csv_line = m.group().split(' · ')
                
                # Write the extracted artist names to the output CSV file
                if (len(csv_line) == 2):
                    row = [csv_line[0], csv_line[1], '-', '-', '-', '-']
                    csv_writer.writerow(row)
                if (len(csv_line) == 3):
                    row = [csv_line[0], csv_line[1], csv_line[2], '-', '-', '-']
                    csv_writer.writerow(row)
                if (len(csv_line) == 4):
                    row = [csv_line[0], csv_line[1], csv_line[2], csv_line[3], '-', '-']
                    csv_writer.writerow(row)
                if (len(csv_line) == 5):
                    row = [csv_line[0], csv_line[1], csv_line[2], csv_line[3], csv_line[4], '-']
                    csv_writer.writerow(row)
                if (len(csv_line) == 6):
                    row = [csv_line[0], csv_line[1], csv_line[2], csv_line[3], csv_line[4], csv_line[5]]
                    csv_writer.writerow(row)
