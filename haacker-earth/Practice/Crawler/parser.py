import requests
from bs4 import BeautifulSoup
import json
import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

req = requests.get('https://beomi.github.io/beomi.github.io_old/')

html = req.text
header = req.headers
status = req.status_code
is_ok = req.ok

# print(req)
# print(html)
# print(header)
# print(is_ok)

soup = BeautifulSoup(html, 'html.parser')

my_titles = soup.select(
    'h3 > a'
    )
data = {}

# for title in my_titles:
#     print(title.text)
#     print(title.get('href'))

for title in my_titles:
    print(title.text)
    data[title.text] = title.get('href')

with open(os.path.join(BASE_DIR, 'result.json'), 'w+') as json_file:
    json.dump(data, json_file)