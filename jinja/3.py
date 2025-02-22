from jinja2 import Template as T1
from string import Template as T2
info = {'cityl': 'Mumbai', 'city2' : 'Delhi', 'city2' : 'Bangalore', 'city4' : 'city1', 'country1' : 'India', 'country2' : 'country1'}

t1 = T1("${{city3}}and{{city4}} are the national and financial capitals of ${{country2}} respectively.")

out1 = t1.render(info)
print(out1)

t2 = T2("${city3}and${city4} are the national and financial capitals of ${country2} respectively.")

out2 = T2(out1)
print(out2.substitute(info))