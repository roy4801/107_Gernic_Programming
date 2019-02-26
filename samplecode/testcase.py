import string
import random

def id_generator(size=10, chars=string.ascii_uppercase + string.digits):
   return ''.join(random.choice(chars) for _ in range(size))

def main():

	name = "test.txt"
	file = open(name, 'w', encoding='UTF-8')

	for i in range(1,100000):
		file.write(id_generator() + '\n')

	file.close()

if __name__ == "__main__":
	main()