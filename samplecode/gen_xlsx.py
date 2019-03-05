from openpyxl import Workbook
import argparse, string

g_input_list = None
g_output_path = None
g_dry = False
def getInputPath(l):
	global g_input_list
	g_input_list = l

def getOutputPath(path):
	global g_output_path
	g_output_path = path

LABEL = {
	'Alternative': ['result/time(s)', 'input', 'Character Table Creation', 'sorting time', 'output', 'totoal', 'sort/total'],
	'Iterator': [],
	'Simple': []
}

CH = string.ascii_uppercase

def POS(i, j):
	return CH[j] + str(i+1)

def createSheetLabel(st, name):
	name = name.split('_')[0]
	for i in range(len(LABEL[name])):
		st[POS(0, i+1)] = LABEL[name][i]

g_file_name = {'line': 'data_line.txt', 'len': 'data_len.txt'}
g_type = ['line', 'len']
def process():
	'''
	process the data (line, len) and gen a .xlsx file
	'''
	wb = Workbook()
	wb.remove(wb.active)
	for i in g_input_list:
		for j in g_type:
			now = '{}_{}'.format(i, j)
			print('Creating sheet {}'.format(now))
			# if dry run, then don't do anything
			if g_dry:
				continue
			
			sheet = wb.create_sheet(now)

			try:
				print('>> {}'.format(i))
				with open('result/' + i + '/' + g_file_name[j], 'r') as f:
					createSheetLabel(sheet, now)

					data = f.readlines()

					for ii in range(len(data)):
						sheet[POS(ii+1, 0)] = data[ii][0]

					print('=== test ===')
					for row in sheet:
						for cel in row:
							print(cel.value)
			except FileNotFoundError as e:
				print('Warning: {}'.format(e))
				pass

	if not g_dry:
		print(wb.sheetnames)
		wb.save('test.xlsx')


if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Process the output time data into xlsx')
	parser.add_argument('-o', '--output', metavar='path', help='Set the output path (Default: .)')
	parser.add_argument('-i', '--input', metavar='path', help='Set the input data path (Multiple)', nargs='+')
	parser.add_argument('--dry', help='Dry run', action='store_true')
	parser.add_argument('-V', '--version', action='version', version='%(prog)s 0.0.1')

	args = parser.parse_args()
	
	flag = True

	if args.input:
		getInputPath(args.input)
	if args.output:
		getOutputPath(args.output)

	g_dry = args.dry
	if args.input and args.output:
		process()
		flag = False
	print('===== test ======')
	print('args.dry = {}'.format(args.dry))
	print('args.o = {}'.format(args.output))
	print('arg.i = {}'.format(args.input))
	print()
	if flag:
		parser.print_usage()