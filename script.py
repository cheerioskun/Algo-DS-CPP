f = open(input(), 'r').read()
s = ''
for i in f:
    if i != '\n':
        s += i
    else:
        s += '\\n'

open('res.txt', 'w').write(s)