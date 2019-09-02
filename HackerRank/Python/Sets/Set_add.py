numCountries = int(input())
countrySet = set([])
for i in range(0, numCountries):
    country = str(input())
    countrySet.add(country)
print(len(countrySet))
