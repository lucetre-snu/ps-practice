import requests
from bs4 import BeautifulSoup
import json
import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

def topic_crawl():
    req = requests.get('https://languagedrops.com/word/en/english/icelandic')
    soup = BeautifulSoup(req.text, 'html.parser')

    topics = []
    for topic in soup.select('h2.linkable-word-box-text'):
        topic = topic.text.lower().replace(" ", "_").replace(".", "_")
        topics.append(topic)

    return topics


def word_crawl(topic_name):
    req = requests.get('https://languagedrops.com/word/en/english/icelandic/topics/%s' % topic_name)
    req1 = requests.get('https://languagedrops.com/word/en/english/korean/topics/%s' % topic_name)
    soup = BeautifulSoup(req.text, 'html.parser')
    soup1 = BeautifulSoup(req1.text, 'html.parser')

    voca_eng = soup.select('div.topic-row-first-word')
    voca_is = soup.select('div.topic-row-second-word')
    voca_kor = soup1.select('div.topic-row-second-word')
    voca = {'is': [], 'eng': [], 'kor': []}

    if len(voca_eng) != len(voca_kor):
        print('>> different lens')
        return


    wf.write(topic_name + '\t\t\t' + str(len(voca_eng)) + '\n')
    for i in range(len(voca_eng)):
        word_eng = voca_eng[i].text.encode('latin-1')
        word_is = voca_is[i].text.encode('latin-1')
        word_kor = voca_kor[i].text.encode('latin-1')
        wf.write(word_is + '\t' + word_eng + '\t' + word_kor + '\n')
        voca['eng'].append(word_eng)
        voca['is'].append(word_is)
        voca['kor'].append(word_kor)

    return voca


# def create_dict():
#     data = {}
#     flag = False
#     for topic in topic_crawl():
#         if topic == 'drinks':
#             flag = True
#         if flag:
#             print(topic)
#             data[topic] = word_crawl(topic)

#     with open(os.path.join(BASE_DIR, 'icelandic.json'), 'w+') as json_file:
#         json.dump(data, json_file)


if __name__ == '__main__':
    # of = open('topics.txt', mode='w')
    # for topic in topic_crawl():
    #     of.write(topic + '\t\n');

    wf = open('icelandic.txt', mode='w')
    flag = False
    for topic in topic_crawl():
        if topic == 'drinks':
            flag = True
        if flag:
            print(topic)
            word_crawl(topic)
    wf.close()

    # create_dict()

