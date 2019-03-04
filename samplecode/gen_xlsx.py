from openpyxl import Workbook
import argparse

g_input_list = None
g_output_path = None
g_dry = False
def getInputPath(l):
	global g_input_list
	g_input_list = l

def getOutputPath(path):
	global g_output_path
	g_output_path = path

g_file_name = {'line': 'gnu_line.txt', 'len': 'gnu_len.txt'}
g_type = ['line', 'len']
def process():
	for i in g_input_list:
		for j in g_type:
			print('{} {}'.format(i, j))

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
	print('===== test ======')
	print('args.dry = {}'.format(args.dry))
	print('args.o = {}'.format(args.output))
	print('arg.i = {}'.format(args.input))
	print()

	parser.print_usage()