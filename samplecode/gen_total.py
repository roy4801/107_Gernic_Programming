import string
import re
from gen_xlsx import getMapAlpha

MAP = {}

s = ['Alternative', 'Iterator', 'Simple']
f = ['data_len', 'data_line']

CH = string.ascii_uppercase

def main():
    getMapAlpha(MAP)
    for i in s:
        i += '/'
        for j in f:
            try:
                with open('result/' + i + j + '.txt') as inp, open('result/' + i + j + '_total.txt', 'w') as outp:
                    data = [x.split() for x in inp.readlines()]
                    for ii in range(len(data)):
                        print(data[ii])
                        if j == 'data_len':
                            outp.write('"({0[0]} {0[1]})"'.format(re.findall("\d+-*\d*",MAP['len'][ii])))
                        if j == 'data_line':
                            outp.write('"({0[0]} {0[1]})"'.format(re.findall("\d+-*\d*",MAP['line'][ii])))
                        outp.write(' ')
                        # sum
                        summ = float(data[ii][2]) + float(data[ii][3]) + float(data[ii][4])
                        if i == 'Alternative/':
                            summ += float(data[ii][5])
                        outp.write('{:.7f}\n'.format(summ))
            except FileNotFoundError as e:
                print('Warning: {}'.format(e))
                pass
if __name__ == '__main__':
    main()
