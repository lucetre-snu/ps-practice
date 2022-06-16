import numpy as np
import pandas as pd

# data = pd.DataFrame({'Country': ['Russia','Colombia','Chile','Equador','Nigeria'],
#                     'Rank':[121,40,100,130,11]})
#
# print(data)
# print(data.describe())
# print(data.info())
#
# data = pd.DataFrame({'group':['a', 'a', 'a', 'b','b', 'b', 'c', 'c','c'],'ounces':[4, 3, 12, 6, 7.5, 8, 3, 5, 6]})
# print(data)
# data1 = data.sort_values(by=['ounces'], ascending=True, inplace=False)
# print(data1)
# data2 = data.sort_values(by=['group', 'ounces'], ascending=[True, False], inplace=False)
# print(data2)
#
# data = pd.DataFrame({'k1':['one']*3 + ['two']*4, 'k2':[3,2,1,3,3,4,4]})
# print(data)
# print(data.sort_values(by='k2'))
# print(data.drop_duplicates())
# print(data.drop_duplicates(subset='k1'))
#
# data = pd.DataFrame({'food': ['bacon', 'pulled pork', 'bacon', 'Pastrami','corned beef', 'Bacon', 'pastrami', 'honey ham','nova lox'],
#                  'ounces': [4, 3, 12, 6, 7.5, 8, 3, 5, 6]})
# print(data)
#
# meat_to_animal = {
# 'bacon': 'pig',
# 'pulled pork': 'pig',
# 'pastrami': 'cow',
# 'corned beef': 'cow',
# 'honey ham': 'pig',
# 'nova lox': 'salmon'
# }
# data['animal'] = data['food'].map(str.lower).map(meat_to_animal)
# print(data)
#
# data['food'] = data['food'].apply(str.lower)
# data['animal2'] = data.apply(lambda x: meat_to_animal[x['food']], axis='columns')
# print(data)
#
# print(data.assign(new_variable=data['ounces']*10))
# data.drop('animal2', axis='columns', inplace=True)
# print(data)

# data = pd.Series([1., -999., 2., -999., -1000., 3.])
# data.replace([-999,-1000],np.nan,inplace=True)
# print(data)

data = pd.DataFrame(np.arange(12).reshape((3, 4)),index=['Ohio', 'Colorado', 'New York'],columns=['one', 'two', 'three', 'four'])
print(data)
data.rename(index = {'Ohio':'SanF'}, columns={'one':'one_p','two':'two_p'},inplace=True)
print(data)


