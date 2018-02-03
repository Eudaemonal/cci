from collections import defaultdict


def ransom_note(magazine, ransom):
	hist = defaultdict(int)
	for word in magazine:
		hist[word] += 1
	for word in ransom:
		if(hist[word]==0):
			return False
		hist[word]-=1
	return True

if __name__ == "__main__":
	f = open("in.txt");
	data=f.readlines()
	m, n = map(int, data[0].strip().split(' '))
	magazine = data[1].strip().split(' ')
	ransom = data[2].strip().split(' ')
	answer = ransom_note(magazine, ransom)
	if(answer):
 	   print("Yes")
	else:
 	   print("No")
