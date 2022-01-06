def solution(pegs):
    sw=1
    suma=0
    for i in range(len(pegs)-1):
        suma+=sw*(pegs[i+1]-pegs[i])
        sw*=-1
    
    if suma<=0:
        return [-1,-1]
    
    if len(pegs)%2==0:
        last=2*suma/3
    else:
        last=2*suma
    for i in range(len(pegs)-1):
        new=pegs[i+1]-pegs[i]-last
        if new<1:
            return [-1,-1]
        last=new
    
    if len(pegs)%2==0:
        if suma<3:
            return [-1,-1]
        if suma%3==0:
            return [2*suma/3,1]
        return [2*suma,3]

    if suma<1:
        return [-1,-1]
    return [2*suma,1]