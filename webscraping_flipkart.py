from bs4 import BeautifulSoup as soup
from urllib.request import urlopen as uReq


myurl="https://www.flipkart.com/search?q=samsung+mobiles&amp;sid=tyy%2C4io&amp;as=on&amp;as-show=on&amp;otracker=AS_QueryStore_HistoryAutoSuggest_0_2&amp;otracker1=AS_QueryStore_HistoryAutoSuggest_0_2&amp;as-pos=0&amp;as-type=HISTORY&amp;as-searchtext=sa"
uClient=uReq(myurl)
page_html=uClient.read();
uClient.close();
page_soup=soup(page_html,"html.parser")
containers=page_soup.findAll("div",{"class":"_300U0u"})
#print("inside ",containers)
#print("containers",soup.prettify(containers[0]))
container = containers[0]
print(container.div.img["alt"])
price = container.findAll("div", {"class": "col col-5-12 _2o7WAb"})
print(price[0].text)
ratings = container.findAll("div", {"class": "niH0FQ"})
print(ratings[0].text)
filename = "products.csv"
f = open(filename, "w")
headers = "Product_Name, Pricing, Ratings \n"
f.write(headers)
for container in containers:
    product_name = container.div.img["alt"]
    price_container = container.findAll("div", {"class": "col col-5-12 _2o7WAb"})
    price = price_container[0].text.strip()

    rating_container = container.findAll("div", {"class": "niH0FQ"})
    rating = rating_container[0].text
    print("Product_Name:"+ product_name)
    print("Price: " + price)
    print("Ratings:" + rating)
