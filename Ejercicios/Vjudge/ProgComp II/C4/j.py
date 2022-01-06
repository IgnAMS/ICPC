cont=0
while(1):
    s=input()
    S=s.strip(' ')
    l=int(S[0])
    p=int(S[1])
    v=int(S[2])
    if v==0 and p==0 and l==0:
        break
    x= v//p
    print("Case ",cont,": ",v-x*p)
