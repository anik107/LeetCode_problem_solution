s = input()
vowel = set("AEIOUaeiou")

li =[]
pos = []
for index,char in enumerate(s):
    if char in vowel:
        li.append(char)
        pos.append(index)

li.sort()
res = list(s)
for position,char in zip(pos,li):
    res[position]=char

print(''.join(res))
