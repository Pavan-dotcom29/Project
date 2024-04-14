import csv
from urllib.request import urlopen
from bs4 import BeautifulSoup

html=urlopen("https://en.wikipedia.org/wiki/Comparison_of_programming_languages")
#print(html);
soup=BeautifulSoup(html,"html.parser")
#print(soup);
table=soup.findAll("table",{"class":"wikitable"})[0]
#print(table);
rows=table.findAll("tr")
#print(rows);


with open("langu.csv", "wt+",newline="") as f:
   writer= csv.writer(f);
   for i in rows:
       row=[]
       for cell in i.findAll(["td","th"]):
           row.append(cell.get_text())
       writer.writerow(row)


import pandas as pd
a=pd.read_csv("langu.csv")
a.head()




