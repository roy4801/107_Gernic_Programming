from openpyxl import Workbook
import argparse

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Process the output time data into xlsx')
	parser.add_argument('-o', '--output', help='Set the output path (Default: .)')
	# parser.add_argument('input', help='Set the input data path', type=str, nargs='3', metavar=)
	parser.add_argument('--dry', help='Dry run', action='store_true')

	args = parser.parse_args()
	
	flag = True

	print('===== test ======')
	print('args.dry = {}'.format(args.dry))
	print('args.o = {}'.format(args.output))

	parser.print_usage()