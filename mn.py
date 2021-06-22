N = int(input())

S = ['' for i in range(N)]
X = [0 for i in range(N)]
for i in range(N):
    S[i], X[i] = input().split()

for i in range(N):
    X[i] = int(X[i])

for i in range (len(S)):
    j = i+1
    while (j < len(S)):
        if (S[i] == S[j]):
            X[i] += X[j]
            S.pop(j)
            X.pop(j)
        else:
            j+=1

print(len(S))
for i in range (len(S)):
    print(S[i], X[i], end='')
    if i != len(S)-1:
        print(end='\n')
