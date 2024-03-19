
#!/usr/bin/env python3

import xml.etree.ElementTree as Xet
import pandas as pd
import time 
from multiprocessing import Process
timeout = time.time() + 60*.5

def csvtime(filename) :
    print('starting function csvtime')
    cols = ["description"]
    rows = []
    xmlparse = Xet.parse(filename)
    root = xmlparse.getroot()

    for description in root.iter("description"):

        print(description.text)
        description = description.text
        rows.append({"description": description})
    df = pd.DataFrame(rows, columns=cols)
    df.to_csv('output.csv')
# Parsing the XML file

#print("here 1")
#while timeout > time.time():
#print("here 2")
if __name__ == '__main__':
    p1 = Process(target=csvtime('masters2.xml'), name='Process_csvtime')
    p1.start()
    p1.join(timeout=30)
    p1.terminate()
    

    
    #title= i.find("title").text

  
        
  
    

    print("Done!")
# Writing dataframe to csv
    