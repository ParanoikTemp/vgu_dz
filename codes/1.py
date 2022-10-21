with open('text.txt', encoding='utf-8') as f:
    planets = [i.replace(',', '.').split() for i in f.readlines()]
with open('text.txt', 'w', encoding='utf-8') as f:
    for i in planets:
        g = round((6.67 * 10 ** -11 * float(i[1]) * 10 ** 24 / (float(i[2]) * 1000) ** 2), 3)
        i.append(str(g))
        v = round((6.67 * 10 ** -11 * float(i[1]) * 10 ** 24 / float(i[2]) * 1000) ** 0.5)
        i.append(str(v))
        f.write(" ".join(i) + '\n')
