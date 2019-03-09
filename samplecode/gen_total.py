import string

s = ['Alternative', 'Iterator', 'Simple']
f = ['data_len', 'data_line']

CH = string.ascii_uppercase

def main():
    for i in s:
        i += '/'
        for j in f:
            try:
                with open('result/' + i + j + '.txt') as inp, open('result/' + i + j + '_total.txt', 'w') as outp:
                    data = [x.split() for x in inp.readlines()]
                    for ii in range(len(data)):
                        print(data[ii])
                        outp.write(CH[ii] + ' ')
                        summ = float(data[ii][2]) + float(data[ii][3]) + float(data[ii][4])
                        if i == 'Alternative/':
                            summ += float(data[ii][5])
                        outp.write('{:.7f}\n'.format(summ))
            except FileNotFoundError as e:
                print('Warning: {}'.format(e))
                pass
if __name__ == '__main__':
    main()