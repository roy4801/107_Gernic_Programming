import string, random, sys

def id_generator(size=20, chars=string.ascii_uppercase + string.digits):
   return ''.join(random.choice(chars) for _ in range(size))

def main():
	if len(sys.argv) != 3:
		print('Usage: {} <len> <lines>'.format(sys.argv[0]))
		return

	name = "test.txt"
	file = open(name, 'w', encoding='UTF-8')
	length = int(sys.argv[1])
	line   = int(sys.argv[2])

	for i in range(line):
		file.write(id_generator(length) + '\n')

	file.close()

if __name__ == "__main__":
	main()