
s = ['Alternative', 'Iterator', 'Simple']
f = ['data_len', 'data_line']

def main():
	for i in s:
		i += '/'
		for j in f:
			try:
				with open('result/' + i + j + '.txt', 'r') as inp, open('result/' + i + j + '_total.txt', 'w') as outp:
					data = [x.split() for x in inp.readlines()]
					for ii in range(len(data)):
						outp.write(data[ii][0] + ' ')
						outp.write('{:.7f}\n'.format(float(data[ii][1]) + float(data[ii][2]) + float(data[ii][3])))
			except FileNotFoundError as e:
				print('Warning: {}'.format(e))
				pass
if __name__ == '__main__':
	main()